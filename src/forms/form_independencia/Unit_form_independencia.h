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

#ifndef Unit_form_independenciaH
#define Unit_form_independenciaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>

#include "Unit_form_nova_tabela_independencia.h"

//---------------------------------------------------------------------------
class TForm_independencia : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGridIndependencia;
	TButton *btnCalcular;
	TEdit *EditConfianca;
	TLabel *Label1;
	void __fastcall btnCalcularClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations

	Tabela_independencia m_tabela;
public:		// User declarations
	__fastcall TForm_independencia(TComponent* Owner, Tabela_independencia _tabela);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_independencia *Form_independencia;
//---------------------------------------------------------------------------

void __fastcall Show_Form_Independencia()
{

	TForm_nova_tabela_independencia *frm_nova_tabela = new  TForm_nova_tabela_independencia(Application);
	frm_nova_tabela->ShowModal();
	Tabela_independencia tabela = frm_nova_tabela->tabela_info;
	frm_nova_tabela->Free();

	if ((tabela.linha != 0) && (tabela.coluna != 0) )
	if ((tabela.linha >= 2) && (tabela.coluna >=2) )
	{

		TForm_independencia *frm_independencia = new TForm_independencia(Application, tabela);
		frm_independencia->ShowModal();
		frm_independencia->Free();
	}
	else
		ShowMessage("A tabela deve ter, no mínimo, duas linhas e duas colunas.");
}

#endif
