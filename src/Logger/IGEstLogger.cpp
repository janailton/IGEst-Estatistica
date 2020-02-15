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

