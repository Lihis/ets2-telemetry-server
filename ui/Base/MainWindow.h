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
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/hyperlink.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/timer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

namespace Base
{

	///////////////////////////////////////////////////////////////////////////////
	/// Class MainWindow
	///////////////////////////////////////////////////////////////////////////////
	class MainWindow : public wxFrame
	{
		private:

		protected:
			wxMenuBar* m_menubar;
			wxMenu* m_menuFile;
			wxMenu* m_menuHelp;
			wxStaticText* m_simulatorStatus;
			wxChoice* m_networkInterfaces;
			wxStaticText* m_serverIP;
			wxHyperlinkCtrl* m_appURL;
			wxHyperlinkCtrl* m_apiURL;
			wxTimer m_timerGame;

			// Virtual event handlers, overide them in your derived class
			virtual void interface_changed( wxCommandEvent& event ) = 0;
			virtual void check_game_status( wxTimerEvent& event ) = 0;


		public:

			MainWindow( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("ETS2 Telemetry Server"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

			~MainWindow();

	};

} // namespace Base

