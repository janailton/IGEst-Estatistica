//    Copyright (C) 2019 Jos� Jana�lton da Silva <josejanailton@gmail.com>
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

#include "form_jarquebera.h"

// alglib
#include "../../lib/alglib/include/ap.h"
#include "../../lib/alglib/include/jarquebera.h"
#include "../config/UnitFormConfig.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include <stdexcept>

//---------------------------------------------------------------------------
__fastcall Tfrm_jarque_bera::Tfrm_jarque_bera(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall Tfrm_jarque_bera::FormShow(TObject *Sender)
{

		//EditX->Text = "0,0";
		//EditY->Text = "0,0";
		EditX->SetFocus();



}
//---------------------------------------------------------------------------






void __fastcall Tfrm_jarque_bera::btnExcluirClick(TObject *Sender)
{
    ListBox1->DeleteSelected();

}
//---------------------------------------------------------------------------

void __fastcall Tfrm_jarque_bera::btnExcluirTudoClick(TObject *Sender)
{
	ListBox1->Clear();
	Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------



void __fastcall Tfrm_jarque_bera::btnAdicionarClick(TObject *Sender)
{
	try
	{
		if(EditX->Text.IsEmpty() )
			return;

		EditX->Text.ToDouble();

		ListBox1->Items->Add(EditX->Text);
		EditX->SetFocus();
	}
	catch( Exception * e )
	{
		ShowMessage( "O d�gito fornecido n�o � um n�mero ou est� inconsistente.\n"
						"Corrija e tente novamente");

	}
	catch( ... )
	{
		ShowMessage("Os dados fornecidos est�o inconsistentes.");
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_jarque_bera::btnCalcularClick(TObject *Sender)
{

	try
	{

		if (ListBox1->Items->Count < 5){
            ShowMessage("Erro: A quantidade de itens da amostra n�o pode ser menor do que 5");
            return;
		}



		double *data = new double[ListBox1->Items->Count];
		double p;
		ap::real_1d_array mat;
		mat.setlength(ListBox1->Items->Count);


		for (int i = 0; i < ListBox1->Items->Count; i++) {
		   data[i] = ListBox1->Items[0][i].ToDouble();
		}

		Memo1->Lines->Clear();

        Memo1->Lines->Add("----------------------------------");
		Memo1->Lines->Add("Dados inseridos: ");
		for (int i = 0; i < ListBox1->Items->Count; i++) {
		   Memo1->Lines->Add(data[i]);
		}

		Memo1->Lines->Add(char(13));
		Memo1->Lines->Add("----------------------------------");
		Memo1->Lines->Add("Calculando o teste de hip�tese Jarque-Bera");

		int temp = GetTickCount();

		mat.setcontent(0,16, data);
		jarqueberatest(mat,ListBox1->Items->Count,p);

		temp = GetTickCount() - temp;

        Memo1->Lines->Add(char(13));

		Memo1->Lines->Add("Resultado do Valor-P Jarque-Bera = " + FloatToStr(p));

		Memo1->Lines->Add(char(13));
		Memo1->Lines->Add("Tempo de c�lculo: " + IntToStr(temp) + " ms.");
		Memo1->Lines->Add(char(13));

		Memo1->Lines->Add("----------------------------------");
        Memo1->Lines->Add(char(13));

		bool rejeitar_hipotese = true;

		 if (( p<1 && p> 0.1 ) && RadioButton1->Checked  ){
			Memo1->Lines->Add("Resultado: Aceitar a hip�tese nula com margem de erro relativa de 1\%");
			rejeitar_hipotese = false;
		 }
		 if (( p<0.1 && p> 0.01 ) && RadioButton2->Checked)  {
			Memo1->Lines->Add("Resultado: Aceitar a hip�tese nula com margem de erro relativa de 2\%");
			rejeitar_hipotese = false;
		 }
		 if (( p<0.01 && p> 0.001 ) && RadioButton1->Checked)  {
			Memo1->Lines->Add("Resultado: Aceitar a hip�tese nula com margem de erro relativa de 6\%");
			rejeitar_hipotese = false;
		 }

		 if (rejeitar_hipotese == true) {
			AnsiString erro;

			if (RadioButton1->Checked) {
				//erro = RadioButton1->Caption;
			}
			if (RadioButton2->Checked) {
				//erro = RadioButton2->Caption;
			}
			if (RadioButton3->Checked) {
				//erro = RadioButton3->Caption;
			}
			Memo1->Lines->Add("Resultado: Rejeitar a hip�tese nula" + erro);
		 }

         delete[] data;


}
	catch( EConvertError * e )
	{
		//ShowMessage("Um ou mais d�gitos inseridos n�o s�o n�meros v�lidos.");
	}
	catch( Exception * e )
	{
		//ShowMessage( "Os dados fornecidos est�o inconsistentes.\n" "Detalhes: " + e->ToString());

	}
	catch( ... )
	{
		//ShowMessage("Os dados fornecidos est�o inconsistentes.");
	}

}
//---------------------------------------------------------------------------



void __fastcall Tfrm_jarque_bera::EditXKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if (Key == VK_RETURN) {
		this->btnAdicionar->Click();
		EditX->Clear();
		EditX->SetFocus();
	}

}
//---------------------------------------------------------------------------

void __fastcall Tfrm_jarque_bera::btnSalvarDadosClick(TObject *Sender)
{
	SaveDialog1->Filter = "Jarque-Bera Files | *.jqb";
	if (SaveDialog1->Execute()) {
		ListBox1->Items->SaveToFile(SaveDialog1->FileName + ".jqb");
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_jarque_bera::btnCarregarDadosClick(TObject *Sender)
{
    OpenDialog1->Filter = "Jarque-Bera Files | *.jqb";
	if (OpenDialog1->Execute()) {
		ListBox1->Items->LoadFromFile(OpenDialog1->FileName);

	}
}
//---------------------------------------------------------------------------

void __fastcall Tfrm_jarque_bera::FormActivate(TObject *Sender)
{
    TIGestConfig::GetIGestConfig()->UpdateFont();
	if (IGEST_CONFIG::ConfigFont != NULL)
	{
		Memo1->Font->Assign(IGEST_CONFIG::ConfigFont);
		Memo1->Font->Color = IGEST_CONFIG::ConfigFont->Color;
		Memo1->Font->Name = IGEST_CONFIG::ConfigFont->Name;
		Memo1->Font->Size = IGEST_CONFIG::ConfigFont->Size;
    }
}
//---------------------------------------------------------------------------

