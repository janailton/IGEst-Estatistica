//    Copyright (C) 2020 - 2009 José Janaílton da Silva <josejanailton@gmail.com>
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
#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <sysutils.hpp>
#include <windows.hpp>
#include <messages.hpp>
#include <sysutils.hpp>
#include <classes.hpp>
#include <graphics.hpp>
#include <controls.hpp>
#include <forms.hpp>
#include <dialogs.hpp>
#include <stdctrls.hpp>
#include <buttons.hpp>
#include <extctrls.hpp>
#include <menus.hpp>
#include <Classes.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdExplicitTLSClientServerBase.hpp>
#include <IdFTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ToolWin.hpp>


#include "../../update/UpdaterThread.h"
#include "IGEST_API.h"
#include "IGEstPluginManager.h"

#include <string>;
using namespace std;

class TUpdater;

//---------------------------------------------------------------------------
class __declspec(uuid("{F3216EAE-4102-41AA-97C5-05777243F60F}")) TMainForm : public TForm, public IGEST_API::IGEstBase/* classe abstrat em "IGEST_API.h" */
{
__published:
	TMainMenu *MainMenu;
	TMenuItem *EstatsticaDescritiva1;
    TMenuItem *DistribuiodePoisson1;
    TMenuItem *DistribuioBinomial1;
    TMenuItem *DistribuioHipergeomtrica1;
    TMenuItem *N1;
    TMenuItem *Fechar1;
    TMenuItem *Ajuda1;
    TMenuItem *Sobre1;
    TStatusBar *StatusBar1;
    TMenuItem *DistribuioNormalPadro1;
    TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *DistribuioTdeStudent1;
	TMenuItem *DistribuibQui;
	TMenuItem *mnLognormal;
	TMenuItem *mnDistribExponencial;
	TMenuItem *mnuAnalise;
	TMenuItem *estedeHiptese1;
	TMenuItem *estedeHipteseMdiaComDesvioPadroConhecido1;
	TMenuItem *estedeHipteseMdiaComDesvioPadroDesconhecido1;
	TMenuItem *DistribuioF1;
	TMenuItem *N4;
	TMenuItem *nmuRegressCorr;
	TMenuItem *mnAtualiza;
	TMenuItem *N5;
	TMenuItem *AnlisedeVarinciaANOVAcomumfator1;
	TMenuItem *TestedeIndependncia1;
	TMenuItem *menu_estimativa_intervalar;
	TMenuItem *N6;
	TPanel *Panel1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TButton *Button14;
	TButton *Button15;
	TButton *Button16;
	TButton *Button17;
	TImageList *ImageList1;
	TMenuItem *estedeHipteseJarqueBera1;
	TButton *Button18;
	TPanel *Panel2;
	TPanel *Panel3;
	TMenuItem *Ferramentas1;
	TMenuItem *Configuraes1;
	TMenuItem *MaterialParaEstudo1;
	TMenuItem *ArquivosdaWikipdia1;
	TMenuItem *SubMenuPlugins;
	TMenuItem *PginadoProjeto1;
    void __fastcall Fechar1Click(TObject *Sender);
    void __fastcall DistribuioBinomial1Click(TObject *Sender);
    void __fastcall DistribuioHipergeomtrica1Click(TObject *Sender);
    void __fastcall DistribuiodePoisson1Click(TObject *Sender);
    void __fastcall Sobre1Click(TObject *Sender);
	void __fastcall EstatsticaDescritiva1Click(TObject *Sender);
	void __fastcall DistribuioNormalPadro1Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall DistribuioTdeStudent1Click(TObject *Sender);
	void __fastcall DistribuibQuiClick(TObject *Sender);
	void __fastcall mnLognormalClick(TObject *Sender);
	void __fastcall mnDistribExponencialClick(TObject *Sender);
	void __fastcall estedeHiptese1Click(TObject *Sender);
	void __fastcall estedeHipteseMdiaComDesvioPadroConhecido1Click(TObject *Sender);
	void __fastcall estedeHipteseMdiaComDesvioPadroDesconhecido1Click(TObject *Sender);
	void __fastcall DistribuioF1Click(TObject *Sender);
	void __fastcall nmuRegressCorrClick(TObject *Sender);
	void __fastcall mnAtualizaClick(TObject *Sender);
	void __fastcall AnlisedeVarinciaANOVAcomumfator1Click(TObject *Sender);
	void __fastcall TestedeIndependncia1Click(TObject *Sender);
	void __fastcall menu_estimativa_intervalarClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall MD51Click(TObject *Sender);
	void __fastcall SobreoAutor1Click(TObject *Sender);
	void __fastcall estedeHipteseJarqueBera1Click(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall Configuraes1Click(TObject *Sender);
	void __fastcall ArquivosdaWikipdia1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall PginadoProjeto1Click(TObject *Sender);



private:        // private user declarations

	TUpdater * ThreadUpd;

public:         // public user declarations
	IGEstPluginManager *IGEstPluginManager1;
	virtual __fastcall TMainForm(TComponent* Owner);
    void __fastcall ThreadTerminated(TObject *Sender);
	__IMP_IGEstBase__(__MAIN_FORM_ID__)  // macro de "IGEST_API.h"
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;


/*

void __fastcall ShowMainForm( string FormName)
{
	Application->Initialize();
	Application->MainFormOnTaskBar = true;
	TMainForm *FormPrincipal = NULL;
	Application->CreateForm(__classid(TMainForm), &FormPrincipal);
	FormPrincipal->Caption = FormName.c_str();
	FormPrincipal->Icon = Application->Icon;
	Application->Run();

	if(FormPrincipal != NULL)
		delete FormPrincipal;


}

*/
//---------------------------------------------------------------------------
#endif
