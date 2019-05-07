///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 18 2019)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "AboutDialog.h"

///////////////////////////////////////////////////////////////////////////
using namespace Base;

AboutDialog::AboutDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );

	wxBoxSizer* bSizerPanel;
	bSizerPanel = new wxBoxSizer( wxVERTICAL );

	m_logo = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizerPanel->Add( m_logo, 0, wxALIGN_CENTER|wxALL, 5 );

	wxStaticText* m_staticTextTitle;
	m_staticTextTitle = new wxStaticText( this, wxID_ANY, wxT("ETS2 Telemetry Server"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTitle->Wrap( -1 );
	m_staticTextTitle->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizerPanel->Add( m_staticTextTitle, 0, wxALIGN_CENTER|wxALL, 5 );

	m_version = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_version->Wrap( -1 );
	bSizerPanel->Add( m_version, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	wxStaticText* m_staticTextDescription;
	m_staticTextDescription = new wxStaticText( this, wxID_ANY, wxT("Telemetry Web Server for Euro Truck Simulator 2 and American Truck Simulator written in C++ based on WebSockets and REST API. The client side consists of a skinnable HTML5 mobile dashboard application that works in any modern desktop or mobile browser."), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticTextDescription->Wrap( 500 );
	bSizerPanel->Add( m_staticTextDescription, 0, wxALIGN_CENTER|wxALL, 5 );

	wxHyperlinkCtrl* m_hyperlinkHomepage;
	m_hyperlinkHomepage = new wxHyperlinkCtrl( this, wxID_ANY, wxT("Website"), wxT("https://github.com/Funbit/ets2-telemetry-server"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizerPanel->Add( m_hyperlinkHomepage, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bSizerPanel->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticTextWarranty = new wxStaticText( this, wxID_ANY, wxT("This program comes with absolutely no warranty."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextWarranty->Wrap( -1 );
	m_staticTextWarranty->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizerPanel->Add( m_staticTextWarranty, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticTextSee;
	m_staticTextSee = new wxStaticText( this, wxID_ANY, wxT("See the"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextSee->SetLabelMarkup( wxT("See the") );
	m_staticTextSee->Wrap( -1 );
	m_staticTextSee->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer11->Add( m_staticTextSee, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_hyperlinkGPLv3 = new wxHyperlinkCtrl( this, wxID_ANY, wxT("GNU General Public License, version 3 or later"), wxT("https://www.gnu.org/licenses/gpl-3.0.html"), wxDefaultPosition, wxSize( -1,-1 ), wxHL_DEFAULT_STYLE );
	m_hyperlinkGPLv3->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer11->Add( m_hyperlinkGPLv3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticTextDetails = new wxStaticText( this, wxID_ANY, wxT("for details."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDetails->Wrap( -1 );
	m_staticTextDetails->SetFont( wxFont( 8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer11->Add( m_staticTextDetails, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizerPanel->Add( bSizer11, 1, wxALIGN_CENTER, 5 );


	this->SetSizer( bSizerPanel );
	this->Layout();
	bSizerPanel->Fit( this );

	this->Centre( wxBOTH );
}

AboutDialog::~AboutDialog()
{
}
