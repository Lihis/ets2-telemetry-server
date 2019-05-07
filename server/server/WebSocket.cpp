#include "WebSocket.h"
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

WebSocket::WebSocket() {
    m_endpoint = new websocketpp::server<websocketpp::config::asio>();
    auto endpoint = reinterpret_cast<websocketpp::server<websocketpp::config::asio> *>(m_endpoint);
    endpoint->clear_access_channels(websocketpp::log::alevel::all);
    endpoint->clear_error_channels(websocketpp::log::alevel::all);

    endpoint->set_access_channels(websocketpp::log::alevel::access_core);
    endpoint->set_access_channels(websocketpp::log::alevel::app);

    endpoint->init_asio();
    endpoint->set_reuse_addr(true);

    endpoint->set_open_handler(websocketpp::lib::bind(&WebSocket::on_open, this, websocketpp::lib::placeholders::_1));
    endpoint->set_close_handler(websocketpp::lib::bind(&WebSocket::on_close, this, websocketpp::lib::placeholders::_1));
}

WebSocket::~WebSocket() {
    if (!reinterpret_cast<websocketpp::server<websocketpp::config::asio> *>(m_endpoint)->stopped()) {
        stop();
    }

    delete reinterpret_cast<websocketpp::server<websocketpp::config::asio> *>(m_endpoint);
    m_endpoint = nullptr;
}

void WebSocket::start() {
    LockGuard lock(m_lock);

    auto endpoint = reinterpret_cast<websocketpp::server<websocketpp::config::asio> *>(m_endpoint);
    if (!endpoint->is_listening()) {
        endpoint->listen(20211);
        endpoint->start_accept();
        m_thread = std::thread(&WebSocket::run, this);
    }
}

void WebSocket::stop() {
    LockGuard lock(m_lock);

    auto endpoint = reinterpret_cast<websocketpp::server<websocketpp::config::asio> *>(m_endpoint);
    if (endpoint->is_listening()) {
        endpoint->stop_listening();
        endpoint->stop();
        m_thread.join();
    }
}

bool WebSocket::is_running() {
    LockGuard lock(m_lock);

    return reinterpret_cast<websocketpp::server<websocketpp::config::asio> *>(m_endpoint)->is_listening();
}

void WebSocket::send(const std::string &data) {
    auto endpoint = reinterpret_cast<websocketpp::server<websocketpp::config::asio> *>(m_endpoint);
    std::set<websocketpp::connection_hdl,std::owner_less<websocketpp::connection_hdl>>::iterator it;

    for (it = m_connections.begin(); it != m_connections.end(); ++it) {
        endpoint->send(*it, data, websocketpp::frame::opcode::text);
    }
}

void WebSocket::run() {
    reinterpret_cast<websocketpp::server<websocketpp::config::asio> *>(m_endpoint)->run();
}

void WebSocket::on_open(const websocketpp::connection_hdl &hdl) {
    m_connections.insert(hdl);
}

void WebSocket::on_close(const websocketpp::connection_hdl &hdl) {
    m_connections.erase(hdl);
}
