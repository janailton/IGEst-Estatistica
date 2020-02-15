//    Copyright (C) 2020 - 2009 José Janaílton da Silva <josejanailton@gmail.com>
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

//---------------------------------------------------------------------------

#ifndef UnitFormWikiH
#define UnitFormWikiH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormWiki : public TForm
{
__published:	// IDE-managed Components
	TTabControl *TabControl1;
	TButton *btnAtualizar;
	void __fastcall btnAtualizarClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormWiki(TComponent* Owner);

	void FindWiki();
	void __fastcall btnClickCallBack(TObject *Sender);
	const UnicodeString pdfPath();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormWiki *FormWiki;
//---------------------------------------------------------------------------

void __fastcall ShowFormWiki()
{
	TFormWiki *_FormWiki = new TFormWiki(Application);
	_FormWiki->Visible = false;
	_FormWiki->ShowModal();
    _FormWiki->Free();
}


#endif
