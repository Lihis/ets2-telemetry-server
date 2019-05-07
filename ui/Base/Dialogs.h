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
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

namespace Base
{

	///////////////////////////////////////////////////////////////////////////////
	/// Class OKDialog
	///////////////////////////////////////////////////////////////////////////////
	class OKDialog : public wxDialog
	{
		private:

		protected:
			wxStaticText* m_staticText;
			wxButton* m_buttonOK;

			// Virtual event handlers, overide them in your derived class
			virtual void on_close( wxCloseEvent& event ) = 0;


		public:

			OKDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
			~OKDialog();

	};

} // namespace Base

