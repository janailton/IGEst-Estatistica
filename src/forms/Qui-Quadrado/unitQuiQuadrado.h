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

#ifndef unitQuiQuadradoH
#define unitQuiQuadradoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <TabNotBk.hpp>
//---------------------------------------------------------------------------



class TFormQuiQuadrado : public TForm
{
__published:	// IDE-managed Components
	TTabbedNotebook *TabbedNotebook1;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TEdit *EditGLInv;
	TEdit *EditP;
	TGroupBox *GroupBox3;
	TButton *BtnCalculaInv;
	TEdit *EditResultadoInv;
	TGroupBox *GroupBox4;
	TGroupBox *GroupBox6;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *EditGL;
	TEdit *EditX;
	TLabel *Label4;
	TLabel *Label5;
	TButton *btnCalcula;
	TEdit *EditResultado;
	TLabel *Label6;
    void __fastcall BtnCalculaInvClick(TObject *Sender);
	void __fastcall btnCalculaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormQuiQuadrado(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormQuiQuadrado *FormQuiQuadrado;
//---------------------------------------------------------------------------


TFormQuiQuadrado *FormQuiQuadrado;

void __fastcall ShowFormQuiQuadrado()
{
    TFormQuiQuadrado *FormQuiQuadrado = new TFormQuiQuadrado(Application);
	FormQuiQuadrado->Visible = false;
	FormQuiQuadrado->ShowModal();
	FormQuiQuadrado->Free();
}

#endif
