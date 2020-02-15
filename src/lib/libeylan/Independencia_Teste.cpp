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


#include "Independencia_Teste.h"

#include <stdexcept>
#include <cmath>

#include "QuiDuadrado.h"

Independencia_Teste::Independencia_Teste(IndMatriz ind_matriz, int lin, int col)
:	m_linha(lin), m_coluna(col), m_matriz(ind_matriz), m_total_geral(0)
{

	m_gl = (lin - 1)*(col - 1);

	for(int i=0; i<m_linha; i++)
	{
		double temp_linha = 0;
		for(int j=0; j<m_coluna; j++)
		{
			temp_linha += m_matriz[i][j];			
		}

		m_total_linha.push_back(temp_linha);
	}

	
	for(int j=0; j<m_coluna; j++)
	{
		double temp_col = 0;

		for(int i=0; i<m_linha; i++)
		{
			temp_col += m_matriz[i][j];
			m_total_geral += m_matriz[i][j];
		}

		m_total_coluna.push_back(temp_col);		
	}

	if(m_total_geral == 0)
		throw std::logic_error("O valor do total geral não pode ser igual a zero.\nOs dados fornecidos estão inconsistente.");

}

Independencia_Teste::~Independencia_Teste(void)
{
}
double Independencia_Teste::total_linha(int i) const
{
	return m_total_linha[i];
}
double Independencia_Teste::total_coluna(int j) const
{
	return m_total_coluna[j];
}
double Independencia_Teste::total_geral() const
{
	return m_total_geral;
}

int Independencia_Teste::gl() const
{
	return m_gl;
}

IndMatriz Independencia_Teste::matriz_esperada()
{
	IndMatriz matriz_esp(m_linha, m_coluna);
	matriz_esp = 0;
	
	for(int i=0; i<m_linha; i++)
		for(int j=0; j<m_coluna; j++)
			matriz_esp[i][j] = (total_linha(i)*total_coluna(j))/total_geral();


	return matriz_esp;
}

double Independencia_Teste::qteste_calculado()
{
	IndMatriz matriz_esp(matriz_esperada());
	double qteste = 0;

	for(int i=0; i<m_linha; i++)
		for(int j=0; j<m_coluna; j++)
			qteste += ( std::pow( m_matriz[i][j] - matriz_esp[i][j], 2) / matriz_esp[i][j] ) ;

	return qteste;	
}

double Independencia_Teste::qtabelado(double confianca)
{
	return Qui_Quadrado_Inverso(gl(), confianca);
}

string Independencia_Teste::resultado_do_teste(double confianca)
{
	double calculado = qteste_calculado();
	double tabelado = qtabelado(confianca);

	if(calculado < tabelado)
		return string("Deixar de rejeitar a hipótese nula");
	else
		return string("Rejeitar a hipótese nula");
}
