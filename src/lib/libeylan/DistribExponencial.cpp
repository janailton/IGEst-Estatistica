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



#include "DistribExponencial.h"

const double DistribExponencial::NUMERO_NEPERIANO_E	= 2.718281828;

DistribExponencial::DistribExponencial(void)
{
}

DistribExponencial::~DistribExponencial(void)
{
}

double DistribExponencial::Exponencial( double x , double lambda )
{
	return pow( NUMERO_NEPERIANO_E , -lambda * x );
}

double DistribExponencial::Exponencial_entre_ab( double a , double b , double lambda )
{
	return Exponencial( a , lambda ) - Exponencial( b , lambda );
}

double DistribExponencial::Exponencial_entre_zero_e_x( double x , double lambda )
{
	return 1 - Exponencial( x , lambda );
}
