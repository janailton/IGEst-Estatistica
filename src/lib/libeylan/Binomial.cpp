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




#include "Binomial.h"

#include "FuncoesBasicas.h"

#include <stdexcept>

// Compilação condicional para o C++ Builder
// Somente para tratamento de exceção com VCL

#ifdef __BCCBUILDER__
#include <SysUtils.hpp>
#endif

long double Binomial( long double x, long double p, long double n)
{
	try
	{
		long double aux1 = Binomio( n , x);
		long double aux2 = pow( p , x );
		long double aux3 = pow( 1- p , n-x );
		return aux1 * aux2 * aux3;
	}

	catch( ... )
	{
		#ifdef __BCCBUILDER__
			throw Exception("o valor fornecido resultou em um número muito grande\n" "ou está fora do dominio da função");
		#else
			throw std::logic_error("o valor fornecido resultou em um número muito grande\n" "ou está fora do dominio da função");
		#endif
	}

	return -1;

}


long double binomial_normal( long double x, long double p , long double n )
{

	return Binomial ( x , p , n );	

}



long double binomial_x_maior( long double x, long double p , long double n )
{
	
	long double soma = 0.0;
	
	for (int i = 0; i <= x; i++)
		soma += Binomial ( i , p , n );

	return ( 1 - soma );	

}

long double binomial_x_menor( long double x, long double p , long double n )
{
	
	long double soma = 0.0;
	
	for (int i = 0; i < x; i++)
		soma += Binomial ( i , p , n );

	return soma;	

}

long double binomial_x_maior_ou_igual( long double x, long double p , long double n )
{
	
	long double soma = 0.0;
	
	for (int i = 0; i < x; i++)
		soma += Binomial ( i , p , n );

	return ( 1 - soma );	

}

long double binomial_x_menor_ou_igual( long double x, long double p , long double n )
{
	
	long double soma = 0.0;
	
	for (int i = 0; i <= x; i++)
		soma += Binomial ( i , p , n );

	return soma;	

}