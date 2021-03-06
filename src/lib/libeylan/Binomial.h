//    Copyright (C) 2009 Jos� Jana�lton da Silva <josejanailton@gmail.com>
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




#ifndef _BINOMIAL_H_
#define _BINOMIAL_H_

#include <cmath>
using namespace std;

long double Binomial( long double x, long double p, long double n);
long double binomial_normal( long double x, long double p , long double n );
long double binomial_x_maior( long double x, long double p , long double n );
long double binomial_x_menor( long double x, long double p , long double n );
long double binomial_x_maior_ou_igual( long double x, long double p , long double n );
long double binomial_x_menor_ou_igual( long double x, long double p , long double n );


#endif