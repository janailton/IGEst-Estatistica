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

//---------------------------------------------------------------------------

#pragma hdrstop

#include "IGEstLogger.h"
//---------------------------------------------------------------------------

#include "../forms/config/UnitFormConfig.h"

#pragma package(smart_init)

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>

void IGEstLogger::LOG(const char* logmsg)
{

	TReplaceFlags flags1;
	UnicodeString fname = ExtractFilePath(TIGestConfig::GetIGestConfig()->inipath()) + "\\" + "log-" + StringReplace(DateToStr(Now()),"/","-",TReplaceFlags()<< rfReplaceAll << rfIgnoreCase) + ".txt";

	TStringList *f = new TStringList();
	f->Add("[log " + DateTimeToStr(Now()) + "]: " +logmsg);
	f->Add("-----------------------------------------------------------------------------------");
    f->Add("\n");

	TFileStream *FStream;
	if (FileExists(fname)) FStream = new TFileStream(fname, fmOpenReadWrite);
	else FStream = new TFileStream(fname, fmCreate);

    FStream->Seek((__int64)0,soEnd);
	f->SaveToStream(FStream);

	delete FStream;
	delete f;
}

