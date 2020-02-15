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



#include "DistribF.h"


DistribF::DistribF(void) 
{
	pDistribF = NULL;
	pDistribF_Direita = NULL;
	pInverso_DistribF = NULL;
	DistribFDll = NULL;

	Init();

}

DistribF::~DistribF(void)
{
	if( DistribFDll != NULL )
		FreeLibrary( DistribFDll );
}

int DistribF::Init()
{
	
	DistribFDll = LoadLibrary("DistribfDll.dll");
	if( DistribFDll == NULL )
	{
		Erro( "Erro! O arquivo \"DistribfDll.dll\" não foi encontrado \n" );
		return 0;
	}

	pDistribF = (_pDistribF) GetProcAddress( DistribFDll , "DistribF" );
	pDistribF_Direita = (_pDistribF_Direita) GetProcAddress( DistribFDll , "DistribF_Direita" );
	pInverso_DistribF = (_pInverso_DistribF) GetProcAddress( DistribFDll , "Inverso_DistribF" );

	if( pDistribF == NULL || pDistribF_Direita == NULL || pInverso_DistribF == NULL )
	{
		Erro( "Erro! Não foi possível carregar as rotinas do aplicativo \"DistribfDll.dll\"" );
		return 0;
	}

	return 1;
}

void DistribF::Erro( string msg )
{
	MessageBox (0, msg.c_str() , "Erro", MB_ICONINFORMATION);
}

double DistribF::getDistribF(int a, int b, double x)
{
	if( pDistribF != NULL ) 
		return pDistribF( a , b , x );
	else
	{
		Erro( "Erro! Não foi possível carregar as rotinas do aplicativo \"DistribfDll.dll\"" );
		return 0;
	}


}
double DistribF::getDistribF_Direita (int a, int b, double x)
{
	if( pDistribF_Direita != NULL )
	return pDistribF_Direita( a , b , x );
	else
	{
		Erro( "Erro! Não foi possível carregar as rotinas do aplicativo \"DistribfDll.dll\"" );
		return 0;
	}
}
double DistribF::getInverso_DistribF(int a, int b, double y)
{
	if( pInverso_DistribF != NULL )
	return pInverso_DistribF( a , b , y );
	else
	{
		Erro( "Erro! Não foi possível carregar as rotinas do aplicativo \"DistribfDll.dll\"" );
		return 0;
	}
}