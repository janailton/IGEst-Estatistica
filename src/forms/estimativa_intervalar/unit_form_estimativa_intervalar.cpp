//    Copyright (C) 2010, 2009 José Janaílton da Silva
//	<josejanailton@gmail.com>
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

#include "unit_form_estimativa_intervalar.h"
#include "../../lib/libeylan/Estimativa_Intervalar.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_Estimativa_Intervalar *Form_Estimativa_Intervalar;
//---------------------------------------------------------------------------
__fastcall TForm_Estimativa_Intervalar::TForm_Estimativa_Intervalar(TComponent* Owner)
	: TForm(Owner)
{
	TabbedNotebook1->PageIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm_Estimativa_Intervalar::btnProporcaoClick(TObject *Sender)
{
	try
	{
		double prop = EditProporcao->Text.ToDouble();
		int n = EditPropN->Text.ToInt();
		double alfa = EditPropAlfa->Text.ToDouble();

		if(prop < 0 || prop > 1)
		{
			ShowMessage("O valor da proporção deve estar entre 0 e 1");
			return;
		}

		if(alfa < 1 || alfa > 99)
		{
			ShowMessage("O valor da confiança deve estar entre 1 e 99");
			return;
		}

		alfa = alfa/100;
		AnsiString texto = Estimativa_Intervalar::proporcao( prop, n, alfa ).c_str();
		ShowMessage(texto);

	}
	catch( EConvertError * e )
	{
		ShowMessage("Um ou mais dígitos inseridos não são números válidos.");
	}
	catch( Exception * e)
	{
		ShowMessage("Os dados fornecidos estão inconsistentes.\n"
					+ AnsiString("Detalhes: ") + e->ToString());
	}
	catch( ... )
	{
		ShowMessage("Os dados fornecidos estão inconsistentes.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_Estimativa_Intervalar::btnMDPCClick(TObject *Sender)
{
	try
	{
		double media = EditMediaDPC->Text.ToDouble();
		double desvio_padrao = EditVarianciaDPC->Text.ToDouble();
		int n = EditNDPC->Text.ToInt();
		double alfa = EditAlfaDPC->Text.ToDouble();

		if(alfa < 1 || alfa > 99)
		{
			ShowMessage("O valor da confiança deve estar entre 1 e 99");
			return;
		}

		alfa = alfa/100;
		AnsiString texto = Estimativa_Intervalar::media_com_desvio_padrao_conhecido( media , desvio_padrao , n , alfa ).c_str();
		ShowMessage(texto);

	}
	catch( EConvertError * e )
	{
		ShowMessage("Um ou mais dígitos inseridos não são números válidos.");
	}
	catch( Exception * e)
	{
		ShowMessage("Os dados fornecidos estão inconsistentes.\n"
					+ AnsiString("Detalhes: ") + e->ToString());
	}
	catch( ... )
	{
		ShowMessage("Os dados fornecidos estão inconsistentes.");
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm_Estimativa_Intervalar::btnMDPDClick(TObject *Sender)
{
	try
	{
		double media = EditMediaMDPD->Text.ToDouble();
		double desvio_padrao = EditVarianciaMDPD->Text.ToDouble();
		int n = EditNMDPD->Text.ToInt();
		double alfa = EditAlfaMDPD->Text.ToDouble();

		if(alfa < 1 || alfa > 99)
		{
			ShowMessage("O valor da confiança deve estar entre 1 e 99");
			return;
		}

		alfa = alfa/100;
		AnsiString texto = Estimativa_Intervalar::media_com_desvio_padrao_desconhecido( media , desvio_padrao , n , alfa ).c_str();
		ShowMessage(texto);

	}
	catch( EConvertError * e )
	{
		ShowMessage("Um ou mais dígitos inseridos não são números válidos.");
	}
	catch( Exception * e)
	{
		ShowMessage("Os dados fornecidos estão inconsistentes.\n"
					+ AnsiString("Detalhes: ") + e->ToString());
	}
	catch( ... )
	{
		ShowMessage("Os dados fornecidos estão inconsistentes.");
	}
}
//---------------------------------------------------------------------------

