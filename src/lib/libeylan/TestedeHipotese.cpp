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




#include "TestedeHipotese.h"

const char * msg_ACEITAR_hipotese_nula = "Não se deve rejeitar a hipótese nula";
const char * msg_REJEITAR_hipotese_nula = "Rejeitar a hipótese nula";


TestedeHipotese::TestedeHipotese(void)
{
	return;
}

TestedeHipotese::~TestedeHipotese(void)
{
	return;
}

string TestedeHipotese::media_com_desvio_padrao_conhecido( double hipotese_nula , double media , double desvio_padrao , int numero_elentos , double alpha , TipodeTeste tipodeteste )
{
	try
	{
		if( tipodeteste == UNILATERAL_ESQUERDA )
		{

			double z0 , z1;
		
			z0 = Normal_Inversa( 1 - alpha );
			z1 = (media - hipotese_nula) / ( desvio_padrao / sqrt( double( numero_elentos ) ) );
			ostringstream os;

			os << "Z(0): " << z0 << endl;
			os << "Z(1): " << z1 << endl;

			if ( z1 > z0 )
				os << "\n" << msg_ACEITAR_hipotese_nula;
			else os << "\n" << msg_REJEITAR_hipotese_nula;
				
			return os.str() ;


		}
		else
		if( tipodeteste == UNILATERAL_DIREITA )
			{

				double z0 , z1; 
				
				z0 = Normal_Inversa( alpha );
				z1 = (media - hipotese_nula) / ( desvio_padrao / sqrt( double( numero_elentos ) ) );
				ostringstream os;

				os << "Z(0): " << z0 << endl;
				os << "Z(1): " << z1 << endl;

				if ( z1 < z0 )
					os << "\n" << msg_ACEITAR_hipotese_nula;
				else os << "\n" << msg_REJEITAR_hipotese_nula;
						
				return os.str() ;


			}
			else // tipodeteste == BILATERAL
				{
	

						double z0_a , z0_b , z1 , delta; 

						delta = (1 - alpha) / 2;
						
						z0_b = Normal_Inversa( alpha + delta );
						z0_a = Normal_Inversa( 1 - (alpha + delta) );

						z1 = (media - hipotese_nula) / ( desvio_padrao / sqrt( double( numero_elentos ) ) );
						ostringstream os;

						os << "Z(0) (limite inferior): " << z0_a << endl;
						os << "Z(0) (limite superior): " << z0_b << endl;
						os << "Z(1): " << z1 << endl;

						if ( z1 > z0_a && z1 < z0_b )
								os << "\n" << msg_ACEITAR_hipotese_nula;
							else os << "\n" << msg_REJEITAR_hipotese_nula;
									
						return os.str() ;

				}
	}
	catch(...)
	{
		return string("Erro! Os dados fornecidos estão inconsistentes.");
	}
	
}


/*
/// @param: 
			hipotese_nula : hipótese nula;
			media : média das amostras;
			desvio_padrao : desvio padrão das amostras;
			numElementos : número de elementos da amostra;
			alpha : conhecido como o "valor crítico" em estatística, ou nível de significâncoa
					seu valor está no intervalo entre 0 e 1;
			tipodeteste : contém o tipo de teste ( UNILATERAL_ESQUERDA ou UNILATERAL_DIREITA ou BILATERAL );
	@return:
			retorna uma string com o resultado do teste;

	exemplo:
			hipotese_nula = 4200;
			media = 4000;
			desvio_padrao = 200;
			numElementos = 10;
			alpha = 0.90;
			tipodeteste = UNILATERAL_ESQUERDA;
			Solução:
					t1 = -3.16228
					t0 = -1.38303
					deve-se rejeitar hipotese_nula
			
*/

