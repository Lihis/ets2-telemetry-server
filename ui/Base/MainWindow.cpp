///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 18 2019)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainWindow.h"

///////////////////////////////////////////////////////////////////////////
using namespace Base;

MainWindow::MainWindow( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,300 ), wxDefaultSize );

	m_menubar = new wxMenuBar( 0 );
	m_menuFile = new wxMenu();
	wxMenuItem* m_menuSetup;
	m_menuSetup = new wxMenuItem( m_menuFile, wxID_SETUP, wxString( wxT("Setup") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuFile->Append( m_menuSetup );

	m_menuFile->AppendSeparator();

	wxMenuItem* m_menuExit;
	m_menuExit = new wxMenuItem( m_menuFile, wxID_EXIT, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuFile->Append( m_menuExit );

	m_menubar->Append( m_menuFile, wxT("File") );

	m_menuHelp = new wxMenu();
	wxMenuItem* m_menuAbout;
	m_menuAbout = new wxMenuItem( m_menuHelp, wxID_ABOUT, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuHelp->Append( m_menuAbout );

	m_menubar->Append( m_menuHelp, wxT("Help") );

	this->SetMenuBar( m_menubar );

	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizerLayout;
	bSizerLayout = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizerServerStatus;
	sbSizerServerStatus = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Server status") ), wxVERTICAL );

	wxBoxSizer* bSizerStatus;
	bSizerStatus = new wxBoxSizer( wxHORIZONTAL );


	bSizerStatus->Add( 0, 0, 1, wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 5, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxStaticText* m_staticTextSimulatorStatus;
	m_staticTextSimulatorStatus = new wxStaticText( sbSizerServerStatus->GetStaticBox(), wxID_ANY, wxT("Status:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextSimulatorStatus->Wrap( -1 );
	fgSizer1->Add( m_staticTextSimulatorStatus, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );

	m_simulatorStatus = new wxStaticText( sbSizerServerStatus->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_simulatorStatus->Wrap( -1 );
	fgSizer1->Add( m_simulatorStatus, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxStaticText* m_staticTextNetwork;
	m_staticTextNetwork = new wxStaticText( sbSizerServerStatus->GetStaticBox(), wxID_ANY, wxT("Network Interface:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextNetwork->Wrap( -1 );
	fgSizer1->Add( m_staticTextNetwork, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );

	wxArrayString m_networkInterfacesChoices;
	m_networkInterfaces = new wxChoice( sbSizerServerStatus->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), m_networkInterfacesChoices, 0 );
	m_networkInterfaces->SetSelection( 0 );
	fgSizer1->Add( m_networkInterfaces, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );

	wxStaticText* m_staticTextIP;
	m_staticTextIP = new wxStaticText( sbSizerServerStatus->GetStaticBox(), wxID_ANY, wxT("Server IP:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextIP->Wrap( -1 );
	fgSizer1->Add( m_staticTextIP, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );

	m_serverIP = new wxStaticText( sbSizerServerStatus->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_serverIP->Wrap( -1 );
	fgSizer1->Add( m_serverIP, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxStaticText* m_staticTextHTML5URL;
	m_staticTextHTML5URL = new wxStaticText( sbSizerServerStatus->GetStaticBox(), wxID_ANY, wxT("HTML5 App URL:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextHTML5URL->Wrap( -1 );
	fgSizer1->Add( m_staticTextHTML5URL, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );

	m_appURL = new wxHyperlinkCtrl( sbSizerServerStatus->GetStaticBox(), wxID_ANY, wxT("http://localhost"), wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	m_appURL->Hide();

	fgSizer1->Add( m_appURL, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5 );

	wxStaticText* m_staticTextAPIURL;
	m_staticTextAPIURL = new wxStaticText( sbSizerServerStatus->GetStaticBox(), wxID_ANY, wxT("Telemetry API URL:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAPIURL->Wrap( -1 );
	fgSizer1->Add( m_staticTextAPIURL, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );

	m_apiURL = new wxHyperlinkCtrl( sbSizerServerStatus->GetStaticBox(), wxID_ANY, wxT("http://localhost"), wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	m_apiURL->Hide();

	fgSizer1->Add( m_apiURL, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT|wxALL, 5 );


	bSizerStatus->Add( fgSizer1, 6, wxEXPAND, 5 );


	sbSizerServerStatus->Add( bSizerStatus, 1, wxEXPAND, 5 );


	bSizerLayout->Add( sbSizerServerStatus, 1, wxEXPAND, 5 );


	bSizerMain->Add( bSizerLayout, 1, wxEXPAND, 5 );


	this->SetSizer( bSizerMain );
	this->Layout();
	m_timerGame.SetOwner( this, wxID_ANY );
	m_timerGame.Start( 500 );


	this->Centre( wxBOTH );

	// Connect Events
	m_networkInterfaces->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainWindow::interface_changed ), NULL, this );
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( MainWindow::check_game_status ) );
}

MainWindow::~MainWindow()
{
	// Disconnect Events
	m_networkInterfaces->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MainWindow::interface_changed ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( MainWindow::check_game_status ) );

}
