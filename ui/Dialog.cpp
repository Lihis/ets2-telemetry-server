#include "Dialog.h"

namespace Dialog {
    Error::Error(wxWindow *parent, const wxString &title, const wxString &message) : Base::OKDialog(parent) {
        SetTitle(title);
        m_staticText->SetLabel(message);

        Connect(wxID_OK, wxEVT_COMMAND_TOOL_CLICKED, wxCloseEventHandler(Error::on_close));
        Fit();
    }

    void Error::on_close(wxCloseEvent &event) {
        EndDialog(wxID_OK);
    }
}
