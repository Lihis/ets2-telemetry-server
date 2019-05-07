///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 18 2019)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "SetupDialog.h"

///////////////////////////////////////////////////////////////////////////
using namespace Base;

SetupDialog::SetupDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizerGamePaths;
	sbSizerGamePaths = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Game Paths") ), wxVERTICAL );

	wxBoxSizer* bSizerGamePathsMain;
	bSizerGamePathsMain = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizerETS2;
	bSizerETS2 = new wxBoxSizer( wxVERTICAL );

	m_install_ets2 = new wxCheckBox( sbSizerGamePaths->GetStaticBox(), wxID_ANY, wxT("ETS2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_install_ets2->SetValue(true);
	bSizerETS2->Add( m_install_ets2, 0, wxALL, 5 );

	wxBoxSizer* bSizerETS2Path;
	bSizerETS2Path = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticTextETS2Path;
	m_staticTextETS2Path = new wxStaticText( sbSizerGamePaths->GetStaticBox(), wxID_ANY, wxT("Path:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextETS2Path->Wrap( -1 );
	bSizerETS2Path->Add( m_staticTextETS2Path, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_ets2_path = new wxDirPickerCtrl( sbSizerGamePaths->GetStaticBox(), wxID_ANY, wxEmptyString, wxT("Select ETS2 folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	bSizerETS2Path->Add( m_ets2_path, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizerETS2->Add( bSizerETS2Path, 1, wxEXPAND, 5 );


	bSizerGamePathsMain->Add( bSizerETS2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizerATS;
	bSizerATS = new wxBoxSizer( wxVERTICAL );

	m_install_ats = new wxCheckBox( sbSizerGamePaths->GetStaticBox(), wxID_ANY, wxT("ATS"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerATS->Add( m_install_ats, 0, wxALL, 5 );

	wxBoxSizer* bSizerATSPath;
	bSizerATSPath = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticTextATSPath;
	m_staticTextATSPath = new wxStaticText( sbSizerGamePaths->GetStaticBox(), wxID_ANY, wxT("Path:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextATSPath->Wrap( -1 );
	bSizerATSPath->Add( m_staticTextATSPath, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_ats_path = new wxDirPickerCtrl( sbSizerGamePaths->GetStaticBox(), wxID_ANY, wxEmptyString, wxT("Select ATS folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	m_ats_path->Enable( false );

	bSizerATSPath->Add( m_ats_path, 0, wxALL, 5 );


	bSizerATS->Add( bSizerATSPath, 1, wxEXPAND, 5 );


	bSizerGamePathsMain->Add( bSizerATS, 1, wxEXPAND, 5 );


	sbSizerGamePaths->Add( bSizerGamePathsMain, 1, wxEXPAND, 5 );


	bSizerMain->Add( sbSizerGamePaths, 0, wxALL|wxEXPAND, 5 );

	m_sbSizerFirewall = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Firewall") ), wxVERTICAL );

	m_firewall_rule = new wxCheckBox( m_sbSizerFirewall->GetStaticBox(), wxID_ANY, wxT("Add firewall rule for 25555 port"), wxDefaultPosition, wxDefaultSize, 0 );
	m_sbSizerFirewall->Add( m_firewall_rule, 0, wxALL, 5 );

	m_acl_rule = new wxCheckBox( m_sbSizerFirewall->GetStaticBox(), wxID_ANY, wxT("Add ACL rule for http://+:25555/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_sbSizerFirewall->Add( m_acl_rule, 0, wxALL, 5 );


	bSizerMain->Add( m_sbSizerFirewall, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizerBottom;
	bSizerBottom = new wxBoxSizer( wxHORIZONTAL );

	m_hyperlink3 = new wxHyperlinkCtrl( this, wxID_ANY, wxT("Help"), wxT("https://github.com/Funbit/ets2-telemetry-server"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizerBottom->Add( m_hyperlink3, 0, wxALIGN_LEFT|wxALL, 5 );


	bSizerBottom->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_install = new wxButton( this, wxID_ANY, wxT("Install"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerBottom->Add( m_button_install, 0, wxALL, 5 );


	bSizerMain->Add( bSizerBottom, 0, wxEXPAND, 5 );


	this->SetSizer( bSizerMain );
	this->Layout();
	bSizerMain->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_install_ets2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SetupDialog::on_install_ets2 ), NULL, this );
	m_install_ats->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SetupDialog::on_install_ats ), NULL, this );
	m_button_install->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDialog::on_install_click ), NULL, this );
}

SetupDialog::~SetupDialog()
{
	// Disconnect Events
	m_install_ets2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SetupDialog::on_install_ets2 ), NULL, this );
	m_install_ats->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SetupDialog::on_install_ats ), NULL, this );
	m_button_install->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SetupDialog::on_install_click ), NULL, this );

}
