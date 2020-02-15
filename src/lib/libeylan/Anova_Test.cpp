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


#include "Anova_Test.h"

#include <sstream>


#include "../../lib/alglib/include/fdistr.h"
#pragma comment( lib, "../../lib/alglib/alglib_cbuilder.lib" )

Anova_Test::Anova_Test(Anova_Matriz MatAnova, int tratamentos, int repeticoes )
:	m_mat(MatAnova), m_tratamentos(tratamentos), m_repeticoes(repeticoes)
{
	m_glTratamentos = m_tratamentos - 1;
	m_glResiduos = m_tratamentos*(m_repeticoes - 1);
	m_glTotal = (m_tratamentos * m_repeticoes) - 1;  
}

Anova_Test::~Anova_Test(void)
{
}

int Anova_Test::glTratamentos()
{
	return m_glTratamentos;
}

int Anova_Test::glResiduos()
{
	return m_glResiduos;
}

int Anova_Test::glTotal()
{
	return m_glTotal;
}

double Anova_Test::SQTotal()
{
	double sxyq = 0; // somatório de (x*y)^2
	double qsxy = 0; // quadrado do somatório de x*y

	for( int i=0; i<m_tratamentos; i++)
		for(int j=0; j<m_repeticoes; j++)
		{
			sxyq = sxyq + m_mat[i][j];
			qsxy = qsxy + (m_mat[i][j]*m_mat[i][j]);
		}

	double resultado = qsxy - ( (sxyq*sxyq)/(m_tratamentos*m_repeticoes) );

	std::stringstream ss;
	ss << resultado;
	str_SQTotal = "Somatório dos quadrados (SQTotal): " + ss.str();

	return resultado;
}

double Anova_Test::SQTrat()
{
	double sxyq = 0;
	double sparcial = 0;
	double smedia = 0;

	for( int i=0; i<  m_tratamentos ; i++)
	{
		for( int j=0; j<m_repeticoes; j++)
		{
			sparcial = sparcial + m_mat[i][j];
			sxyq = sxyq + m_mat[i][j];
		}

		smedia = smedia + (sparcial*sparcial); // + ((sparcial*sparcial)/m_repeticoes);
		sparcial = 0;

	}

	smedia = smedia/m_repeticoes;

	double resultado = smedia - ( (sxyq*sxyq)/(m_tratamentos*m_repeticoes) );

	std::stringstream ss;
	ss << resultado;
	str_SQTrat = "Somatório dos quadrados dos tratamentos (SQTrat): " + ss.str();

	return resultado;
}

double Anova_Test::SQRes()
{
	double resultado = SQTotal() - SQTrat();

	std::stringstream ss;
	ss << resultado;
	str_SQRes = "Somatório dos quadrados dos resíduos (SQRes): " + ss.str();

	return resultado;
}

double Anova_Test::QMTrat()
{

	double resultado = SQTrat()/(m_tratamentos-1);

	std::stringstream ss;
	ss << resultado;
	str_QMTrat = "Quadrado médio dos tratamentos (QMTrat): " + ss.str();

	return resultado;
}

double Anova_Test::QMRes()
{

	double resultado = SQRes()/(m_tratamentos*(m_repeticoes-1));

	std::stringstream ss;
	ss << resultado;
	str_QMRes = "Quadrado médio dos resíduos (QMRes): " + ss.str();

	return resultado;
}

double Anova_Test::FCalculado()
{

	double resultado = QMTrat() / QMRes();

	std::stringstream ss;
	ss << resultado;
	str_FCalculado = "valor F calculado: " + ss.str();


	return resultado;
}
double Anova_Test::FTabelado(double confianca)
{

	double resultado = invfdistribution(m_glTratamentos, m_glResiduos, confianca/100);

	std::stringstream ss;
	ss << resultado;
	str_FTabelado = "valor F tabelado: " + ss.str();

	return resultado;
}

std::string Anova_Test::Solucao_Teste(double confianca)
{
	glTratamentos();
	glResiduos();
	glTotal();
	SQTotal();
	SQTrat();
	SQRes();
	QMTrat();
	QMRes();

	solucao_teste = "solução: ";

	if(FCalculado() > FTabelado(confianca))
		solucao_teste += "Rejeitar a hipótese nula";
	else solucao_teste += "Deixar de rejeitar a hipótese nula";

	std::stringstream ss;
	ss << "G. L. Tratamentos: " << glTratamentos() << "\n"
	   << "G. L. Resíduos: " << glResiduos()  << "\n"
	   <<str_SQTotal << "\n" << str_SQTrat  << "\n" << str_SQRes  << "\n" << str_QMTrat
	   << "\n" << str_QMRes  << "\n" << str_FCalculado << "\n" << str_FTabelado << "\n"
	   << solucao_teste;

	return ss.str();
}

