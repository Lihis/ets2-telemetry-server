#include "Config.h"
#include "Helpers/Network.h"
#include <wx/filename.h>
#include <wx/fileconf.h>
#ifdef __linux__
#include <cstdlib>
#else
#include <wx/stdpaths.h>
#endif

bool Config::load() {
    wxString confFile;
    wxFileConfig *config;

    confFile = getConfigFile();
    if (confFile.empty()) {
        return false;
    }

    config = new wxFileConfig(wxEmptyString, wxEmptyString, confFile);

    config->SetPath("paths");
    m_ets2_path = config->Read("ets2", "");
    m_ats_path = config->Read("ats", "");

    config->SetPath("network");
    m_interface_name = config->Read("interface", "");
    if (m_interface_name.empty()) {
        std::vector<Network::IFace> interfaces = Network::get_interfaces();
        if (!interfaces.empty()) {
            m_interface_name = interfaces.at(0).name;
        }
    }
    m_port = config->Read("port", 25555);

    delete config;

    return (!m_ets2_path.empty() || !m_ats_path.empty());
}

bool Config::save() {
    wxString confFile;
    wxFileConfig *config;

    confFile = getConfigFile();
    if (confFile.empty()) {
        return false;
    }

    if (!wxDirExists(wxPathOnly(confFile))) {
        if (!wxMkdir(wxPathOnly(confFile))) {
            return false;
        }
    }

    config = new wxFileConfig(wxEmptyString, wxEmptyString, confFile);

    config->SetPath("paths");
    config->Write("ets2", m_ets2_path);
    config->Write("ats", m_ats_path);

    config->SetPath("network");
    config->Write("interface", m_interface_name);
    config->Write("port", m_port);

    delete config;

    return true;
}

wxString Config::getETS2Path() const {
    return m_ets2_path;
}

void Config::setETS2Path(const wxString &path) {
    m_ets2_path = path;
}

wxString Config::getATSPath() const {
    return m_ats_path;
}

void Config::setATSPath(const wxString &path) {
    m_ats_path = path;
}

wxString Config::getNetworkInterFace() const {
    return m_interface_name;
}

void Config::setNetworkInterface(const wxString &name) {
    m_interface_name = name;
}

uint32_t Config::getPort() const {
    return m_port;
}

void Config::setPort(const wxString &port) {
    m_port = static_cast<uint32_t>(wxAtoi(port));
}

wxString Config::getConfigFile() const {
    wxString path;

    path = getConfigDir();
    if (path.empty()) {
        return "";
    } else {
        path += wxFileName::GetPathSeparator() +  wxString("ets2-telemetry-server");
    }

    return path + wxFileName::GetPathSeparator() + wxString("config.ini");
}

wxString Config::getConfigDir() const {
#ifdef __linux__
    char *path = std::getenv("XDG_CONFIG_HOME");
    if (!path) {
        path = std::getenv("HOME");
        if (path) {
            return std::string(path).append("/.local/share").c_str();
        }
    }

    return path;
#else
    return wxStandardPaths::Get().GetUserConfigDir();
#endif
}
