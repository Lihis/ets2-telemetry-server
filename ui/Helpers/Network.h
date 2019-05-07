#ifndef ETS2_TELEMETRY_SERVER_NETWORK_H
#define ETS2_TELEMETRY_SERVER_NETWORK_H

#include <vector>
#include <wx/string.h>

namespace Network {
    struct IFace {
        IFace(const wxString &addr, const wxString &name) {
            this->addr = addr;
            this->name = name;
        }

        wxString addr;
        wxString name;
    };
    /**
     * Get available network interfaces
     *
     * @return
     */
    std::vector<IFace> get_interfaces();

    /**
     * Get address for interface named @p iface
     *
     * @param interface
     * @return
     */
    std::string get_addr(const wxString &iface);
};


#endif //ETS2_TELEMETRY_SERVER_NETWORK_H
