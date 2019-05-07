#ifndef ETS2_TELEMETRY_SERVER_WEBSOCKET_H
#define ETS2_TELEMETRY_SERVER_WEBSOCKET_H

#include <set>
#include <websocketpp/common/connection_hdl.hpp>
#include <mutex>
#include <thread>

class WebSocket {
public:
    WebSocket();
    ~WebSocket();

    void start();
    void stop();
    bool is_running();

    void send(const std::string &data);

private:
    void run();
    void on_open(const websocketpp::connection_hdl &hdl);
    void on_close(const websocketpp::connection_hdl &hdl);

    void *m_endpoint;
    std::set<websocketpp::connection_hdl,std::owner_less<websocketpp::connection_hdl>> m_connections;

    typedef std::lock_guard<std::mutex> LockGuard;
    std::mutex m_lock;
    std::thread m_thread;
};

#endif //ETS2_TELEMETRY_SERVER_WEBSOCKET_H
