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

#include "unitPoisson.h"

#include "../../lib/libeylan/Poisson.h"

#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormPoisson::TFormPoisson(TComponent* Owner)
    : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TFormPoisson::Button1Click(TObject *Sender)
{
	try
	{

		double x = EditX->Text.ToDouble();
		double lambda = EditLambda->Text.ToDouble();

		if(x<0)
		{
			ShowMessage("O valor de X deve ser maior ou igual a 0");
        	return;
		}

		if(lambda <=0)
		{
			ShowMessage("O valor de Lambda deve ser maior do que 0");
        	return;
		}


		if (RadioButton1->Checked)
		{
			double resultado = poisson_normal( x , lambda );
			EditResultado->Text = FormatFloat("#0.0000", resultado);
		}

		else   if (RadioButton2->Checked)
		{
			double resultado = poisson_x_maior( x , lambda );
			EditResultado->Text = FormatFloat("#0.0000", resultado);
		}

		else if (RadioButton3->Checked)
		{
			double resultado = poisson_x_menor( x , lambda );
			EditResultado->Text = FormatFloat("#0.0000", resultado);
		}

		else if (RadioButton4->Checked)
		{
			double resultado = poisson_x_maior_ou_igual( x , lambda );
			EditResultado->Text = FormatFloat("#0.0000", resultado);
		}

		else if (RadioButton5->Checked)
		{
			double resultado = poisson_x_menor_ou_igual( x , lambda );
			EditResultado->Text = FormatFloat("#0.0000", resultado);
		}
	}
	catch( exception * e )
	{
		ShowMessage("Um ou mais dígitos inseridos não são números válidos.");
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
	catch( EOverflow * e)
	{
		ShowMessage("o cálculo não pôde ser realizado porque o processamento gerou um número grande demais, ou fora do dominio da função");
	}
	catch( ... )
	{
		ShowMessage("Os dados fornecidos estão inconsistentes.");
	}

}
//---------------------------------------------------------------------------


