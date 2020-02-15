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

#ifndef Unit_form_nova_tabelaH
#define Unit_form_nova_tabelaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------

struct Tabela
{
	int coluna;
	int linha;

	Tabela()
	{
	   coluna = 0;
	   linha = 0;
	};

};

class TForm_nova_tabela : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TEdit *EditRepet;
	TLabel *Label2;
	TEdit *EditTrat;
	TButton *btnConfirmar;
	TButton *btnCancelar;
	void __fastcall btnConfirmarClick(TObject *Sender);
	void __fastcall btnCancelarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm_nova_tabela(TComponent* Owner);

public:
	Tabela tabela_info;
	bool cancelado;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_nova_tabela *Form_nova_tabela;
//---------------------------------------------------------------------------

void __fastcall Show_Form_Nova_Tabela(Tabela & tabela)
{
	TForm_nova_tabela *frm_nova_tabela = new  TForm_nova_tabela(Application);
	frm_nova_tabela->ShowModal();

	tabela =  frm_nova_tabela->tabela_info;
	frm_nova_tabela->Free();

}

#endif
