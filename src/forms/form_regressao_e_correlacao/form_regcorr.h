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

#ifndef form_regcorrH
#define form_regcorrH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <Tabs.hpp>
#include <TabNotBk.hpp>
#include <Graphics.hpp>


#include <Buttons.hpp>
#include <Dialogs.hpp>

#include "../../lib/libeylan/Regressao_Correlacao.h"
#include <Grids.hpp>
#include <ValEdit.hpp>

#include <vector>

//---------------------------------------------------------------------------
class Tfrm_regressao_correlacao : public TForm
{
__published:	// IDE-managed Components
    TTabbedNotebook *TabNotebook;
    TGroupBox *GroupBox1;
    TLabel *Label1;
	TEdit *EditX;
    TLabel *Label2;
    TButton *btnAdicionar;
    TButton *btnExcluir;
    TButton *btnCalcular;
    TGroupBox *GroupBox2;
    TMemo *Memo1;
    TButton *btnExcluirTudo;
	TEdit *EditY;
	TLabel *Label3;
	TValueListEditor *VList1;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall btnExcluirClick(TObject *Sender);
    void __fastcall btnExcluirTudoClick(TObject *Sender);
	void __fastcall btnAdicionarClick(TObject *Sender);
	void __fastcall btnCalcularClick(TObject *Sender);
private:

public:		// User declarations
	__fastcall Tfrm_regressao_correlacao(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm_regressao_correlacao *frm_regressao_correlacao;
//---------------------------------------------------------------------------

Tfrm_regressao_correlacao *frm_regressao_correlacao;

void __fastcall ShowFormRegressaCorrelacao()
{
	Tfrm_regressao_correlacao *_RegCor = new Tfrm_regressao_correlacao(Application);
	_RegCor->Visible = false;
	_RegCor->ShowModal();
    _RegCor->Free();
}


#endif
