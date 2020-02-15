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

#include <vcl.h>
#pragma hdrstop

#include "unitNormal_Padrao.h"

#include "../../lib/libeylan/DistribNormal.h"

#include <sstream>
#include <string>
using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormNormalPadrao::TFormNormalPadrao(TComponent* Owner)
    : TForm(Owner)
{

}

//---------------------------------------------------------------------------

void __fastcall TFormNormalPadrao::Button1Click(TObject *Sender)
{
	try
	{

		double x = EditX->Text.ToDouble();
		double media = EditMedia->Text.ToDouble();
		double DesvioPadrao = EditDesvioPadrao->Text.ToDouble();

		if(DesvioPadrao == 0)
		{
			ShowMessage("O desvio padrão não pode ser igual a zero.");
			return;
        }

		if (RadioButton1->Checked)
		{
			double resultado = Normal_Padrao( x , media , DesvioPadrao );
			EditResultado->Text = FormatFloat("#0.0000", resultado);
		}

		else   if (RadioButton2->Checked)
		{

			double resultado = 1 - Normal_Padrao( x , media , DesvioPadrao );
			EditResultado->Text = FormatFloat("#0.0000", resultado);
		}
	}
	catch( EConvertError * e )
	{
		ShowMessage("Um ou mais dígitos inseridos não são números válidos.");
	}
	catch( Exception * e)
	{
		ShowMessage("Os dados fornecidos estão inconsistentes.\n\n"
					+ AnsiString("Detalhes: ") + e->ToString());
	}
	catch( ... )
	{
		ShowMessage("Os dados fornecidos estão inconsistentes.");
	}

}
//---------------------------------------------------------------------------

