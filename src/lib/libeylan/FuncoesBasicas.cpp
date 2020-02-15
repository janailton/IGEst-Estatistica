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



#include "FuncoesBasicas.h"

#include <stdexcept>

// Compilação condicional para o C++ Builder
// Somente para tratamento de exceção com VCL

#ifdef __BCCBUILDER__
#include <SysUtils.hpp>
#endif

long double Fatorial(long double numero)
{

	long double fat = 1;
	long double cont = numero;
	for( ; cont>=1 ; cont--)
		fat = fat*cont;

	return fat;
}

long double Binomio( long double n, long double p)
{
	
	/*
	long double aux, a, b;
	
	a = Fatorial(n);
	b = Fatorial(p);

	aux = n - p;	
	aux = Fatorial( aux );
	aux *= b;
	return a  / aux;
	*/

	long double numerador = Fatorial(n);
	long double denominador = ( Fatorial(p)*Fatorial(n-p));

	if( denominador !=0 )
		return  numerador / denominador ;

	else
	{
		#ifdef __BCCBUILDER__
			throw Exception("Erro: divisão por zero.\nConfira os dados e tente novamente");
		#else
			throw std::logic_error("Erro: divisão por zero.\nConfira os dados e tente novamente");
		#endif

    }


	 return -1;

}