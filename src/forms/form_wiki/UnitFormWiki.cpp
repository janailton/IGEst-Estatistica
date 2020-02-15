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

#include <vcl.h>
#pragma hdrstop

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

#include "UnitFormWiki.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormWiki *FormWiki;

const UnicodeString TFormWiki::pdfPath()
{
    return ExtractFilePath(ParamStr(0)) + "\\pdf\\";
}


//---------------------------------------------------------------------------
__fastcall TFormWiki::TFormWiki(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormWiki::btnAtualizarClick(TObject *Sender)
{
	//Button1->Style = TCustomButton::bsCommandLink;
	FindWiki();
	btnAtualizar->Enabled = false;
}
//---------------------------------------------------------------------------

void TFormWiki::FindWiki()
{
	TSearchRec fPDF;
	int i = 0;
	if (( FindFirst(pdfPath() + "*.*", faArchive,fPDF)) ==0)
	{
		do{
			TButton *btn = new TButton(this);
			btn->Caption = ChangeFileExt(fPDF.Name,"");
			btn->Parent = TabControl1;
			//btn->Style = TCustomButton::bsCommandLink;
			btn->Align = alTop;
			btn->OnClick = btnClickCallBack;
			btn->Tag = i;
			btn->Hint = pdfPath() + fPDF.Name;
			i++;
			//ShowMessage(fPDF.Name);
		} while (FindNext(fPDF) == 0);

	}
   FindClose(fPDF);

}

void __fastcall TFormWiki::btnClickCallBack(TObject *Sender)
{
	AnsiString file = dynamic_cast<TButton*>(Sender)->Hint;
	AnsiString sOpen = "open";
	ShellExecuteA( NULL ,sOpen.c_str(), file.c_str(), NULL, NULL, SW_SHOWNORMAL);
}
void __fastcall TFormWiki::FormActivate(TObject *Sender)
{
    btnAtualizar->Click();
}
//---------------------------------------------------------------------------

