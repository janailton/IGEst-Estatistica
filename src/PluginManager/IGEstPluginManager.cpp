//    Copyright (C) 2020 Jos� Jana�lton da Silva
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
#pragma hdrstop
#pragma package(smart_init)
#include "IGEstPluginManager.h"
#include "IGEstLogger.h"

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>

IGEstPluginManager::IGEstPluginManager(TMainMenu* MenuPlugin)
{
	_AppMainMenu = MenuPlugin;
	m_MenuPlugin = MenuPlugin->Items->Find("Plugins");
	load_plugins();
}

IGEstPluginManager::~IGEstPluginManager()
{
	Unload_plugins();
	m_MenuPlugin->Parent->Remove(m_MenuPlugin);
	m_MenuPlugin->Free();
}

void IGEstPluginManager::load_plugins()
{
    load_dlls_plugins();
}
void IGEstPluginManager::Unload_plugins()
{
	map<UnicodeString,PluginStruct*>::iterator itr;
	for (itr = mapIGEstPlugins.begin(); itr != mapIGEstPlugins.end(); ++itr) {
		itr->second->_T->Parent->Remove(itr->second->_T);
		itr->second->_T->Free();
		FreeLibrary(itr->second->_H);
	}
}
void __fastcall IGEstPluginManager::MenuClickEvent(TObject *Sender)
{
	mapIGEstPlugins[dynamic_cast<TMenuItem*>(Sender)->Name]->plugin->InitPlugin();
	mapIGEstPlugins[dynamic_cast<TMenuItem*>(Sender)->Name]->plugin->Run();
    mapIGEstPlugins[dynamic_cast<TMenuItem*>(Sender)->Name]->plugin->ClosePlugin();
}

void IGEstPluginManager::load_dlls_plugins()
{
	UnicodeString PluginsPath = ExtractFilePath(ParamStr(0)) + "Plugins\\";
	TSearchRec fplugins;
	int i = 0;
	UnicodeString mnName = "menu_plugin";
	if (( FindFirst(PluginsPath + "*.dll", faArchive,fplugins)) ==0)
	{
		int i = 0;
		do{
			UnicodeString path = PluginsPath + fplugins.Name;
			HMODULE H = 0;
			H = LoadLibraryW(path.w_str());
			if (H)
			{
				PluginStruct *info = new PluginStruct;
				info->igest_plugin_func =(TIGEstFunc)GetProcAddress(H,TIGEst_FuncName);
				info->Version =(TIGEstPluginVersion)GetProcAddress(H,TIGEstPluginVersion_FuncName);
				info->PluginName =(TIGEstPluginName)GetProcAddress(H,TIGEstPluginName_FuncName);
				info->PluginDescription =(TIGEstPluginDescription)GetProcAddress(H,TIGEstPluginDescription_FuncName);

				TMenuItem *t = new TMenuItem(m_MenuPlugin);
				//_AppMainMenu->Items->Items[_AppMainMenu->Items->Count-1]->Add(t);
				info->plugin = info->igest_plugin_func();
				t->Name = mnName + IntToStr(i);
				t->Caption = info->PluginName();
				t->OnClick = &MenuClickEvent;
				t->Tag = i;
				t->Hint = path;
				info->DllName = path;
				info->_H = H;
				info->_T = t;
				m_MenuPlugin->Add(t);
				mapIGEstPlugins.insert(pair<UnicodeString,PluginStruct*>(info->_T->Name, info));
			}
			else ShowMessage("Erro ao carregar " +  fplugins.Name);
		  i++;
		} while (FindNext(fplugins) == 0);

	}
   FindClose(fplugins);
}



