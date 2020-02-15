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


#include "Estimativa_Intervalar.h"

#include <cmath>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "DistribNormal.h"
#include "tStudent.h"

Estimativa_Intervalar::Estimativa_Intervalar(void)
{
}

Estimativa_Intervalar::~Estimativa_Intervalar(void)
{
}

string Estimativa_Intervalar::media_com_desvio_padrao_conhecido( double media , double desvio_padrao , int numero_elentos , double alpha )
{
	try
	{


		double erro , z0;
		ostringstream os;

		double omega = (1 - alpha)/2;
		
		z0 = Normal_Inversa( omega + alpha );
		erro = z0*(desvio_padrao/sqrt(double(numero_elentos)));

		os << "Intervalo: " << media - erro << " a "  << media + erro;
				
		return os.str() ;

	}
	catch( exception *e)
	{
		return string("Erro! Os dados fornecidos estão inconsistentes.");
	}
	catch(...)
	{
		return string("Erro! Os dados fornecidos estão inconsistentes.");
	}
	
}




string Estimativa_Intervalar::media_com_desvio_padrao_desconhecido( double media, double desvio_padrao, int numElementos, double alpha )
{

	try
	{

		double erro , z0;
		ostringstream os;

		double omega = (1 - alpha)/2;

		if(numElementos <= 30)
			z0 = tStudent_Inverso( numElementos - 1, omega + alpha );
		else
			z0 = Normal_Inversa( omega + alpha );


		erro = z0*(desvio_padrao/sqrt(double(numElementos)));

		os << "Intervalo: " << media - erro << " a "  << media + erro;
				
		return os.str() ;

	}
	catch( exception *e)
	{
		return string("Erro! Os dados fornecidos estão inconsistentes.");
	}
	catch(...)
	{
		return string("Erro! Os dados fornecidos estão inconsistentes.");
	}

}


string Estimativa_Intervalar::proporcao( double proporcao_amostra, int numElementos, double alpha )
{

	try
	{


		double erro , z0;
		ostringstream os;

		double omega = (1 - alpha)/2;
		
		z0 = Normal_Inversa( omega + alpha );
		erro = z0*sqrt( (proporcao_amostra*(1-proporcao_amostra))/numElementos  );

		os << "Intervalo: " << proporcao_amostra - erro << " a "  << proporcao_amostra + erro;
				
		return os.str() ;

	}
	catch( exception *e)
	{
		return string("Erro! Os dados fornecidos estão inconsistentes.");
	}
	catch(...)
	{
		return string("Erro! Os dados fornecidos estão inconsistentes.");
	}

}

