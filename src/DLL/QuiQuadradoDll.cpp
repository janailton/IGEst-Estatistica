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




#include "QuiDuadradoDll.h"


extern "C" 
{

	typedef double  (*_pQui_Quadrado)( double, double );
	typedef double  (*_pQui_Quadrado_Inverso)( double, double );


	_pQui_Quadrado pQui_Quadrado = NULL;
	_pQui_Quadrado_Inverso pQui_Quadrado_Inverso = NULL;

	HINSTANCE QuiQuadradoDll = NULL;


	void MostraErro()
	{
		MessageBox (0, "Erro! O arquivo \"QuiQuadradoDll.dll\" não foi encontrado \n", "Erro", MB_ICONINFORMATION);
	}

	int Inicia_Dll_QuiQuadrado()
	{
		QuiQuadradoDll = LoadLibrary("QuiQuadradoDll.dll");
		if ( QuiQuadradoDll == NULL )
		{
			MostraErro();
			return 0;
		}


		pQui_Quadrado = (_pQui_Quadrado)  GetProcAddress( QuiQuadradoDll , "Qui_Quadrado");
		pQui_Quadrado_Inverso = (_pQui_Quadrado_Inverso)  GetProcAddress( QuiQuadradoDll , "Qui_Quadrado_Inverso");

		if ( pQui_Quadrado == NULL || pQui_Quadrado_Inverso == NULL  )
		{
			MostraErro();
			return 0;
		}

	
		return ( 1 );
	}

	int Dll_QuiQuadrado_Iniciada = Inicia_Dll_QuiQuadrado();

}

double Qui_Quadrado( double v , double x )
{
	if ( Dll_QuiQuadrado_Iniciada ) return pQui_Quadrado( v , x );
	else
	{
		MostraErro();
		return 0;
	}
}

double Qui_Quadrado_Inverso( double v , double p )
{
	if ( Dll_QuiQuadrado_Iniciada ) return pQui_Quadrado_Inverso( v , p );
	else
	{
		MostraErro();
		return 0;
	}
}