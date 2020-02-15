//    Copyright (C) 2009 José Janaílton da Silva <josejanailton@gmail.com>
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

#ifndef unit_fdistriH
#define unit_fdistriH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormFDistr : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TLabel *Label1;
	TEdit *EditglNumerador;
    TLabel *Label2;
	TEdit *EditglDenominador;
    TLabel *Label3;
	TEdit *EditAlpha;
	TGroupBox *GroupBox3;
	TButton *Button1;
	TEdit *EditResultado;
	TLabel *Label4;
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormFDistr(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormFDistr *FormFDistr;
//---------------------------------------------------------------------------


TFormFDistr *FormFDistr;

void __fastcall ShowFormFDistr()
{
	TFormFDistr *_FDistr = new TFormFDistr(Application);
	_FDistr->Visible = false;
	_FDistr->ShowModal();
    _FDistr->Free();
}

#endif
