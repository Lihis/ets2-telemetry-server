#include "Application.h"
#include "MainWindow.h"
#include "SetupDialog.h"
#include "server/TelemeteryHelper.h"
#include "Helpers/Network.h"
#include "Dialog.h"

#ifdef _WIN32
#include <windows.h>
#include <memoryapi.h>
#include <winbase.h>
#else
#include <sys/mman.h>
#endif

Application::Application() :
#ifdef _WIN32
m_telemetry_handle(nullptr),
#else
m_telemetry_handle(0),
#endif
m_telemetry(nullptr),
m_socket(new WebSocket()),
m_http(nullptr),
m_window(nullptr)
{
    SetAppName("ets2-telemetry-server");
    SetAppDisplayName("ETS2 Telemetry Server");

    Connect(m_timer_send.GetId(), wxEVT_TIMER, wxTimerEventHandler(Application::send_to_socket));
}

bool Application::isGameRunning() {
    std::string game;

    return isGameRunning(game);
}

bool Application::isGameRunning(std::string &game) {
    bool running = TelemetryHelper::isGameRunning(game);

    if (running && !m_telemetry) {
        m_telemetry = reinterpret_cast<ets2TelemetryMap_t *>(open_shared_memory());
        if (m_telemetry) {
            if (!m_timer_send.IsRunning()) {
                m_timer_send.Start(100);
            }
        }
    } else if (!running && m_timer_send.IsRunning()) {
        close_shared_memory();
        m_timer_send.Stop();
    }

    return running;
}

bool Application::isConnected() {
    return m_telemetry;
}

int Application::showSetup() {
    int ret;

    auto setup = new SetupDialog(m_config, nullptr);
    ret = setup->ShowModal();
    delete setup;

    return ret;
}

wxString Application::getETS2Path() const {
    return m_config.getETS2Path();
}

void Application::setETS2Path(const wxString &path) {
    m_config.setETS2Path(path);
}

wxString Application::getATSPath() const {
    return m_config.getATSPath();
}

void Application::setATSPath(const wxString &path) {
    m_config.setATSPath(path);
}

wxString Application::getNetworkInterFace() const {
    return m_config.getNetworkInterFace();
}

void Application::setNetworkInterface(const wxString &name) {
    m_config.setNetworkInterface(name);
    if (!m_config.save()) {
        Dialog::Error(m_window, "Error", "Failed to save configuration.");
    } else {
        if (m_http->isRunning()) {
            m_http->stop();
        }
        m_http->start(Network::get_addr(m_config.getNetworkInterFace()), m_config.getPort());
    }
}

uint32_t Application::getPort() const {
    return m_config.getPort();
}

void Application::setPort(const wxString &port) {
    m_config.setPort(port);
}

bool Application::OnInit() {
    if (!m_config.load()) {
        if (showSetup() == wxID_CANCEL) {
            return false;
        }
    } else {
        if (!m_config.getETS2Path().empty()) {

        }
    }

    m_socket->start();
    m_http = new HttpServer(m_telemetry);
    m_http->start(Network::get_addr(m_config.getNetworkInterFace()), m_config.getPort());

    m_window = new MainWindow(this);
    m_window->Show(true);
    SetTopWindow(m_window);

    return true;
}

int Application::OnExit() {
    if (m_timer_send.IsRunning()) {
        m_timer_send.Stop();
    }

    if (m_http->isRunning()) {
        m_http->stop();
    }

    if (m_socket->is_running()) {
        m_socket->stop();
    }

    if (m_telemetry) {
        close_shared_memory();
    }

    return wxApp::OnExit();
}

void *Application::open_shared_memory() {
#ifdef _WIN32
    return (m_telemetry_handle = OpenFileMapping(FILE_MAP_READ, false, ETS2_PLUGIN_MMF_NAME));
#else
    struct stat sb = {};

    m_telemetry_handle = open("/tmp/shm_telemetry", O_RDONLY | O_CLOEXEC);
    if (m_telemetry_handle == -1) {
        m_telemetry_handle = 0;
        fprintf(stderr, "Failed to open shared mem file.\n");
        return nullptr;
    }

    if (fstat(m_telemetry_handle, &sb) == -1) {
        m_telemetry_handle = 0;
        fprintf(stderr, "Failed to stat shared mem file.\n");
        return nullptr;
    }

    return mmap(nullptr, (size_t)sb.st_size, PROT_READ, MAP_SHARED, m_telemetry_handle, 0);
#endif
}

void Application::close_shared_memory() {
#ifdef _WIN32
    if (m_telemetry_handle) {
        CloseHandle(m_telemetry_handle);
        m_telemetry_handle = nullptr;
        m_telemetry = nullptr;
    }
#else
    if (m_telemetry_handle > 0) {
        close(m_telemetry_handle);
        m_telemetry_handle = 0;
        m_telemetry = nullptr;
    }
#endif
}

void Application::send_to_socket(wxTimerEvent &/*event*/) {
    m_socket->send(TelemetryHelper::toJson(isGameRunning(), m_telemetry));
}
