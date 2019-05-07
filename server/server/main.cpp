#include "TelemeteryHelper.h"
#include "WebSocket.h"
#include "HttpServer.h"
#include <csignal>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <cstdio>
#include <unistd.h>
#include <ctime>

#include <fstream>

namespace {
    volatile std::atomic<bool> run = { true };
}

void *open_shared() {
    int fd;
    struct stat sb = {};

    fd = open("/tmp/shm_telemetry", O_RDONLY | O_CLOEXEC);
    if (fd == -1) {
        fprintf(stderr, "Failed to open shared mem file.\n");
        return nullptr;
    }

    if (fstat(fd, &sb) == -1) {
        fprintf(stderr, "Failed to stat shared mem file.\n");
        return nullptr;
    }

    return mmap(nullptr, (size_t)sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
}

bool isGameRunning() {
    return true;//(system("ps aux | grep '[e]urotrucks2' &>/dev/null") == 0);
}

void signal_handler(int /*signal*/) {
    run = false;
    exit(0);
}

int main(int argc, char *argv[]) {
    signal(SIGINT, signal_handler);

    Ets2Telemetry::Structure *shared_mem;

    // Wait shared memory to be available
    do {
        shared_mem = reinterpret_cast<Ets2Telemetry::Structure *>(open_shared());
        sleep(1);
    } while (!shared_mem);

    WebSocket websoc;
    websoc.start();

    HttpServer server(shared_mem);
    if (!server.start()) {
        printf("Failed to start server.\n");
        return 1;
    } else {
        printf("Server started\n");
    }

    std::stringstream content;
    std::ifstream file("../Ets2TestTelemetry.json");
    if (file.is_open()) {
        content << file.rdbuf();
        file.close();
    }

    while (run) {
        server.setConnected(isGameRunning());
        websoc.send(Ets2Telemetry::toJson(isGameRunning(), shared_mem), websocketpp::frame::opcode::text);
        usleep(100000);
    }

    server.stop();
    websoc.stop();

    return 0;
}