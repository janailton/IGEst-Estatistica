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





#ifndef __DISTRIBNORMAL_H__
#define __DISTRIBNORMAL_H__

#include <cmath>
using namespace std;


long double Normal( long double z );
long double Normal_Inversa( long double p );
long double Normal_Padrao( long double x, long double Media, long double DesvioPadrao );
long double normal_entre_ab( long double limInferior, long double limSuperior);


#endif