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




#include "DistribNormal.h"

// Todos os valores de Z aqui representam a probabilidade equivalente à
// área à esquerda de Z no gráfico

long double Normal( long double z )
{
	long double t = (z > 0) ? z : (- z);
	long double p = 1 - pow((1 + (t * (0.0498673470 + t * (0.0211410061 + t *
		(0.0032776263 + t * (0.0000380036 + t * (0.0000488906 + t *
		0.0000053830))))))), -16) / 2;

	return (z > 0) ? p : (1 - p);
}

long double Normal_Inversa( long double p )
{

	long double t = (p > .5) ? (1 - p) : p;
	long double s = sqrt(-2.0 * log(t));
	long double a = 2.515517 + (0.802853 * s) + (0.010328 * s * s);
	long double b = 1 + (1.432788 * s) + (0.189269 * s * s) + (0.001308 * s * s * s);
	long double u = s - (a / b);
	return (p < .5) ? (- u) : u;

}

long double Normal_Padrao( long double x, long double Media, long double DesvioPadrao )
{
	
	if ( DesvioPadrao > 0 )
	{
		long double zPadrao = ( x - Media ) / DesvioPadrao;
		return Normal( zPadrao );
	}
	else return -1.0;

}


long double normal_entre_ab( long double limInferior, long double limSuperior)
{
	return ( Normal( limSuperior ) - Normal( limInferior ) );
}