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





#include "tStudentDll.h"


extern "C" 
{

	typedef double  (*_pT_Student)( int, double );
	typedef double  (*_pT_Student_Inverso)( int, double );


	_pT_Student pT_Student = NULL;
	_pT_Student_Inverso pT_Student_Inverso = NULL;

	HINSTANCE TStudentDll = NULL;


	void MostraErro_tStudent()
	{
		MessageBox (0, "Erro! O arquivo \"T-StudentDll.dll\" não foi encontrado \n", "Erro", MB_ICONINFORMATION);
	}

	int Inicia_Dll_tStudent()
	{
		TStudentDll = LoadLibrary("T-StudentDll.dll");
		if ( TStudentDll == NULL )
		{
			MostraErro_tStudent();
			return 0;
		}


		pT_Student = (_pT_Student)  GetProcAddress( TStudentDll , "Student");
		pT_Student_Inverso = (_pT_Student_Inverso)  GetProcAddress( TStudentDll , "Student_Inverso");

		if ( pT_Student == NULL || pT_Student_Inverso == NULL  )
		{
			MostraErro_tStudent();
			return 0;
		}

	
		return ( 1 );
	}

	int Dll_tStudent_Iniciada = Inicia_Dll_tStudent();

}


double tStudent ( int k , double x )
{


	if ( Dll_tStudent_Iniciada ) return pT_Student( k , x );
	else
	{
		MostraErro_tStudent();
		return 0;
	}
}
double tStudent_Inverso ( int k , double p )
{


	if ( Dll_tStudent_Iniciada ) return pT_Student_Inverso( k , p );
	else
	{
		MostraErro_tStudent();
		return 0;
	}
}