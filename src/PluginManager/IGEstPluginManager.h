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


#ifndef IGEstPluginManagerH
#define IGEstPluginManagerH
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
#include <map>
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

#include "Plugin.h"


const char TIGEst_FuncName[] = "IGEstPluginCallFunction\0";
const char TIGEstPluginVersion_FuncName[] ="Version\0";
const char TIGEstPluginName_FuncName[] = "PluginName\0";
const char TIGEstPluginDescription_FuncName[]= "PluginDescription";

typedef IGEstPlugin* __stdcall (*TIGEstFunc)();
typedef const WideChar* __stdcall (*TIGEstPluginVersion)();
typedef const WideChar* __stdcall (*TIGEstPluginName)();
typedef const WideChar* __stdcall (*TIGEstPluginDescription)();


struct PluginStruct{
	IGEstPlugin *plugin;
    TIGEstFunc igest_plugin_func;
	TIGEstPluginVersion Version;
	TIGEstPluginName  PluginName;
	TIGEstPluginDescription PluginDescription;
	UnicodeString DllName;
	HMODULE _H;
	TMenuItem *_T;
};

class IGEstPluginManager{
	private:

		std::map<UnicodeString,PluginStruct*> mapIGEstPlugins;
		//std::map<UnicodeString,IGEstPlugin*> mapIGEstPlugins;
        TMainMenu *_AppMainMenu;
		TMenuItem* m_MenuPlugin;
		IGEstPluginManager(){};
		void load_plugins();
		void load_dlls_plugins();
		void Unload_plugins();
		void __fastcall MenuClickEvent(TObject *Sender);
	public:
		IGEstPluginManager(TMainMenu* MenuPlugin);
		~IGEstPluginManager();
};


#endif
