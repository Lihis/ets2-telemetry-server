#include "HttpServer.h"
#include "TelemeteryHelper.h"
#include "ets2-telemetry-common.hpp"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <fstream>
#include <dirent.h>
#include <vector>

HttpServer::HttpServer(ets2TelemetryMap_t *telemetry) :
m_event(nullptr),
m_server(nullptr),
m_running(false)
{
    m_telemetry = telemetry;
}

HttpServer::~HttpServer() {
    stop();
}

bool HttpServer::start(const std::string &addr, uint16_t port) {
    LockGuard lock(m_lock);

    if (m_running) {
        printf("Running already\n");
        return true;
    }

    bool ret = init_server(addr, port);
    if (ret) {
        m_thread = std::thread(&HttpServer::server_loop, this);
    }

    return ret;
}

bool HttpServer::stop() {
    LockGuard lock(m_lock);

    m_running = false;
    if (m_server) {
        m_thread.join();
        evhttp_free(m_server);
        m_server = nullptr;
        event_base_free(m_event);
        m_event = nullptr;
    }

    return true;
}

bool HttpServer::isRunning() {
    LockGuard lock(m_lock);

    return m_running;
}

void HttpServer::register_cb(struct evhttp_request *request, void *arg) {
    static_cast<HttpServer *>(arg)->api_callback(request, nullptr);
}

bool HttpServer::init_server(const std::string &addr, uint16_t port) {
    m_event = event_base_new();
    if (!m_event) {
        return false;
    }

    m_server = evhttp_new(m_event);
    if (!m_server) {
        event_base_free(m_event);
        m_event = nullptr;
        return false;
    }

    if (evhttp_bind_socket(m_server, addr.c_str(), port) != 0) {
        evhttp_free(m_server);
        m_server = nullptr;
        event_base_free(m_event);
        m_event = nullptr;
        return false;
    }
    evhttp_set_gencb(m_server, register_cb, this);

    return true;
}

void HttpServer::server_loop() {
    struct timeval tm = { 0, 200000 };

    m_running = true;

    while (m_running) {
        event_base_loop(m_event, EVLOOP_ONCE | EVLOOP_NONBLOCK);
        event_base_loopexit(m_event, &tm);
    }

    m_running = false;
}

void HttpServer::api_callback(struct evhttp_request *request, void */*arg*/) {
    auto buffer = evhttp_request_get_output_buffer(request);
    std::string uri = evhttp_uri_get_path(evhttp_uri_parse(evhttp_request_get_uri(request)));

    printf("Received request (URI: %s)\n", uri.c_str());
    if (evhttp_request_get_command(request) != EVHTTP_REQ_GET) {
        printf("Only GET request is supported.\n");
        evhttp_send_error(request, HTTP_BADREQUEST, nullptr);
        return;
    }

    if (uri.find("..") != std::string::npos) {
        evhttp_send_error(request, HTTP_BADREQUEST, nullptr);
        return;
    } else if (uri == "/api/ets2/telemetry") {
        evhttp_add_header(request->output_headers, "Content-Type", "application/json");
        evbuffer_add_printf(buffer, "%s", TelemetryHelper::toJson(true, m_telemetry).c_str());
    } else if (uri == "/config.json") {
        std::stringstream config;
        std::vector<std::string> skins;
#ifdef _WIN32
        WIN32_FIND_DATA ffd;
        HANDLE hFind = FindFirstFile("html\\skins", &ffd);
        if (hFind != INVALID_HANDLE_VALUE) {
            do {
                if ((ffd.dwFileAttributes | FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY &&
                    ffd.cFileName[0] != '.')
                {
                    skins.emplace_back(ffd.cFileName);
                }
            } while (FindNextFile(hFind, &ffd));
        }
#else
        struct dirent *dp;
        DIR *dir = opendir("html/skins");

        while ((dp = readdir(dir)) != nullptr) {
            if (dp->d_type == DT_DIR && dp->d_name[0] != '.') {
                skins.emplace_back("./html/skins/" + std::string(dp->d_name) + "/config.json");
            }
        }
#endif

        for (uint32_t i = 0; i < skins.size(); ++i) {
            std::ifstream file(skins[i]);
            if (file.is_open()) {
                std::stringstream conf;
                std::string line;
                bool append = false;

                while (std::getline(file, line)) {
                    if (line.find(R"("config": {)") != std::string::npos) {
                        append = true;
                        continue;
                    }

                    if (line == "    }") {
                        break;
                    }

                    if (append) {
                        conf << line << "\n";
                    }
                }

                if (!conf.str().empty()) {
                    config << "  {\n" << conf.str() << "  }";
                    if ((i + 1) < skins.size()) {
                        config << ",\n";
                    } else {
                        config << "\n";
                    }
                }
            }
        }

        evhttp_add_header(request->output_headers, "Content-Type", "application/json");
        evbuffer_add_printf(buffer, "{ \"skins\": [\n%s]\n}", config.str().c_str());
    } else {
        if (uri == "/") {
            uri = "/index.html";
        }
        uri = "./html" + uri;

        int fd;
        struct stat sb = {};

#ifdef _WIN32
        fd = open(uri.c_str(), O_RDONLY);
#else
        fd = open(uri.c_str(), O_RDONLY | O_CLOEXEC);
#endif
        if (fd == -1) {
            fprintf(stderr, "Failed to open file '%s'.\n", uri.c_str());
            evhttp_send_error(request, HTTP_NOTFOUND, nullptr);
            return;
        }

        if (fstat(fd, &sb) == -1) {
            close(fd);
            fprintf(stderr, "Failed to stat the file.\n");
            evhttp_send_error(request, HTTP_INTERNAL, nullptr);
            return;
        }

        std::string content_type = "text/plain";
        if (uri.find(".html") != std::string::npos) {
            content_type = "text/html";
        } else if (uri.find(".js") != std::string::npos) {
            content_type = "application/javascript";
        } else if (uri.find(".css") != std::string::npos) {
            content_type = "text/css";
        } else if (uri.find(".png") != std::string::npos) {
            content_type = "image/png";
        } else if (uri.find(".svg") != std::string::npos) {
            content_type = "image/svg+xml";
        }

        printf(" serving %s (mime: %s, len: %s)\n", uri.c_str(), content_type.c_str(), std::to_string(sb.st_size).c_str());

        evhttp_add_header(request->output_headers, "Content-Type", content_type.c_str());
        evhttp_add_header(request->output_headers, "Content-Length", std::to_string(sb.st_size).c_str());
        evbuffer_add_file(buffer, fd, 0, sb.st_size);
        close(fd);
    }

    evhttp_send_reply(request, HTTP_OK, "", buffer);
}
