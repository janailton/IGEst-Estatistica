//    Copyright (C) 2010, 2009 José Janaílton da Silva <josejanailton@gmail.com>
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

#include "Unit_form_independencia.h"
#include "Unit_resultado_independencia.h"
#include "../../lib/libeylan/Independencia_Teste.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_independencia *Form_independencia;
//---------------------------------------------------------------------------
__fastcall TForm_independencia::TForm_independencia(TComponent* Owner, Tabela_independencia _tabela)
	: TForm(Owner)
{
	m_tabela = _tabela;
}
//---------------------------------------------------------------------------
void __fastcall TForm_independencia::btnCalcularClick(TObject *Sender)
{

	try
	{

		IndMatriz matriz_independencia(StringGridIndependencia->RowCount -1 , StringGridIndependencia->ColCount - 1);
		matriz_independencia = 0;

		try
		{

		for( int i=1; i<StringGridIndependencia->RowCount; i++)  //
			for( int j=1; j<StringGridIndependencia->ColCount; j++)  //StringGridAnova->ColCount
				matriz_independencia[i-1][j-1] = StringGridIndependencia->Cells[j][i].ToDouble();
		}
		catch( ...)
		{
			throw  Exception("Um ou mais dígitos inseridos na tabela não são válidos");
        }

		if(EditConfianca->Text.IsEmpty())
        	{
				ShowMessage("Não foi inserido o valor do nível de confiança");
				return ;
            }
		double alfa = this->EditConfianca->Text.ToDouble();

		alfa = alfa / 100;

		if((alfa <=0) || (alfa >=1))
		{
			throw Exception("O nível de confiança deve ser maior do que zero e menor do que 100");
			return;
        }

		Independencia_Teste teste_independencia(matriz_independencia, StringGridIndependencia->RowCount -1, StringGridIndependencia->ColCount - 1);

		AnsiString texto = "Graus de liberdade: " +  AnsiString(teste_independencia.gl()) + "\n\n";


		for( int j=1; j<StringGridIndependencia->ColCount; j++)
				texto += "Total da coluna " + AnsiString( j ) + ": " + AnsiString(teste_independencia.total_coluna(j-1)) + "\n";
		for(int i=1; i<StringGridIndependencia->RowCount; i++)
			texto += "Total da linha " + AnsiString( i ) + ": " + AnsiString(teste_independencia.total_linha(i-1)) + "\n";

		texto += "\nTotal geral: "  +  AnsiString( teste_independencia.total_geral() ) + "\n\n";



		IndMatriz matriz_esperada = teste_independencia.matriz_esperada();
		texto += "Frequência esperada: \n\n";

		for( int i=1; i<StringGridIndependencia->RowCount; i++)  //
		{
			for( int j=1; j<StringGridIndependencia->ColCount; j++)
			{
				texto += FormatFloat("#0.000", matriz_esperada[i-1][j-1]) + "\t";
			}
			texto += "\n";
		}

		texto += "\n\n";

		texto += "Qui-Quadrado calculado: " + FormatFloat("#0.000", teste_independencia.qteste_calculado()) + "\n";
		texto += "Qui-Quadrado tabelado: " + FormatFloat("#0.000",teste_independencia.qtabelado(alfa)) + "\n";
		texto += "Solução do teste: "  + AnsiString(teste_independencia.resultado_do_teste(alfa).c_str()) + "\n";

		//ShowMessage(texto);
		 Show_Form_resultado_independencia(texto);

	}
	catch( EConvertError * e )
	{
		ShowMessage("Um ou mais dígitos inseridos não são números válidos.");
	}
	catch( Exception * e)
	{
		ShowMessage("Os dados fornecidos estão inconsistentes\nDetalhes: " + e->ToString());
	}
	catch( ... )
	{
		ShowMessage("Os dados fornecidos estão inconsistentes.");
	}


}
//---------------------------------------------------------------------------
void __fastcall TForm_independencia::FormShow(TObject *Sender)
{

	if ((m_tabela.linha < 1) || (m_tabela.coluna <1) )
	{
		this->Close();
	}
	else
	{
		StringGridIndependencia->RowCount = m_tabela.linha + 1;
		StringGridIndependencia->ColCount = m_tabela.coluna + 1;

		for( int i=1; i<StringGridIndependencia->RowCount; i++)
			StringGridIndependencia->Cells[0][i]= "L" + AnsiString(i);

		for( int j=1; j<StringGridIndependencia->ColCount; j++)
			StringGridIndependencia->Cells[j][0]= "C" + AnsiString(j);
	}

}
//---------------------------------------------------------------------------
