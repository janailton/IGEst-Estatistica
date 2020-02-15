//    Copyright (C) 2010, 2009 José Janaílton da Silva
//		<josejanailton@gmail.com>
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


#ifndef __ESTIMATIVA_INTERVALAR_H__
#define __ESTIMATIVA_INTERVALAR_H__

#include <string>


class Estimativa_Intervalar
{
public:
	Estimativa_Intervalar(void);
	~Estimativa_Intervalar(void);

	static std::string media_com_desvio_padrao_conhecido( double media , double desvio_padrao , int numero_elentos , double alpha );
	static std::string media_com_desvio_padrao_desconhecido( double media , double desvio_padrao , int numElementos , double alpha );
	static std::string proporcao( double proporcao_amostra, int numElementos, double alpha ); 



};


#endif
