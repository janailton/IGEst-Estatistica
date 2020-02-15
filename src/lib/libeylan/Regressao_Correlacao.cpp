//    Copyright (C) 2010, 2009  José Janaílton da Silva
//					<josejanailton@gmail.com>
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


#include "Regressao_Correlacao.h"

#include <stdexcept>
#include <cmath>


// Compilação condicional para o C++ Builder
// Somente para tratamento de exceção com VCL

#ifdef __BCCBUILDER__
#include <SysUtils.hpp>
#endif

Regressao_Correlacao::Regressao_Correlacao(void)
{
}

Regressao_Correlacao::~Regressao_Correlacao(void)
{
}

void Regressao_Correlacao::Add( double x, double y)
{
	pares.push_back(Pares( x, y));
}
void Regressao_Correlacao::remover_pares()
{
	pares.clear();
}

double Regressao_Correlacao::b0()
{

	double n = pares.size();
	double sx =0, sy=0;

	for(size_t i=0; i<pares.size(); i++)
	{
		sx += pares[i].X;
		sy += pares[i].Y;
	}

	double numerador = sy- (b1()*sx);

	if(n == 0)
	{
		#ifdef __BCCBUILDER__
			throw Exception("Erro: divisão por zero.\nConfira os dados e tente novamente");
		#else
			throw std::logic_error("Erro: divisão por zero.\nConfira os dados e tente novamente");
		#endif
	}
	else return (numerador / n);

	return -1; // retorna -1 se ocorrer um erro
}

double Regressao_Correlacao::b1()
{
	double n = pares.size();
	double sx =0, sy=0, sxy=0;
	double sxq = 0;

	for(size_t i=0; i<pares.size(); i++)
	{
		sx += pares[i].X;
		sy += pares[i].Y;
		sxy += pares[i].X * pares[i].Y;
		sxq += pares[i].X * pares[i].X;
	}

	double numerador = n*sxy - (sx*sy);
	double denominador = n*sxq - (sx*sx);

	if(denominador == 0)
	{
		#ifdef __BCCBUILDER__
			throw Exception("Erro: divisão por zero.\nConfira os dados e tente novamente");
		#else
			throw std::logic_error("Erro: divisão por zero.\nConfira os dados e tente novamente");
		#endif
	}
	else return (numerador / denominador);

	return -1; // retorna -1 se ocorrer um erro

}

double Regressao_Correlacao::coeficiente_correlacao()
{


	double sx =0, sy =0;  ///! somatório de X e Y
	double sxy=0;		  ///! somatório de X*Y
	double sxq=0, syq=0;  ///! somatório de X^2 e Y^2, respectivamente

	double n = pares.size();

	for(size_t i=0; i<pares.size(); i++)
	{
		sx = sx + pares[i].X;
		sy = sy + pares[i].Y;
		sxy = sxy + (pares[i].X * pares[i].Y);
		sxq = sxq + (pares[i].X * pares[i].X);
		syq = syq + (pares[i].Y * pares[i].Y);

	}


	double numerador = n*sxy - (sx*sy);
	double denominador = std::sqrt( n*sxq - (sx*sx) ) * std::sqrt( n*syq - (sy*sy));

	if(denominador == 0)
	{
		#ifdef __BCCBUILDER__
			throw Exception("Erro: divisão por zero.\nConfira os dados e tente novamente");
		#else
			throw std::logic_error("Erro: divisão por zero.\nConfira os dados e tente novamente");
		#endif
	}
	else return (numerador / denominador);

	return -1; // retorna -1 se ocorrer um erro

}

double Regressao_Correlacao::coeficiente_determinacao()
{
	double r = coeficiente_correlacao();
	return r*r;
}
