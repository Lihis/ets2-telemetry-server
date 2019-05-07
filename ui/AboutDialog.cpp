#include "AboutDialog.h"
#include "Version.h"

AboutDialog::AboutDialog(wxWindow *parent) : Base::AboutDialog(parent) {
    m_version->SetLabel(ETS2_SERVER_VERSION);
}
