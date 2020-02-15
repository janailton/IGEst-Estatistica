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

#include "form_regcorr.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include <stdexcept>

//---------------------------------------------------------------------------
__fastcall Tfrm_regressao_correlacao::Tfrm_regressao_correlacao(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall Tfrm_regressao_correlacao::FormShow(TObject *Sender)
{

		//EditX->Text = "0,0";
		//EditY->Text = "0,0";
		EditX->SetFocus();
		this->TabNotebook->PageIndex = 0;


}
//---------------------------------------------------------------------------






void __fastcall Tfrm_regressao_correlacao::btnExcluirClick(TObject *Sender)
{

	if(!VList1->Cells[0][0].IsEmpty())
		VList1->DeleteRow(VList1->RowCount-1);
	Memo1->Lines->Clear();

}
//---------------------------------------------------------------------------

void __fastcall Tfrm_regressao_correlacao::btnExcluirTudoClick(TObject *Sender)
{
	while(!VList1->Cells[0][0].IsEmpty())
		VList1->DeleteRow(VList1->RowCount-1);
	Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------



void __fastcall Tfrm_regressao_correlacao::btnAdicionarClick(TObject *Sender)
{
	try
	{
		if(EditX->Text.IsEmpty() || EditY->Text.IsEmpty() )
			return;

		EditX->Text.ToDouble();
		EditY->Text.ToDouble();

		VList1->InsertRow(EditX->Text, EditY->Text, true);
		EditX->Text = "";
		EditY->Text = "";
		EditX->SetFocus();
	}
	catch( Exception * e )
	{
		ShowMessage( "O dígito fornecido não é um número ou está inconsistente.\n"
						"Corrija e tente novamente");

	}
	catch( ... )
	{
		ShowMessage("Os dados fornecidos estão inconsistentes.");
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_regressao_correlacao::btnCalcularClick(TObject *Sender)
{

	try
	{
    	Regressao_Correlacao regressao_correlacao;

		for(int i=0; i<VList1->RowCount; i++)
		{

			double x = 	VList1->Cells[0][i].ToDouble();
			double y = 	VList1->Cells[1][i].ToDouble();
			regressao_correlacao.Add(x, y);

		}

		Memo1->Lines->Clear();

		Memo1->Lines->Add( "Resultado:" );
		Memo1->Lines->Add( "Coeficente de correlação: " + FormatFloat("#0.000", regressao_correlacao.coeficiente_correlacao()) );
		Memo1->Lines->Add( "Coeficente de determinação: " + FormatFloat("#0.000", regressao_correlacao.coeficiente_determinacao()) );
		double b1 = regressao_correlacao.b1();
		if(b1>0 || b1==0)
			Memo1->Lines->Add( "Reta de regressão:  f(x) = " + FormatFloat("#0.000", regressao_correlacao.b0()) + " + " + FormatFloat("#0.000", b1) + "X" );
		else
			Memo1->Lines->Add( "Reta de regressão:  f(x) = " + FormatFloat("#0.000",regressao_correlacao.b0()) + " " + FormatFloat("#0.000",b1) + "X" );
	}
	catch( EConvertError * e )
	{
		ShowMessage("Um ou mais dígitos inseridos não são números válidos.");
	}
	catch( Exception * e )
	{
		ShowMessage( "Os dados fornecidos estão inconsistentes.\n" "Detalhes: " + e->ToString());

	}
	catch( ... )
	{
		ShowMessage("Os dados fornecidos estão inconsistentes.");
	}

}
//---------------------------------------------------------------------------



