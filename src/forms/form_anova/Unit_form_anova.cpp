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

#include "Unit_form_anova.h"
#include "../../lib/libeylan/Anova_Test.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_anova *Form_anova;
//---------------------------------------------------------------------------
__fastcall TForm_anova::TForm_anova(TComponent* Owner, Tabela _tabela)
	: TForm(Owner)
{
	m_tabela = _tabela;
}
//---------------------------------------------------------------------------
void __fastcall TForm_anova::btnCalcularClick(TObject *Sender)
{

	try
	{
		Anova_Matriz matriz_anova(StringGridAnova->RowCount -1 , StringGridAnova->ColCount - 1);
		matriz_anova = 0;

		try
		{

		for( int i=1; i<StringGridAnova->RowCount; i++)  //
			for( int j=1; j<StringGridAnova->ColCount; j++)  //StringGridAnova->ColCount
				matriz_anova[i-1][j-1] = StringGridAnova->Cells[j][i].ToDouble();
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

		int alfa = this->EditConfianca->Text.ToInt();
		if(alfa <=0)
		{
			throw Exception("O nível de confiança deve ser maior do que zero");
			return;
        }

		Anova_Test teste_anova(matriz_anova, StringGridAnova->RowCount -1, StringGridAnova->ColCount - 1);
		ShowMessage(teste_anova.Solucao_Teste(alfa).c_str());
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
void __fastcall TForm_anova::FormShow(TObject *Sender)
{


	if ((m_tabela.linha < 1) || (m_tabela.coluna <1) )
	{
		this->Close();
	}
	else
	{
		StringGridAnova->RowCount = m_tabela.linha + 1;
		StringGridAnova->ColCount = m_tabela.coluna + 1;

		for( int i=1; i<StringGridAnova->RowCount; i++)
			StringGridAnova->Cells[0][i]= "Trat. " + AnsiString(i);

		for( int j=1; j<StringGridAnova->ColCount; j++)
        	StringGridAnova->Cells[j][0]= "Repet. " + AnsiString(j);
    }


}
//---------------------------------------------------------------------------
