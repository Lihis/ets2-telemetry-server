#ifndef ETS2_TELEMETRY_SERVER_HTTPSERVER_H
#define ETS2_TELEMETRY_SERVER_HTTPSERVER_H

#include <evhttp.h>
#include <ets2-telemetry-common.hpp>
#include <mutex>
#include <thread>

class HttpServer {
public:
    explicit HttpServer(ets2TelemetryMap_t *telemetry);
    ~HttpServer();

    bool start(const std::string &addr, uint16_t port);
    bool stop();
    bool isRunning();

private:
    static void register_cb(struct evhttp_request *request, void *arg);

    bool init_server(const std::string &addr, uint16_t port);

    void server_loop();

    void api_callback(struct evhttp_request *request, void *arg);

    event_base *m_event;
    evhttp *m_server;
    bool m_running;

    ets2TelemetryMap_t *m_telemetry;

    typedef std::lock_guard<std::mutex> LockGuard;
    std::thread m_thread;
    std::mutex m_lock;
};

#endif //ETS2_TELEMETRY_SERVER_HTTPSERVER_H
