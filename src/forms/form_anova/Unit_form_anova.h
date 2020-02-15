//    Copyright (C) 2010, 2009 José Janaílton da Silva <josejanailton@gmail.com>
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

#ifndef Unit_form_anovaH
#define Unit_form_anovaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>

#include "Unit_form_nova_tabela.h"

//---------------------------------------------------------------------------
class TForm_anova : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGridAnova;
	TButton *btnCalcular;
	TEdit *EditConfianca;
	TLabel *Label1;
	void __fastcall btnCalcularClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations

	Tabela m_tabela;
public:		// User declarations
	__fastcall TForm_anova(TComponent* Owner, Tabela _tabela);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_anova *Form_anova;
//---------------------------------------------------------------------------

void __fastcall Show_Form_anova()
{

	TForm_nova_tabela *frm_nova_tabela = new  TForm_nova_tabela(Application);
	frm_nova_tabela->ShowModal();
	Tabela tabela = frm_nova_tabela->tabela_info;
	frm_nova_tabela->Free();

	if ((tabela.linha != 0) && (tabela.coluna != 0) )
	if ((tabela.linha >= 2) && (tabela.coluna >=2) )
	{

		TForm_anova *frm_anova = new TForm_anova(Application, tabela);
		frm_anova->ShowModal();
		frm_anova->Free();
	}
	else
		ShowMessage("A tabela deve ter, no mínimo, duas linhas e duas colunas.");
}

#endif
