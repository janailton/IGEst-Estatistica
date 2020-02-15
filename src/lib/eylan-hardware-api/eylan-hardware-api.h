//    Copyright (C) 2020 - 2009 José Janaílton da Silva
//	  <josejanailton@gmail.com>
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
//---------------------------------------------------------------------------
#include <vcl.h>
#include <tchar.h>

#ifdef MAKE_DLL
	#define API_EXTERN_C extern "C"
	#define EYLAN_LIB_API __declspec(dllexport)
	#define API_CALL __stdcall
#else
	#define API_EXTERN_C extern "C"
	#define EYLAN_LIB_API __declspec(dllimport)
	#define API_CALL __stdcall
    #pragma comment( lib, "eylan-hardware-api.lib")
#endif



