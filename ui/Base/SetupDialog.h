///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 18 2019)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/checkbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/hyperlink.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

namespace Base
{

	///////////////////////////////////////////////////////////////////////////////
	/// Class SetupDialog
	///////////////////////////////////////////////////////////////////////////////
	class SetupDialog : public wxDialog
	{
		private:

		protected:
			wxCheckBox* m_install_ets2;
			wxDirPickerCtrl* m_ets2_path;
			wxCheckBox* m_install_ats;
			wxDirPickerCtrl* m_ats_path;
			wxStaticBoxSizer* m_sbSizerFirewall;
			wxCheckBox* m_firewall_rule;
			wxCheckBox* m_acl_rule;
			wxHyperlinkCtrl* m_hyperlink3;
			wxButton* m_button_install;

			// Virtual event handlers, overide them in your derived class
			virtual void on_install_ets2( wxCommandEvent& event ) = 0;
			virtual void on_install_ats( wxCommandEvent& event ) = 0;
			virtual void on_install_click( wxCommandEvent& event ) = 0;


		public:

			SetupDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
			~SetupDialog();

	};

} // namespace Base

