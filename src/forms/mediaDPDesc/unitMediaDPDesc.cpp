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

#include <vcl.h>
#pragma hdrstop

#include "unitMediaDPDesc.h"

#include "../../lib/libeylan/TestedeHipotese.h"

#include <sstream>
#include <string>
using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormMediaDPDesc::TFormMediaDPDesc(TComponent* Owner)
    : TForm(Owner)
{

}

//---------------------------------------------------------------------------

void __fastcall TFormMediaDPDesc::Button1Click(TObject *Sender)
{

	try
	{
		double h0 = EditH0->Text.ToDouble();
		double media = EditMedia->Text.ToDouble();
		double desvio = EditDesvio->Text.ToDouble();
		double n = EditN->Text.ToDouble();
		double alpha = EditAlpha->Text.ToDouble();


		if( alpha<1 || alpha>99)
		{
			ShowMessage("O valor do n�vel de confian�a deve estar entre 1 e 99");
			return;
		}

		if( n <1)
		{
			ShowMessage("O valor de N deve ser maior ou igual a 1");
			return;
		}


		alpha = alpha/100;


		// Unilateral � esquerda
		if (RadioButton1->Checked)
		{
			AnsiString resultado = TestedeHipotese::media_com_desvio_padrao_desconhecido(h0, media, desvio, n , alpha , UNILATERAL_ESQUERDA).c_str() ;
			MemoResultado->Lines->Clear();
			MemoResultado->Lines->Text = resultado;
		}

		// Unilateral � direita
		else   if (RadioButton2->Checked)
		{
			AnsiString resultado = TestedeHipotese::media_com_desvio_padrao_desconhecido(h0, media, desvio, n , alpha , UNILATERAL_DIREITA).c_str() ;
			MemoResultado->Lines->Clear();
			MemoResultado->Lines->Text = resultado;
		}
		// Bilateral
		else if (RadioButton3->Checked)
		{
			AnsiString resultado = TestedeHipotese::media_com_desvio_padrao_desconhecido(h0, media, desvio, n , alpha , BILATERAL).c_str() ;
			MemoResultado->Lines->Clear();
			MemoResultado->Lines->Text = resultado;
		}

	}
	catch( EConvertError * e )
	{
		ShowMessage("Um ou mais d�gitos inseridos n�o s�o n�meros v�lidos.");
	}
	catch( Exception * e)
	{
		ShowMessage("Os dados fornecidos est�o inconsistentes.\n\n"
					+ AnsiString("Detalhes: ") + e->ToString());
	}
	catch( ... )
	{
		ShowMessage("Os dados fornecidos est�o inconsistentes.");
	}

}
//---------------------------------------------------------------------------

void __fastcall TFormMediaDPDesc::btnAjudaClick(TObject *Sender)
{
	const char msg_mdpd[] = "OBS: para amostras com N <= 30 � utilizado o valor t de uma tabela T de Student\n"
							"Para amostras com N > 30 � utilizado o valor z de uma tabela normal";
	ShowMessage( msg_mdpd );
}

