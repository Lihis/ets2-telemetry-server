#ifndef ETS2_TELEMETRY_SERVER_DIALOGS_H
#define ETS2_TELEMETRY_SERVER_DIALOGS_H

#include "Base/Dialogs.h"

namespace Dialog {
    class Error : public Base::OKDialog {
    public:
        Error(wxWindow *parent, const wxString &title, const wxString &message);

        Error(Error const&) = delete;
        Error& operator=(Error const &) = delete;

    protected:
        void on_close(wxCloseEvent &event) final;
    };
}


#endif //ETS2_TELEMETRY_SERVER_DIALOGS_H
