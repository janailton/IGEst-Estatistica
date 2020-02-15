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



#ifndef __ANOVA_TEST_H__
#define __ANOVA_TEST_H__

#include "Matriz_MD.h"
#include <string>

typedef matrix<double> Anova_Matriz;

class Anova_Test
{
	public:
		Anova_Test(Anova_Matriz MatAnova, int tratamentos, int repeticoes );
		virtual ~Anova_Test(void);

		int glTratamentos();
		int glResiduos();
		int glTotal();

		double SQTotal();
		double SQTrat();
		double SQRes();
		double QMTrat();
		double QMRes();
		double FCalculado();
		double FTabelado(double confianca);
		std::string Solucao_Teste(double confianca);

	private:
		int m_tratamentos; // número de tratamentos.
		int m_repeticoes;  // número de repetições
		int m_glTratamentos; // grau de liberdade do tratamento
		int m_glResiduos;    // grau de liberdade do resíuo 
		int m_glTotal;       // grau de liberdade total

		std::string str_glTratamentos;
		std::string str_glResiduos;
		std::string str_glTotal;
		std::string solucao_teste;
		std::string str_SQTotal;
		std::string str_SQTrat;
		std::string str_SQRes;
		std::string str_QMTrat;
		std::string str_QMRes;
		std::string str_FCalculado;
		std::string str_FTabelado;

		Anova_Matriz m_mat;
};


#endif