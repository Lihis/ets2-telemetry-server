#ifndef ETS2_TELEMETRY_SERVER_CONFIG_H
#define ETS2_TELEMETRY_SERVER_CONFIG_H

#include <wx/string.h>

class Config {
public:
    Config() = default;
    ~Config() = default;

    Config(Config const&) = delete;
    Config& operator=(Config const &) = delete;

    bool load();
    bool save();

    wxString getETS2Path() const;
    void setETS2Path(const wxString &path);
    wxString getATSPath() const;
    void setATSPath(const wxString &path);
    wxString getNetworkInterFace() const;
    void setNetworkInterface(const wxString &name);
    uint32_t getPort() const;
    void setPort(const wxString &port);
private:
    wxString getConfigFile() const;
    wxString getConfigDir() const;

    wxString m_ets2_path;
    wxString m_ats_path;
    wxString m_interface_name;
    uint32_t m_port;
};


#endif //ETS2_TELEMETRY_SERVER_CONFIG_H
