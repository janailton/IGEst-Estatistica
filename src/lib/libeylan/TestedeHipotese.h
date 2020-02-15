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




#ifndef _TESTE_DE_HIPOTESE_H_
#define _TESTE_DE_HIPOTESE_H_

#include <cmath>
#include <string>
#include <sstream>
using namespace std;

#include "../DLL/tStudentDll.h"
#include "../libeylan/DistribNormal.h"

enum TipodeTeste
	{
		UNILATERAL_ESQUERDA,
		UNILATERAL_DIREITA,
		BILATERAL,
	};

class TestedeHipotese
{
public:
	TestedeHipotese(void);
	
	static string media_com_desvio_padrao_conhecido( double hipotese_nula , double media , double desvio_padrao , int numero_elentos , double alpha , TipodeTeste tipodeteste );
	static string media_com_desvio_padrao_desconhecido( double hipotese_nula , double media , double desvio_padrao , int numElementos , double alpha , TipodeTeste tipodeteste);
	static string proporcao( double hipotese_nula , double proporcao_amostra, int numElementos, double alpha, TipodeTeste tipodeteste); 

public:
	~TestedeHipotese(void);
};


#endif
