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



//---------------------------------------------------------------------------

#ifndef FormHistogramaH
#define FormHistogramaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <Tabs.hpp>
#include <TabNotBk.hpp>
#include <Graphics.hpp>


#include "..\libeylan\EstatisticaDescritiva.h"
#include "IGEST_API.h"

#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <VCLTee.Series.hpp>


#include <string>
#include <iomanip>
using namespace std;


//---------------------------------------------------------------------------
class __declspec(uuid("{29A6377C-8BE5-4A44-A2A7-E050DB639606}")) TFHistograma : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenuHistograma;
    TMenuItem *Arquivo1;
    TMenuItem *Salvar1;
    TTabbedNotebook *TabNotebook;
    TChart *ChartFreqRel;
    TBarSeries *FreqRel;
    TChart *ChartFreqRelAcum;
    TBarSeries *FreqRelAcum;
    TChart *ChartFreqAbs;
    TBarSeries *FreqAbs;
    TChart *ChartFreqAbsAcum;
    TBarSeries *FreqAbsAcum;
    TRichEdit *REDistrFreq;
    TGroupBox *GroupBox1;
    TLabel *Label1;
    TEdit *Edit1;
    TListBox *ListBox1;
    TLabel *Label2;
    TButton *btnAdicionar;
    TButton *btnExcluir;
    TButton *btnCalcular;
    TGroupBox *GroupBox2;
    TMemo *Memo1;
    TSaveDialog *SaveDialog1;
    TOpenDialog *OpenDialog1;
    TMenuItem *Abrir1;
    TButton *btnExcluirTudo;
    TMenuItem *Novo1;
	TButton *btnSalvarnoExcel;
    void __fastcall Salvar1Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall btnAdicionarClick(TObject *Sender);
    void __fastcall btnExcluirClick(TObject *Sender);
    void __fastcall btnCalcularClick(TObject *Sender);
    void __fastcall ListBox1DrawItem(TWinControl *Control, int Index,
          TRect &Rect, TOwnerDrawState State);
    void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall Abrir1Click(TObject *Sender);
    void __fastcall btnExcluirTudoClick(TObject *Sender);
    void __fastcall Novo1Click(TObject *Sender);
	void __fastcall btnSalvarnoExcelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFHistograma(TComponent* Owner);

	void CalculaEstatistica( EstatisticaDescritiva& estatistica);
	void AbrirnoExcel( EstatisticaDescritiva& estatistica);
};
//---------------------------------------------------------------------------
extern PACKAGE TFHistograma *FHistograma;
//---------------------------------------------------------------------------

TFHistograma *FHistograma;

void __fastcall ShowFormHistograma()
{
    TFHistograma *FHistograma = new TFHistograma(Application);
    FHistograma->Visible = false;
    FHistograma->ShowModal();
    FHistograma->Free();
}


#endif
