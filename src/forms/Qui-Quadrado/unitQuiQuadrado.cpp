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

#include "unitQuiQuadrado.h"

#include "../../lib/libeylan/QuiDuadrado.h"

#include <sstream>
#include <string>
using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormQuiQuadrado::TFormQuiQuadrado(TComponent* Owner)
    : TForm(Owner)
{

}

//---------------------------------------------------------------------------

void __fastcall TFormQuiQuadrado::BtnCalculaInvClick(TObject *Sender)
{



	try
	{

		double p = EditP->Text.ToDouble();
		double glInv = EditGLInv->Text.ToDouble();

		if( glInv<1 )
		{
			ShowMessage("O valor do grau de liberdade deve ser maior ou igual a 1");
			return;
		}


		if( p< 1 || p > 100)
		{
			ShowMessage("O valor da probabilidade deve estar entre 0 e 100");
			return;
		}

		p = p /100;

		EditResultadoInv->Text = AnsiString( Qui_Quadrado_Inverso ( glInv , p ) );

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


void __fastcall TFormQuiQuadrado::btnCalculaClick(TObject *Sender)
{

	try
	{


		double x = EditX->Text.ToDouble();
		double gl = EditGL->Text.ToDouble();

		if( gl <1 )
		{
			ShowMessage("O valor do grau de liberdade deve ser maior ou igual a 1");
			return;
		}

		if( x <0 )
		{
			ShowMessage("O valor do x deve ser positivo");
			return;
		}

		EditResultado->Text = AnsiString( Qui_Quadrado( gl , x ) ) ;

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

