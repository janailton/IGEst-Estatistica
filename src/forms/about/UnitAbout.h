//    Copyright (C) 2009 Jos� Jana�lton da Silva <josejanailton@gmail.com>
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA



//---------------------------------------------------------------------------

#ifndef UnitAboutH
#define UnitAboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>

#include <string>
using namespace std;

#include "../../Vers�o/UnitVersao.h"

//---------------------------------------------------------------------------
class TFormAbout : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *LabelAppName;
	TLabel *LabelAutor;
	TLabel *LabelLicense;
	TLabel *LabelEmail;
	TLabel *LabelSite;
	TImage *Image1;
	void __fastcall LabelSiteClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormAbout(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAbout *FormAbout;
//---------------------------------------------------------------------------

void __fastcall ShowFormAbout( string AppName , string Versao , string Autor , string Email , string License )
{

	TFormAbout *FormAbout = new TFormAbout(Application);
	FormAbout->Visible = false;
	FormAbout->LabelAppName->Caption = string( AppName + " " + Versao ).c_str();
	FormAbout->LabelAutor->Caption = string( "Autor: " + Autor ).c_str();
	FormAbout->LabelEmail->Caption = string( "Contato: " + Email ).c_str();
	FormAbout->LabelLicense->Caption = License.c_str();
	FormAbout->LabelSite->Caption = string( "Fa�a o download de atualiza��es no site oficial: " + IGEST_VERSAO::SITE ).c_str();
	FormAbout->ShowModal();
	FormAbout->Free();
}

#endif
