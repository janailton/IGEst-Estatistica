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





#include "Poisson.h"

long double Poisson( long double x,  long double lambda)
{

		long double numerador = pow( e, - lambda) * pow( lambda, x);
		long double denominador = Fatorial( x );

		if(denominador !=0)
			return numerador / denominador;

		else return -1;

}


long double poisson_normal( long double x, long double lambda )
{

	return Poisson ( x , lambda );	

}

long double poisson_x_maior( long double x, long double lambda )
{
	
	long double soma = 0.0;
	
	for (int i = 0; i <= x; i++)
		soma += Poisson ( i , lambda );

	return ( 1 - soma );	

}

long double poisson_x_menor( long double x, long double lambda )
{
	long double soma = 0.0;
	
	for (int i = 0; i < x; i++)
		soma += Poisson ( i , lambda );

	return soma;	

}

long double poisson_x_maior_ou_igual( long double x, long double lambda )
{
	long double soma = 0.0;
	
	for (int i = 0; i < x; i++)
		soma += Poisson ( i , lambda );

	return ( 1 - soma );	

}

long double poisson_x_menor_ou_igual( long double x, long double lambda )
{
	
	long double soma = 0.0;
	
	for (int i = 0; i <= x; i++)
		soma += Poisson ( i , lambda );

	return soma;	

}