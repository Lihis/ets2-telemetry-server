#include "MainWindow.h"
#include "AboutDialog.h"
#include "SetupDialog.h"
#include "Helpers/Network.h"
#ifndef _WIN32
#include "Resources/app.xpm"
#else
#warning "Application does not have icon."
#endif

MainWindow::MainWindow(IApplication *app) : Base::MainWindow(nullptr), m_app(app) {
#ifndef _WIN32
    // FIXME: Removed #ifdef when icon is available for Windows
    SetIcon(wxIcon(app_xpm));
#endif
    Connect(wxID_SETUP, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainWindow::on_setup));
    Connect(wxID_EXIT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainWindow::on_exit));
    Connect(wxID_ABOUT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(MainWindow::on_about));

    for (const auto &iface : Network::get_interfaces()) {
        m_networkInterfaces->Append(iface.name);
        if (iface.name == m_app->getNetworkInterFace()) {
            m_networkInterfaces->Select(m_networkInterfaces->GetCount() - 1);
        }
    }

    update_urls();
}

void MainWindow::interface_changed(wxCommandEvent &/*event*/) {
    wxString iface = m_networkInterfaces->GetStringSelection();

    if (iface != m_app->getNetworkInterFace()) {
        m_app->setNetworkInterface(iface);
        update_urls();
    }
}

void MainWindow::check_game_status(wxTimerEvent &/*event*/) {
    std::string game;
    bool running;

    running = m_app->isGameRunning(game);
    if (running && m_app->isConnected()) {
        m_simulatorStatus->SetLabel("Connected to simulator (" + game + ")");
        m_simulatorStatus->SetForegroundColour(wxColour(0, 100, 0));
    } else if (running) {
        m_simulatorStatus->SetLabel("Simulator is running (" + game + ")");
        m_simulatorStatus->SetForegroundColour(wxColour(0, 128, 128));
    } else {
        m_simulatorStatus->SetLabel("Simulator is not running");
        m_simulatorStatus->SetForegroundColour(wxColour(240, 55, 30));
    }
}

void MainWindow::update_urls() {
    wxString addr = Network::get_addr(m_networkInterfaces->GetStringSelection());
    if (addr.empty()) {
        m_serverIP->Show(false);
        m_appURL->Show(false);
        m_apiURL->Show(false);
    } else {
        wxString url = "http://" + addr + ":" + std::to_string(m_app->getPort()) + "/";

        m_serverIP->Show(true);
        m_serverIP->SetLabel(addr);
        m_appURL->SetLabel(url);
        m_appURL->SetURL(url);
        m_appURL->Show(true);
        m_apiURL->SetLabel(url + "api/ets2/telemetry");
        m_apiURL->SetURL(url + "api/ets2/telemetry");
        m_apiURL->Show(true);
    }
}

void MainWindow::on_setup(wxCommandEvent &event) {
    (void)m_app->showSetup();
}

void MainWindow::on_exit(wxCommandEvent &event) {
    Close();
}

void MainWindow::on_about(wxCommandEvent &event) {
    auto about = new AboutDialog(this);
    about->ShowModal();
    delete about;
}
