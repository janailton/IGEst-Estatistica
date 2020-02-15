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


#ifndef __DISTRIBF_H__
#define __DISTRIBF_H__

#include <windows.h>
#include <string>
using namespace std;

extern "C"
{

	typedef double (*_pDistribF)( int , int , double );
	typedef double (*_pDistribF_Direita) ( int , int , double );
	typedef double (*_pInverso_DistribF)( int , int , double );

}

class DistribF
{
public:	

	DistribF(void);
	virtual ~DistribF(void);

	virtual double getDistribF(int a, int b, double x);
	virtual double getDistribF_Direita (int a, int b, double x);
	virtual double getInverso_DistribF(int a, int b, double y);

protected:


	_pDistribF pDistribF;
	_pDistribF_Direita pDistribF_Direita;
	_pInverso_DistribF pInverso_DistribF;

	HINSTANCE DistribFDll;

	virtual int Init();
	virtual void Erro( string );

};



#endif
