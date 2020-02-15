//    Copyright (C) 2020 José Janaílton da Silva
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



//---------------------------------------------------------------------------

#ifndef PluginH
#define PluginH
//---------------------------------------------------------------------------

#ifdef MAKE_DLL
	#define API_EXTERN_C extern "C"
	#define EYLAN_LIB_API __declspec(dllexport)
	#define API_CALL __stdcall
#else
	#define API_EXTERN_C extern "C"
	#define EYLAN_LIB_API __declspec(dllimport)
	#define API_CALL __stdcall
#endif


class IGEstPlugin{
	public:
		virtual void API_CALL InitPlugin() = 0;
		virtual void API_CALL Run() = 0;
		virtual void API_CALL ClosePlugin() = 0;

};

/*
// Implemente a classe abastrata e as funções a seguir, exportando em uma dll
// Coloque a DLL na pasta /Plugin do igest
API_EXTERN_C EYLAN_LIB_API IGEstPlugin* API_CALL IGEstPluginCallFunction();

API_EXTERN_C EYLAN_LIB_API const WideChar* API_CALL Version();
API_EXTERN_C EYLAN_LIB_API const WideChar* API_CALL PluginName();
API_EXTERN_C EYLAN_LIB_API const WideChar* API_CALL PluginDescription();

*/



#endif
