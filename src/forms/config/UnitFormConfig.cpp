//    Copyright (C) 2019 José Janaílton da Silva <josejanailton@gmail.com>
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

#pragma hdrstop

#include "UnitFormConfig.h"
#include <System.IniFiles.hpp>
#include "../../Versão/UnitVersao.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TIGestConfig::TIGestConfig()
{
try{

#ifdef USE_LOCKBOX
		bf = new TLbBlowfish(NULL);
		rjan = new TLbRijndael(NULL);
		ConfigHash = get_hash();
		strHash = get_str_hash();
		UnicodeString _data;
		for (int i = 0; i < ConfigHash.size; i++) {
			_data = _data + ConfigHash.data[i];
		}
		bf->GenerateKey(_data);
        rjan->GenerateKey(_data);
#endif

	if (_mConfigListNames == NULL) {
		_mConfigListNames = new TStringList();
	}
	
	load_mapSettings();
	set_config("AppIGESTHomePath",inipath());
	set_config("APPNAME",IGEST_VERSAO::APPNAME.c_str());
	set_config("VERSAO",IGEST_VERSAO::VERSAO.c_str());
	set_config("AUTOR",IGEST_VERSAO::AUTOR.c_str());
	set_config("SITE",IGEST_VERSAO::SITE.c_str());



	set_config("UPDATE_SERVER",IGEST_VERSAO::UPDATE_SERVER.c_str());
	set_config("UPDATE_INFO",IGEST_VERSAO::UPDATE_INFO.c_str());
	//set_config("GNULICENSE",IGEST_VERSAO::GNULICENSE.c_str());
	set_config("DEFAULT_STYLE",IGEST_CONFIG::DEFAULT_STYLE.c_str());
	set_config("NORMAL_STYLE",IGEST_CONFIG::NORMAL_STYLE.c_str());
	set_config("GEST_EXE",ParamStr(0));


#ifdef USE_LOCKBOX
	set_config("eylan-hardware-api-guid",eylan_hardware_guid());
	set_config("eylan-hadware-api-cpu-id", eylan_get_cpu_id());
	set_config("USER_SERIAL", rjan->EncryptString(UnicodeString("IGEst-3.9.5")+ eylan_hardware_guid()  + eylan_get_cpu_id()));
#endif
	UpdateFont();
} catch (...){
}


}

TIGestConfig::~TIGestConfig()
{
	save_all_settings();
    delete IGEST_CONFIG::ConfigFont;

#ifdef USE_LOCKBOX
        rjan->Free();
		bf->Free();
#endif
}

UnicodeString TIGestConfig::inipath()
{
	UnicodeString s = GetHomePath()+"\\IGEst\\IGEst.ini";
	if (FileExists(s) == false)
	{
		MkDir(GetHomePath()+"\\IGEst\\");
	}

	return s;
}

void TIGestConfig::save_form(TForm *FormToSave)
{
	TIniFile *ini;
	ini = new TIniFile( inipath() );
	ini->WriteInteger(FormToSave->Name,"Top",FormToSave->Top);
	ini->WriteInteger(FormToSave->Name,"Height",FormToSave->Height);
	ini->WriteInteger(FormToSave->Name,"Left",FormToSave->Left);
	ini->WriteInteger(FormToSave->Name,"Width",FormToSave->Width);
	ini->WriteBool(FormToSave->Name,"Maximized", FormToSave->WindowState == wsMaximized);
	delete ini;
}
void TIGestConfig::load_form(TForm *FormToLoad)
{
	//if (FileExists(ChangeFileExt( Application->ExeName, ".ini" )) == false) return;

	TIniFile *ini;
	ini = new TIniFile( inipath() );
	FormToLoad->Top = ini->ReadInteger(FormToLoad->Name,"Top", FormToLoad->Top);
	FormToLoad->Height = ini->ReadInteger(FormToLoad->Name,"Height",FormToLoad->Height);
	FormToLoad->Left = ini->ReadInteger(FormToLoad->Name,"Left",FormToLoad->Left);
	FormToLoad->Width = ini->ReadInteger(FormToLoad->Name,"Width",FormToLoad->Width);
	bool _WindowState = ini->ReadBool(FormToLoad->Name,"Maximized", FormToLoad->WindowState == wsMaximized );

	if (_WindowState)
	{
		FormToLoad->WindowState = wsMaximized;
	} else FormToLoad->WindowState = wsNormal;

	delete ini;
}

