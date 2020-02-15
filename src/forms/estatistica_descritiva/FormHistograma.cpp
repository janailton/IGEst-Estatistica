//    Copyright (C) 2020 - 2009 José Janaílton da Silva <josejanailton@gmail.com>
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

#include "FormHistograma.h"
#include "..\libeylan\ExportExcel.h"
#include "../config/UnitFormConfig.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define INVALID_NUMBER "O texto inserido não é um número válido!"

AnsiString formata_texto ( AnsiString texto, int tamanho)
{
	int len = tamanho - texto.Length();

	//ShowMessage( " tamanho da string: " + AnsiString( len ) );

	AnsiString aux = texto;

	if (len<=0)
		{
			//return texto;
			return aux.SetLength( tamanho );
		}


	for (int i = 0 ; i < (len) ; i++ )
		{
			aux +=" ";
		}

	//ShowMessage( " tamanho da string: " + AnsiString( aux.Length() ) );

   return aux;

}




//---------------------------------------------------------------------------
__fastcall TFHistograma::TFHistograma(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFHistograma::Salvar1Click(TObject *Sender)
{

	SaveDialog1->Filter = ".igest|*.igest";

    if( SaveDialog1->Execute() )
    {
        AnsiString str;
        str = SaveDialog1->FileName;

		if (ExtractFileExt(str) == ".igest" )
        {
            str.SetLength( str.Length() - 4 );
        }


		ListBox1->Items->SaveToFile( str + ".igest" );
        REDistrFreq->Lines->SaveToFile( str + "_Distrib_de_Fresqüência.rtf" );
        ChartFreqAbs->SaveToBitmapFile( str + "_Freq_Absoluta.bmp");
        ChartFreqAbsAcum->SaveToBitmapFile( str + "_Freq_Abs_Acumulada.bmp");
        ChartFreqRel->SaveToBitmapFile( str + "_Freq_Relativa.bmp");
        ChartFreqRelAcum->SaveToBitmapFile( str + "_Freq_Rel_Acumulada.bmp");

    }

}
//---------------------------------------------------------------------------


void TFHistograma::CalculaEstatistica( EstatisticaDescritiva& estatistica)
{

	AnsiString texto;

	this->REDistrFreq->Lines->Clear();
	FreqAbs->Clear();
	FreqAbsAcum->Clear();
	FreqRel->Clear();
	FreqRelAcum->Clear();




	texto = "Dados inseridos: \n" ;
	for (int i = 0, j = 0; i<estatistica.getSize(); i++, j++)
	{
		if (j>9) { texto += "\n"; j=0; }
		texto += "\t" + AnsiString( estatistica.getElement(i) );
	}


	texto += "\n\nDados ordenados: \n";
	if (!estatistica.Dados_Ordenados())
		 estatistica.Ordenar_Dados();
	for (int i = 0, j = 0; i<estatistica.getSize(); i++, j++)
	{
		if (j>9) { texto += "\n"; j=0; }
		texto += "\t" + AnsiString( estatistica.getElement(i) );
	}


	regDistribFrequencia regDistr = estatistica.Distrib_de_Frequencia();

	texto += "\n\n\n\Número de elementos: " + AnsiString( estatistica.getSize() ) + "\n";
	texto += "Amplitude total: " + AnsiString( estatistica.Amplitude_total() ) + "\n" ;
	texto += "Número de classes: " + AnsiString( estatistica.NumerodeClasses() ) + "\n";
	texto += "Amplitude da classe: " + AnsiString( estatistica.Amplitude_de_Classe() ) + "\n";
	texto += "Mediana: " + FormatFloat( "0.####", estatistica.Mediana() ) + "\n" ;
	texto += "Media: " + FormatFloat( "0.####", estatistica.Media() ) + "\n" ;
	texto += "Moda: " + FormatFloat( "0.####", estatistica.Moda() ) + "\n" ;
	texto += "Variância: " + FormatFloat( "0.####", estatistica.Variancia() ) + "\n" ;
	texto += "Desvio Padrão: " + FormatFloat( "0.####", estatistica.DesvioPadrao() ) + "\n" ;
	texto += "Coeficiente de variação(%): " + FormatFloat( "0.####", estatistica.Coeficiente_de_Variacao() ) + "\n" ;



	texto += "\n\n\t\t\t Distribuição de Frequência\n";


	texto += formata_texto ( "Classe", 25);
	texto += formata_texto ( "Ponto Médio", 20 );
	texto += formata_texto ( "Fi", 20 );
	texto += formata_texto ( "Fac" , 20 );
	texto += formata_texto ( "fi(%)", 20 );
	texto += "fac(%)\n";




    for(int i=0; i< regDistr.tamanho; i++)
    {

		texto += formata_texto( FormatFloat( "0.###",  float( regDistr.Distrib[i].LimInferior ) )
		+ " |-- "
		+ FormatFloat( "0.###", float(regDistr.Distrib[i].LimSuperior) )
		 , 30) ;


		texto += formata_texto ( FormatFloat( "0.###", float(regDistr.Distrib[i].PontoMedio) ), 20 ) ;

		texto +=  formata_texto ( FormatFloat( "0.###", float(regDistr.Distrib[i].Fi) ), 20 );

		texto += formata_texto ( FormatFloat( "0.###", float(regDistr.Distrib[i].Fac) ), 20 );


		texto += formata_texto ( FormatFloat( "0.##",  float(regDistr.Distrib[i].fi) ), 20 );

		texto += formata_texto ( FormatFloat( "0.##", float(regDistr.Distrib[i].fac) ), 20 );
		texto += "\n" ;


        // Histograma de frequência absoluta
        FreqAbs->Add( regDistr.Distrib[i].Fi, AnsiString( IntToStr( (int)regDistr.Distrib[i].LimInferior) + " a " + IntToStr( (int)regDistr.Distrib[i].LimSuperior) ) );

        // Histograma de frequência absoluta acumulada
        FreqAbsAcum->Add( regDistr.Distrib[i].Fac, AnsiString( IntToStr( (int)regDistr.Distrib[i].LimInferior) + " a " + IntToStr( (int)regDistr.Distrib[i].LimSuperior) ) );

        // Histograma de frequência relativa
        //FreqAbsAcum->Add( regDistr.Distrib[i].fi, AnsiString( IntToStr( (int)regDistr.Distrib[i].LimInferior) + " a " + IntToStr( (int)regDistr.Distrib[i].LimSuperior) ) );
        FreqRel->Add(  float(  int( regDistr.Distrib[i].fi*100 ) )/100 , AnsiString( IntToStr( (int)regDistr.Distrib[i].LimInferior) + " a " + IntToStr( (int)regDistr.Distrib[i].LimSuperior) ));

        // Histograma de frequência relativa acumulada
        //FreqRelAcum->Add( regDistr.Distrib[i].fac , FormatFloat("0.00", regDistr.Distrib[i].fac ) );
        FreqRelAcum->Add(  float(  int( regDistr.Distrib[i].fac*100 ) )/100 , AnsiString( IntToStr( (int)regDistr.Distrib[i].LimInferior) + " a " + IntToStr( (int)regDistr.Distrib[i].LimSuperior) ));

	}



	this->REDistrFreq->Lines->Text = texto;
	//this->REDistrFreq->Lines->SetText( static_cast< wchar_t *> ( texto ) );
	delete [] regDistr.Distrib;
}


void TFHistograma::AbrirnoExcel( EstatisticaDescritiva& estatistica)
{




	ExportExcel exportexcel;


	exportexcel.setText("Dados inseridos:");
	exportexcel.nextLine();
	exportexcel.nextLine();


	for (int i = 0, j = 0; i<estatistica.getSize(); i++, j++ )
	{
		if (j>9) { exportexcel.nextLine(); j=0; }
		exportexcel.setText(AnsiString( estatistica.getElement(i) ));
	}

	exportexcel.nextLine();
	exportexcel.nextLine();

	exportexcel.setText("Dados ordenados:");
	exportexcel.nextLine();
	exportexcel.nextLine();

	if (!estatistica.Dados_Ordenados())
		 estatistica.Ordenar_Dados();

	for (int i = 0, j = 0; i<estatistica.getSize(); i++, j++ )
	{
		if (j>9) { exportexcel.nextLine(); j=0; }
		exportexcel.setText(AnsiString( estatistica.getElement(i) ));
	}

	exportexcel.nextLine();
	exportexcel.nextLine();
	exportexcel.nextLine();

	regDistribFrequencia regDistr = estatistica.Distrib_de_Frequencia();

	exportexcel.setText("Número de elementos: ");
	exportexcel.setText( AnsiString( estatistica.getSize() ));
	exportexcel.nextLine();
	exportexcel.setText("Amplitude total: " ) ;
	exportexcel.setText( AnsiString( estatistica.Amplitude_total() ));
	exportexcel.nextLine();
	exportexcel.setText("Número de classes: " );
	exportexcel.setText(AnsiString( estatistica.NumerodeClasses() ));
	exportexcel.nextLine();
	exportexcel.setText("Amplitude da classe: " );
	exportexcel.setText( AnsiString( estatistica.Amplitude_de_Classe() ));
	exportexcel.nextLine();
	exportexcel.setText("Mediana: ") ;
	exportexcel.setText( FormatFloat( "0.####", estatistica.Mediana() ));
	exportexcel.nextLine();
	exportexcel.setText("Media: "  ) ;
	exportexcel.setText(FormatFloat( "0.####", estatistica.Media() ));
	exportexcel.nextLine();
	exportexcel.setText("Moda: ") ;
	exportexcel.setText( FormatFloat( "0.####", estatistica.Moda() ));
	exportexcel.nextLine();
	exportexcel.setText("Variância: " ) ;
	exportexcel.setText(FormatFloat( "0.####", estatistica.Variancia() ));
	exportexcel.nextLine();
	exportexcel.setText("Desvio Padrão: " );
	exportexcel.setText(FormatFloat( "0.####", estatistica.DesvioPadrao() ));
	exportexcel.nextLine();
	exportexcel.setText("Coeficiente de variação(%): " ) ;
	exportexcel.setText(FormatFloat( "0.####", estatistica.Coeficiente_de_Variacao() ));


	exportexcel.nextLine();
	exportexcel.nextLine();

	exportexcel.setText("Distribuição de Frequência:");

	exportexcel.nextLine();
	exportexcel.nextLine();
	exportexcel.setText("Classe");
	exportexcel.setText( "Ponto Médio");
	exportexcel.setText( "Fi" );
	exportexcel.setText( "Fac" );
	exportexcel.setText( "fi(%)");
	exportexcel.setText("fac(%)");
	exportexcel.nextLine();




    for(int i=0; i< regDistr.tamanho; i++)
    {

		exportexcel.setText( FormatFloat( "0.###",  float( regDistr.Distrib[i].LimInferior ) )+ " |-- " + FormatFloat( "0.###", float(regDistr.Distrib[i].LimSuperior) )); ;


		exportexcel.setText( FormatFloat( "0.###", float(regDistr.Distrib[i].PontoMedio) ) );
		exportexcel.setText( FormatFloat( "0.###", float(regDistr.Distrib[i].Fi) ));
		exportexcel.setText(FormatFloat( "0.###", float(regDistr.Distrib[i].Fac)));
		exportexcel.setText(FormatFloat( "0.##",  float(regDistr.Distrib[i].fi) ));
		exportexcel.setText(FormatFloat( "0.##", float(regDistr.Distrib[i].fac)));
		exportexcel.nextLine();
	}

	delete [] regDistr.Distrib;
	exportexcel.ShowExcel();

}

// eof abrir no excel ------------------------------------------



void __fastcall TFHistograma::FormShow(TObject *Sender)
{

        Edit1->SelectAll();
        //Edit1->SetFocus();
        this->TabNotebook->PageIndex = 0;


}
//---------------------------------------------------------------------------

void __fastcall TFHistograma::btnAdicionarClick(TObject *Sender)
{


        try{

			   double aux = Edit1->Text.ToDouble();

			   ListBox1->AddItem( Edit1->Text, Sender);
               Edit1->SelectAll();
               Edit1->SetFocus();

               }

            catch(...)
                 {
					   ShowMessage(INVALID_NUMBER);
                 }

        Edit1->SetFocus();

}
//---------------------------------------------------------------------------





void __fastcall TFHistograma::btnExcluirClick(TObject *Sender)
{
        ListBox1->DeleteSelected();
		Edit1->SelectAll();
        Edit1->SetFocus();    
}
//---------------------------------------------------------------------------

void __fastcall TFHistograma::btnCalcularClick(TObject *Sender)
{
     try{
        if ( (ListBox1->Items->Count) > 0)
        {

			EstatisticaDescritiva estatistica( ListBox1->Items->Count );

            for( int i = 0; i< ListBox1->Items->Count ; i++)
			{
				estatistica.Add( ListBox1->Items[0][i].ToDouble() );
            }

            this->CalculaEstatistica( estatistica );
            this->TabNotebook->PageIndex = 1;

        }
	 }

	catch( EConvertError * e )
	{
		ShowMessage(INVALID_NUMBER);
	}

	catch( ... )
	{
		ShowMessage("Os dados fornecidos estão inconsistentes.");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFHistograma::ListBox1DrawItem(TWinControl *Control,
      int Index, TRect &Rect, TOwnerDrawState State)
{
		Edit1->SelectAll();
        Edit1->SetFocus();    
}
//---------------------------------------------------------------------------


void __fastcall TFHistograma::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{

		 if (Key == VK_RETURN)
        {
            try{
					 double aux = Edit1->Text.ToDouble();

					 ListBox1->Items->Insert(0, Edit1->Text );
					 Edit1->SelectAll();
                     Edit1->SetFocus();

                }

            catch(...)
                 {
                       ShowMessage(INVALID_NUMBER);
                 }

        }


}
//---------------------------------------------------------------------------


void __fastcall TFHistograma::Abrir1Click(TObject *Sender)
{
    OpenDialog1->Filter = ".igest|*.igest";

    if (OpenDialog1->Execute() )
    {



        REDistrFreq->Lines->Clear();
        FreqAbs->Clear();
        FreqAbsAcum->Clear();
        FreqRel->Clear();
        FreqRelAcum->Clear();

        ListBox1->Items->Clear();
        ListBox1->Items->LoadFromFile( OpenDialog1->FileName  );
        btnCalcular->Click();
    }


}
//---------------------------------------------------------------------------

void __fastcall TFHistograma::btnExcluirTudoClick(TObject *Sender)
{
    ListBox1->Clear();
    REDistrFreq->Lines->Clear();
    FreqAbs->Clear();
    FreqAbsAcum->Clear();
    FreqRel->Clear();
    FreqRelAcum->Clear();

}
//---------------------------------------------------------------------------

void __fastcall TFHistograma::Novo1Click(TObject *Sender)
{
    btnExcluirTudo->Click();    
}
//---------------------------------------------------------------------------


void __fastcall TFHistograma::btnSalvarnoExcelClick(TObject *Sender)
{


			EstatisticaDescritiva estatistica( ListBox1->Items->Count );

            for( int i = 0; i< ListBox1->Items->Count ; i++)
			{
				estatistica.Add( ListBox1->Items[0][i].ToDouble() );
            }

			AbrirnoExcel( estatistica );
			//this->CalculaEstatistica( estatistica );
			//this->TabNotebook->PageIndex = 1;



}
//---------------------------------------------------------------------------




