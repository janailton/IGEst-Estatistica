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



#ifndef __DISTRIB_EXPONENCIAL_H__
#define __DISTRIB_EXPONENCIAL_H__

#include <cmath>
using namespace std;

class DistribExponencial
{
public:
	static const double NUMERO_NEPERIANO_E; 

	DistribExponencial(void);
	virtual ~DistribExponencial(void);

	// Para a área entre X e o infinito positivo
	static double Exponencial( double x , double lambda );

	// Para a área entre o intervalo a e b, onde a é o limite inferior e b o  limite superior
	static double Exponencial_entre_ab( double a , double b , double lambda );

	// Para a área entre o intervalo 0 e x
	static double Exponencial_entre_zero_e_x( double x , double lambda );
};


#endif