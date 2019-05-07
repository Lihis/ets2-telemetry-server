#include "SetupDialog.h"
#include "Version.h"
#include "Dialog.h"
#include "Helpers/Plugin.h"

SetupDialog::SetupDialog(Config &config, wxWindow *parent) : Base::SetupDialog(parent), m_config(config) {
    SetTitle("ETS Telemetry Server " ETS2_SERVER_VERSION " - Setup");
    SetReturnCode(wxID_CANCEL);

    m_ets2_path->SetPath(m_config.getETS2Path());
    if (!m_config.getATSPath().empty()) {
        m_install_ats->SetValue(true);
        m_ats_path->Enable(true);
        m_ats_path->SetPath(m_config.getATSPath());
    }

#ifndef _WIN32
    m_sbSizerFirewall->Show(false);
#endif
}

void SetupDialog::on_install_ets2(wxCommandEvent &/*event*/) {
    m_ets2_path->Enable(m_install_ets2->IsChecked());
}

void SetupDialog::on_install_ats(wxCommandEvent &/*event*/) {
    m_ats_path->Enable(m_install_ats->IsChecked());
}

void SetupDialog::on_install_click(wxCommandEvent &/*event*/) {
    if (!m_install_ets2->IsChecked() && !m_install_ats->IsChecked()) {
        Dialog::Error(this, "Error", "Either ETS2 or ATS plugin must be installed.").ShowModal();
        return;
    }

    if (m_install_ets2->IsChecked()) {
        if (m_ets2_path->GetPath().empty()) {
            Dialog::Error(this, "Error", "Select ETS2 path.").ShowModal();
            return;
        } else {
            wxString error;
            if (!Plugin::install(Game::ETS2, m_ets2_path->GetPath(), error)) {
                Dialog::Error(this, "Error", "Failed to install ETS2 plugin.\n\n" + error).ShowModal();
                return;
            }
            m_config.setETS2Path(m_ets2_path->GetPath());
        }
    }

    if (m_install_ats->IsChecked()) {
        if (m_ats_path->GetPath().empty()) {
            Dialog::Error(this, "Error", "Select ATS path.").ShowModal();
            return;
        } else {
            wxString error;
            if (!Plugin::install(Game::ATS, m_ats_path->GetPath(), error)) {
                Dialog::Error(this, "Error", "Failed to install ATS plugin.\n\n" + error).ShowModal();
                return;
            }
            m_config.setATSPath(m_ats_path->GetPath());
        }
    }

#ifdef _WIN32
    {
        Dialog::Error(this, "Warning", "Firewall and ACL rule installation not implemented.").ShowModal();
    }
#endif

    if (!m_config.save()) {
        Dialog::Error(this, "Error", "Failed to save configuration.").ShowModal();
    } else {
        Dialog::Error(this, "Success", "Installation done.").ShowModal();
        EndDialog(wxID_OK);
    }
}
