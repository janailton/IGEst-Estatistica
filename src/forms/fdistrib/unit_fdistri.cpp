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

#include "unit_fdistri.h"

#include "../../lib/alglib/include/fdistr.h"

#include <sstream>
#include <string>
using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormFDistr::TFormFDistr(TComponent* Owner)
    : TForm(Owner)
{

}

//---------------------------------------------------------------------------

void __fastcall TFormFDistr::Button1Click(TObject *Sender)
{
	try
	{
		double glnum = EditglNumerador->Text.ToInt();
		double glden = EditglDenominador->Text.ToInt();
		double alpha = EditAlpha->Text.ToDouble();

		if(glnum<1 || glden<1)
		{
			ShowMessage("O valor do grau de liberade deve ser maior ou igual a 1");
			return;
		}

		if(alpha<1 || alpha>99)
		{
			ShowMessage("O grau de confiança deve estrar entre 1 e 99");
			return;
		}

		alpha = alpha/100;


		EditResultado->Text = FormatFloat( "0.#####" , invfdistribution( glnum, glden, alpha) );
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