string TestedeHipotese::media_com_desvio_padrao_desconhecido( double hipotese_nula, double media, double desvio_padrao, int numElementos, double alpha, TipodeTeste tipodeteste)
{
	try
	{
		if( tipodeteste == UNILATERAL_ESQUERDA )
		{


			double t0, t1;

			// Se o número de elementos da amostra for maior do que trinta,
			// calcula-se o valor crítico pela normal
			if(numElementos <= 30)
			{
				t0 = tStudent_Inverso( numElementos - 1, 1- alpha );
			}
			else
			{
				t0 = Normal_Inversa( 1 - alpha );
			}

			t1 = (media - hipotese_nula) / ( desvio_padrao / sqrt( double(numElementos) ) );

			ostringstream os;

			os << "t(0): " << t0 << endl;
			os << "t(1): " << t1 << endl;

			if ( t1 > t0 )
				os << "\n" << msg_ACEITAR_hipotese_nula;
			else os << "\n" << msg_REJEITAR_hipotese_nula;
					
		return os.str() ;

		}
		else
			if( tipodeteste == UNILATERAL_DIREITA )
				{

					double t0, t1; 

					if(numElementos <= 30)
					{
						t0 = tStudent_Inverso( numElementos - 1, alpha );
					}
					else
					{
						t0 = Normal_Inversa( alpha );
					}

					t1 = (media - hipotese_nula) / ( desvio_padrao / sqrt( double(numElementos) ) );

					ostringstream os;

					os << "t(0): " << t0 << endl;
					os << "t(1): " << t1 << endl;

					if ( t1 < t0 )
						os << "\n" << msg_ACEITAR_hipotese_nula;
							else os << "\n" << msg_REJEITAR_hipotese_nula;
					return os.str() ;


			}
			else // tipodeteste == BILATERAL
				{
					double t0_a, t0_b, t1 , delta; 						
										
					delta = (1 - alpha) / 2;

					if(numElementos <= 30)
					{
						t0_b = tStudent_Inverso( numElementos - 1 , alpha + delta );
						t0_a = tStudent_Inverso( numElementos - 1 , 1 - (alpha + delta) );
					}
					else
					{
						t0_b = Normal_Inversa( alpha + delta );
						t0_a = Normal_Inversa( 1 - (alpha + delta) );
                    }


					t1 = (media - hipotese_nula) / ( desvio_padrao / sqrt( double(numElementos) ) );


					ostringstream os;

					os << "t(0) (limite inferior): " << t0_a << endl;
					os << "t(0) (limite superior): " << t0_b << endl;
					os << "t(1): " << t1 << endl;

					if ( t1 > t0_a && t1 < t0_b )
						os << "\n" << msg_ACEITAR_hipotese_nula;
							else os << "\n" << msg_REJEITAR_hipotese_nula;
					
					return os.str() ;

				}
	}
	catch(...)
	{
		return string("Erro! Os dados fornecidos estão inconsistentes.");
	}

}

string TestedeHipotese::proporcao( double hipotese_nula , double proporcao_amostra, int numElementos, double alpha, TipodeTeste tipodeteste)
{

	try
	{

		if( tipodeteste == UNILATERAL_ESQUERDA )
		{
			double h0, h1;
						
			h0 = Normal_Inversa( 1 - alpha );
			h1 = ( proporcao_amostra - hipotese_nula ) / sqrt( hipotese_nula*( 1 - hipotese_nula )/numElementos);

			ostringstream os;

			os << "Z(H0): " << h0 << "\n";
			os << "Z(H1): " << h1 << "\n";

			if ( h1 > h0 )
				os << "\n" << msg_ACEITAR_hipotese_nula;
			else os << "\n" << msg_REJEITAR_hipotese_nula;
				
			return os.str() ;
		}
		else
		if( tipodeteste == UNILATERAL_DIREITA )
			{
				double h0, h1;
						
				h0 = Normal_Inversa( alpha );
				h1 = ( proporcao_amostra - hipotese_nula ) / sqrt( hipotese_nula*( 1 - hipotese_nula )/numElementos);

				ostringstream os;

				os << "Z(H0): " << h0 << "\n";
				os << "Z(H1): " << h1 << "\n";

				if ( h1 < h0 )
					os << "\n" << msg_ACEITAR_hipotese_nula;
				else os << "\n" << msg_REJEITAR_hipotese_nula;
				
				return os.str() ;

			}
		else // tipodeteste == BILATERAL
		{
			double h0_a, h0_b, h1,delta;

			delta = (1 - alpha) / 2;

			h0_b = Normal_Inversa( alpha + delta );
			h0_a = Normal_Inversa( 1 - (alpha + delta) );
						
			h1 = ( proporcao_amostra - hipotese_nula ) / sqrt( hipotese_nula*( 1 - hipotese_nula )/numElementos);

			ostringstream os;
			os << "Z(H0) (limite inferior): " << h0_a << endl;
			os << "Z(H0) (limite superior): " << h0_b << endl;
			os << "Z(H1): " << h1 << endl;

			if ( h1 > h0_a && h1 < h0_b )
				os << "\n" << msg_ACEITAR_hipotese_nula;
				else os << "\n" << msg_REJEITAR_hipotese_nula;
									
		return os.str() ;

		}
	}
	catch(...)
	{
		return string("Erro! Os dados fornecidos estão inconsistentes.");
	}

}