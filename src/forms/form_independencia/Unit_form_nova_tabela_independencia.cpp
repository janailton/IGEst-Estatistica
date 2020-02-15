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

#include <vcl.h>
#pragma hdrstop

#include "Unit_form_nova_tabela_independencia.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_nova_tabela_independencia *Form_nova_tabela_independencia;
//---------------------------------------------------------------------------
__fastcall TForm_nova_tabela_independencia::TForm_nova_tabela_independencia(TComponent* Owner)
	: TForm(Owner)
{
	cancelado = false;

}
//---------------------------------------------------------------------------
void __fastcall TForm_nova_tabela_independencia::btnConfirmarClick(TObject *Sender)
{
	try
	{

		tabela_info.coluna = this->EditRepet->Text.ToInt();
		tabela_info.linha = this->EditTrat->Text.ToInt();
		Close();

	}
	catch( EConvertError * e )
	{
		ShowMessage("Um ou mais dígitos inseridos não são números válidos.");
	}
	catch (Exception * e)
	{
		ShowMessage("Erro: os dados fornecidos estão inconsistentes\n" + e->ToString());
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm_nova_tabela_independencia::btnCancelarClick(TObject *Sender)
{

	cancelado = true;
	Close();

}
//---------------------------------------------------------------------------
