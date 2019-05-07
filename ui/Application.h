#ifndef ETS2_TELEMETRY_SERVER_APPLICATION_H
#define ETS2_TELEMETRY_SERVER_APPLICATION_H

#include <wx/app.h>
#include "IApplication.h"
#include "Config.h"
#include "MainWindow.h"
#include <ets2-telemetry-common.hpp>
#include "server/WebSocket.h"
#include "server/HttpServer.h"

class Application : public wxApp, public IApplication {
public:
    Application();

    Application(Application const&) = delete;
    Application& operator=(Application const &) = delete;

    bool isGameRunning() final;
    bool isGameRunning(std::string &game) final;
    bool isConnected() final;

    int showSetup() final;

    wxString getETS2Path() const final;
    void setETS2Path(const wxString &path) final;

    wxString getATSPath() const final;
    void setATSPath(const wxString &path) final;

    wxString getNetworkInterFace() const final;
    void setNetworkInterface(const wxString &name) final;

    uint32_t getPort() const final;
    void setPort(const wxString &port) final;

protected:
    bool OnInit() final;
    int OnExit() override;

    /**
     * Open Shared Memory
     *
     * @return
     */
    void *open_shared_memory();

    /**
     * Close Shared Memory
     */
    void close_shared_memory();

    void send_to_socket(wxTimerEvent &event);
private:
    wxTimer m_timer_send;
    Config m_config;
    MainWindow *m_window;

#ifdef _WIN32
    HANDLE m_telemetry_handle;
#else
    int m_telemetry_handle;
#endif
    ets2TelemetryMap_t *m_telemetry;

    WebSocket *m_socket;
    HttpServer *m_http;
};

#endif //ETS2_TELEMETRY_SERVER_APPLICATION_H
