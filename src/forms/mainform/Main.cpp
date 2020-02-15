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
#include <vcl.h>
#pragma hdrstop

#include "Main.h"

#include "../estimativa_intervalar/unit_form_estimativa_intervalar.h"
#include "../form_independencia/Unit_form_independencia.h"
#include "../../Versão/UnitVersao.h"
#include "../about/UnitAbout.h"
#include "../tstudent/unitTStudent.h"
#include "../Qui-Quadrado/unitQuiQuadrado.h"
#include "../binomial/unitBinomial.h"
#include "../estatistica_descritiva/FormHistograma.h"
#include "../hipergeometrica/unitHipergeometrica.h"
#include "../poisson/unitPoisson.h"
#include "../normal/unitNormal_Padrao.h"
#include "../lognormal/unitLognormal.h"
#include "../exponencial/unitDistribExponencial.h"
#include "../proporcao/unitProporcao.h"
#include "../mediaDPC/unitmediaDPC.h"
#include "../mediaDPDesc/unitMediaDPDesc.h"
#include "../fdistrib/unit_fdistri.h"
#include "../form_regressao_e_correlacao/form_regcorr.h"
#include "../form_anova/Unit_form_anova.h"
#include "../config/UnitFormConfig.h"
#include "../../update/UpdaterThread.h"
#include "../form_jarque_bera/form_jarquebera.h"
#include "../src\forms/form_opcoes/UnitFormOpcoes.h"
#include "../form_wiki/UnitFormWiki.h"



//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	ThreadUpd = new TUpdater(true);
	ThreadUpd->OnTerminate = &ThreadTerminated;
    ThreadUpd->Start();
}
//----------------------------------------------------------------------------
void __fastcall TMainForm::Fechar1Click(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::DistribuioBinomial1Click(TObject *Sender)
{
	ShowFormBinomial();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::DistribuioHipergeomtrica1Click(TObject *Sender)
{
    ShowFormHipergeometrica();    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DistribuiodePoisson1Click(TObject *Sender)
{
	ShowFormPoisson();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::Sobre1Click(TObject *Sender)
{
	ShowFormAbout( IGEST_VERSAO::APPNAME , IGEST_VERSAO::VERSAO , IGEST_VERSAO::AUTOR , IGEST_VERSAO::CONTACT , IGEST_VERSAO::GNULICENSE );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EstatsticaDescritiva1Click(TObject *Sender)
{
	ShowFormHistograma();
}

void __fastcall TMainForm::DistribuioNormalPadro1Click(TObject *Sender)
{
		ShowFormNormalPadrao();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::FormActivate(TObject *Sender)
{
    TIGestConfig::GetIGestConfig()->load_form(this);
	this->Refresh();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::DistribuioTdeStudent1Click(TObject *Sender)
{
	ShowFormTStudent();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DistribuibQuiClick(TObject *Sender)
{
	ShowFormQuiQuadrado();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::mnLognormalClick(TObject *Sender)
{
	ShowFormLognormal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::mnDistribExponencialClick(TObject *Sender)
{
	ShowFormDistribExponencial();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::estedeHiptese1Click(TObject *Sender)
{
	ShowFormProporcao();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::estedeHipteseMdiaComDesvioPadroConhecido1Click(TObject *Sender)

{
	ShowFormMediaDPC();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::estedeHipteseMdiaComDesvioPadroDesconhecido1Click(TObject *Sender)

{
	ShowFormMediaDPDesc();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DistribuioF1Click(TObject *Sender)
{
	ShowFormFDistr();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::nmuRegressCorrClick(TObject *Sender)
{
	ShowFormRegressaCorrelacao();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::mnAtualizaClick(TObject *Sender)
{
	ShellExecute( NULL , "open", IGEST_VERSAO::SITE.c_str(), NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AnlisedeVarinciaANOVAcomumfator1Click(TObject *Sender)

{
	Show_Form_anova();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TestedeIndependncia1Click(TObject *Sender)
{
	Show_Form_Independencia();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::menu_estimativa_intervalarClick(TObject *Sender)
{
	Show_Form_Estimativa_Intervalar();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{

	if(ThreadUpd != NULL)
	{
		ThreadUpd->Terminate();
		delete ThreadUpd;
		ThreadUpd = NULL;
	}
	ShellExecute( NULL , "open", IGEST_VERSAO::SITE.c_str(), NULL, NULL, SW_SHOWNORMAL);

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	Hide();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MD51Click(TObject *Sender)
{
	//ShowFormMD5();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::SobreoAutor1Click(TObject *Sender)
{
	//http://lattes.cnpq.br/6388966089604003
	ShellExecute( NULL , "open", "http://lattes.cnpq.br/6388966089604003", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::estedeHipteseJarqueBera1Click(TObject *Sender)
{
    ShowFormJarqueBera();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::FormDestroy(TObject *Sender)
{
		if (ThreadUpd != NULL )
		{
			ThreadUpd->Free();
		}

		this->Refresh();
		TIGestConfig::GetIGestConfig()->save_form(this);
		TIGestConfig::GetIGestConfig()->set_config("UltimaFinalizacao", DateTimeToStr(Now()));
		delete TIGestConfig::GetIGestConfig();
		delete IGEstPluginManager1;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Configuraes1Click(TObject *Sender)
{
	TForm *FrmOpcoes = CriarFormOpcoes(this);
	FrmOpcoes->FormStyle << fsMDIChild;
    //FrmOpcoes->Visible = true;
	FrmOpcoes->Parent = this;
	FrmOpcoes->Width = 1102;
	FrmOpcoes->Height = 580;
    FrmOpcoes->Position = poScreenCenter;
	FrmOpcoes->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ArquivosdaWikipdia1Click(TObject *Sender)
{
    ShowFormWiki();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
    IGEstPluginManager1 = new IGEstPluginManager(MainMenu);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ThreadTerminated(TObject *Sender)
{
	// thread is finished with its work ...
    //ThreadUpd->OnTerminate = NULL;
	//ShowMessage("DEBUG: thread terminou");
}
void __fastcall TMainForm::PginadoProjeto1Click(TObject *Sender)
{
	ShellExecute( NULL , "open", IGEST_VERSAO::SITE_PROJ_SRC.c_str(), NULL, NULL, SW_SHOWNORMAL);

}
//---------------------------------------------------------------------------

