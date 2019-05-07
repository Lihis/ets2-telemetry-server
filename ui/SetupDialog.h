#ifndef ETS2_TELEMETRY_SERVER_SETUPDIALOG_H
#define ETS2_TELEMETRY_SERVER_SETUPDIALOG_H

#include "Base/SetupDialog.h"
#include "Config.h"
#include <vector>

class SetupDialog : public Base::SetupDialog {
public:
    explicit SetupDialog(Config &config, wxWindow *parent);

    SetupDialog(SetupDialog const&) = delete;
    SetupDialog& operator=(SetupDialog const &) = delete;

protected:
    void on_install_ets2(wxCommandEvent &event) final;
    void on_install_ats(wxCommandEvent &event) final;

    void on_install_click(wxCommandEvent &event) final;

    Config &m_config;
};


#endif //ETS2_TELEMETRY_SERVER_SETUPDIALOG_H