void TIGestConfig::save_string(AnsiString file, AnsiString text)
{
    inipath();
	TIniFile *ini;
	ini = new TIniFile( GetHomePath()+"\\IGEst\\" + file );
	ini->WriteString("Texto","info",text);
	delete ini;


}

TIGestConfig *_IGEstConfig = NULL;

TIGestConfig* TIGestConfig::GetIGestConfig(){
	if ( _IGEstConfig == NULL)
	{
		_IGEstConfig = new TIGestConfig();
	}
    return _IGEstConfig;
}



// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
UnicodeString TIGestConfig::GetRegistryPath(void)
{
	UnicodeString acPath = "Software\\" + Application->Name + "\0";


	return (acPath);
}


// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
UnicodeString TIGestConfig::GetRegistry(const UnicodeString pacName)
{
	TRegistry *Reg = new  TRegistry();
	Reg->RootKey = IGEST_CONFIG::IGEST_REG_RootKey;
	UnicodeString _result;

	if(!Reg->KeyExists(IGEST_CONFIG::IGEST_REG_SubKey))
	{
		//
	}

	Reg->Access = KEY_READ;
	bool openResult = Reg->OpenKey(IGEST_CONFIG::IGEST_REG_SubKey, true);

	if(!openResult)
	{
		//MessageDlg("Unable to create key! Exiting.", mtError, TMsgDlgButtons() << mbOK, 0);
		return _result;
	}

	_result = Reg->ReadString(pacName);

	Reg->CloseKey();

	delete Reg;
	return _result;


	return _result;
}

UnicodeString TIGestConfig::GetRegistrySettings(const UnicodeString pacName)
{
	TRegistry *Reg = new  TRegistry();
	Reg->RootKey = IGEST_CONFIG::IGEST_REG_RootKey;
	UnicodeString _result;

	if(!Reg->KeyExists(IGEST_CONFIG::IGEST_REG_SETTINGS_SubKey))
	{
		//
	}

	Reg->Access = KEY_READ;
	bool openResult = Reg->OpenKey(IGEST_CONFIG::IGEST_REG_SubKey, true);

	if(!openResult)
	{
		//MessageDlg("Unable to create key! Exiting.", mtError, TMsgDlgButtons() << mbOK, 0);
		return _result;
	}

	_result = Reg->ReadString(pacName);

	Reg->CloseKey();

	delete Reg;
	return _result;


	return _result;
}



// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool TIGestConfig::SetRegistry(const UnicodeString pacName, const UnicodeString pacValue)
{
	bool bRes = false;

	TRegistry *Reg = new  TRegistry();
	Reg->RootKey = IGEST_CONFIG::IGEST_REG_RootKey;

	if(!Reg->KeyExists(IGEST_CONFIG::IGEST_REG_SubKey))
	{
		//
	}

	Reg->Access = KEY_WRITE;
	bool openResult = Reg->OpenKey(IGEST_CONFIG::IGEST_REG_SubKey, true);

	if(!openResult)
	{
		//MessageDlg("Unable to create key! Exiting.", mtError, TMsgDlgButtons() << mbOK, 0);
		return false;
	}

	Reg->WriteString(pacName,pacValue);

	Reg->CloseKey();

	delete Reg;
	return true;
}

// ----------------------------------------------------------------------------------------

bool TIGestConfig::SetRegistrySettings(const UnicodeString pacName, const UnicodeString pacValue)
{
	bool bRes = false;

	TRegistry *Reg = new  TRegistry();
	Reg->RootKey = IGEST_CONFIG::IGEST_REG_RootKey;

	if(!Reg->KeyExists(IGEST_CONFIG::IGEST_REG_SubKey))
	{
		//
	}

	Reg->Access = KEY_WRITE;
	bool openResult = Reg->OpenKey(IGEST_CONFIG::IGEST_REG_SETTINGS_SubKey, true);

	if(!openResult)
	{
		//MessageDlg("Unable to create key! Exiting.", mtError, TMsgDlgButtons() << mbOK, 0);
		return false;
	}

	Reg->WriteString(pacName,pacValue);

	Reg->CloseKey();

	delete Reg;
	return true;
}


// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void TIGestConfig::set_config(UnicodeString info, UnicodeString val)
{
	map<UnicodeString,UnicodeString>::iterator itr;
	bool _return = false;

	for (itr = mapSettings.begin(); itr != mapSettings.end(); ++itr) {
		if (itr->first == info) 
		{
			itr->second = val;
			_return = true;
			break;
		}
	}

	SetRegistrySettings(info, val);

	if (_return) 
	{
		return;
	}

	mapSettings.insert(pair<UnicodeString,UnicodeString>(info,val));
	save_mapSettings();
}
void TIGestConfig::save_mapSettings()
{
	inipath();
	TIniFile *ini;
	ini = new TIniFile( GetHomePath()+"\\IGEst\\" + "IGEst.Settings.ini" );

	map<UnicodeString,UnicodeString>::iterator itr;

	for (itr = mapSettings.begin(); itr != mapSettings.end(); ++itr) {
		ini->WriteString("Settings",itr->first, itr->second);
		SetRegistrySettings(itr->first, itr->second);
	}

	delete ini;
}

void TIGestConfig::load_mapSettings()
{
	inipath();
	TIniFile *ini;
	ini = new TIniFile( GetHomePath()+"\\IGEst\\" + "IGEst.Settings.ini" );
	TStringList* Keys = new TStringList;
	TStringList* Values = new TStringList;
	ini->ReadSection("Settings", Keys);

	for (int i=0; i<Keys->Count; i++)
	{
		Values->Add(ini->ReadString("Settings", Keys->Strings[i], ""));
		_mConfigListNames->Add(Keys->Strings[i]); 
    }

	for (int j=0; j<Values->Count; j++)
	{
	//ShowMessage("[" + Keys->Strings[j] + "]  :  [" +  Values->Strings[j] + "]");  // para depuração
		set_config(Keys->Strings[j], Values->Strings[j]);
	}

	delete Values;
	delete Keys;
	delete ini;

}

const UnicodeString TIGestConfig::get_app_style()
{
	UnicodeString _Result;

	if (!get_config("AppLayout", _Result)) 
	{
		set_config("AppLayout", IGEST_CONFIG::DEFAULT_STYLE);
	}

	get_config("AppLayout", _Result);
	return _Result;
}

void TIGestConfig::set_app_style(UnicodeString app_style)
{
	set_config("AppLayout", app_style);
}

bool TIGestConfig::get_config(UnicodeString info, UnicodeString &val)
{
	bool _Result = false;
	map<UnicodeString,UnicodeString>::iterator itr;

	for (itr = mapSettings.begin(); itr != mapSettings.end(); ++itr) {
		if (itr->first == info) 
		{
			val = itr->second;
			_Result = true;
			break;
		}
	}

	return _Result;
}

void TIGestConfig::save_all_settings()
{
	save_mapSettings();
#ifdef USE_LOCKBOX
	save_to_xml();
#endif
}

TStringList *TIGestConfig::get_config_list_names()
{
	if (_mConfigListNames == NULL) {
		_mConfigListNames = new TStringList();
	}
	return _mConfigListNames;
}

void TIGestConfig::UpdateFont()
{
	if (IGEST_CONFIG::ConfigFont == NULL) {
		IGEST_CONFIG::ConfigFont = new TFont();
		UnicodeString iname, tam = "0", icolor = "0";
		get_config("StatisticalFontName", iname);
		get_config("StatisticalFontSize", tam);
		get_config("StatisticalFontColor", icolor);
        IGEST_CONFIG::ConfigFont->Name = iname;
		IGEST_CONFIG::ConfigFont->Size = StrToInt(tam);
		IGEST_CONFIG::ConfigFont->Color = StrToInt(icolor); 
	}
}


#ifdef USE_LOCKBOX
void TIGestConfig::save_to_xml()
{

	Xml::Xmlintf::_di_IXMLDocument xml;
	IXMLNode *RootNode, *CurNode;

	CoInitialize(0);

	xml = NewXMLDocument();
	xml->Active = true;
	xml->Options << doNodeAutoIndent;
	RootNode = xml->AddChild("XML");

	CurNode =  RootNode->AddChild("Settings");

	map<UnicodeString,UnicodeString>::iterator itr;

	for (itr = mapSettings.begin(); itr != mapSettings.end(); ++itr) {
		CurNode->Attributes[itr->first] =  itr->second;
	}

	UnicodeString xmlfilepath = ExtractFilePath(inipath())+"IGEst.Settings.xml";
	xml->SaveToFile(xmlfilepath);
	xml->Release();

	CoUninitialize();

}
#endif
