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

#include "unitBinomial.h"

#include "../../lib/libeylan/Binomial.h"
#include "../../lib/libeylan/ajuda.h"

#include <sstream>
#include <string>
using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


//---------------------------------------------------------------------------

const AnsiString ERRO_PROB_RESULTADO = 	"O cálculo resultou numa probabilidade fora do intervalo entre 0 e 1.\n"
										"Se o resultado não estiver ligeiramente arredondado ou não for satisfatório, os dados podem estar inconsistentes.";



__fastcall TFormBinomial::TFormBinomial(TComponent* Owner)
    : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TFormBinomial::Button1Click(TObject *Sender)
{
	try
		{

		double x = EditX->Text.ToDouble();
		double n = EditN->Text.ToDouble();
		double p = EditP->Text.ToDouble();

		if(p<0|| p>=1)
			{
 		ShowMessage("O valor de P deve estar entre 0 e 1.");
			return;
		}

		if( x > n )
		{
			ShowMessage("O valor de X deve ser menor ou igual a n");
			return;
        }

		if( x == n && n==p)
		{
			if(x==1 || x==0)
			ShowMessage("Os dados fornecidos estão inconsistentes.\n");
			return;

		}

		if (RadioButton1->Checked)
		{
			double resultado = binomial_normal( x , p , n );

			if(resultado > 1 || resultado < 0)
				ShowMessage(ERRO_PROB_RESULTADO);

			EditResultado->Text = FormatFloat("#0.0000", resultado);
		}

		else   if (RadioButton2->Checked)
		{
			double resultado = binomial_x_maior( x , p , n );

			if(resultado > 1 || resultado < 0)
				ShowMessage(ERRO_PROB_RESULTADO);

			EditResultado->Text = FormatFloat("#0.0000", resultado);
		}

		else if (RadioButton3->Checked)
		{
			double resultado = binomial_x_menor( x , p , n );

			if(resultado > 1 || resultado < 0)
				ShowMessage(ERRO_PROB_RESULTADO);

			EditResultado->Text = FormatFloat("#0.0000", resultado);
		}

		else if (RadioButton4->Checked)
		{
			double resultado = binomial_x_maior_ou_igual( x , p , n );

			if(resultado > 1 || resultado < 0)
				ShowMessage(ERRO_PROB_RESULTADO);

			EditResultado->Text = FormatFloat("#0.0000", resultado);
		}

		else if (RadioButton5->Checked)
		{
			double resultado = binomial_x_menor_ou_igual( x , p , n );

			if(resultado > 1 || resultado < 0)
				ShowMessage(ERRO_PROB_RESULTADO);

			EditResultado->Text = FormatFloat("#0.0000", resultado);
		}
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

void __fastcall TFormBinomial::btnAjudaClick(TObject *Sender)
{
	ShowMessage( ajuda(BINOMIAL).c_str() );
}
//---------------------------------------------------------------------------

