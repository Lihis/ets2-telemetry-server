#ifndef ETS2_TELEMETRY_SERVER_IAPPLICATION_H
#define ETS2_TELEMETRY_SERVER_IAPPLICATION_H

#include <wx/string.h>
#include <map>

class IApplication {
public:
    virtual bool isGameRunning() = 0;
    virtual bool isGameRunning(std::string &game) = 0;
    virtual bool isConnected() = 0;

    virtual int showSetup() = 0;

    virtual wxString getETS2Path() const = 0;
    virtual void setETS2Path(const wxString &path) = 0;

    virtual wxString getATSPath() const = 0;
    virtual void setATSPath(const wxString &path) = 0;

    virtual wxString getNetworkInterFace() const = 0;
    virtual void setNetworkInterface(const wxString &name) = 0;

    virtual uint32_t getPort() const = 0;
    virtual void setPort(const wxString &port) = 0;
};

#endif //ETS2_TELEMETRY_SERVER_IAPPLICATION_H
