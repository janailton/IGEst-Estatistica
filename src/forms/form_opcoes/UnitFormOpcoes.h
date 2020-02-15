//    Copyright (C) 2020 - 2009 Jos� Jana�lton da Silva <josejanailton@gmail.com>
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

#ifndef UnitFormOpcoesH
#define UnitFormOpcoesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ValEdit.hpp>
//---------------------------------------------------------------------------
class TFormOpcoes : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TPageControl *PageControlOpcoes;
	TTabSheet *TabSheetLayou;
	TTabControl *TabControlOpcoes;
	TButton *btnMaisOpcoes;
	TButton *btnPastas;
	TButton *btnLayou;
	TTabSheet *TabSheetPastas;
	TTabSheet *TabSheetOutrasOpcoes;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TGroupBox *GroupBox3;
	TButton *btnSalvar;
	TLabel *Label1;
	TComboBox *ComboBoxStyle;
	TLabel *Label2;
	TFontDialog *FontDialog1;
	TButton *Button2;
	TEdit *EditFont;
	TLabel *Label3;
	TComboBox *ComboBoxTamFont;
	TLabel *Label4;
	TColorBox *ColorBoxFont;
	TValueListEditor *ValueListEditor;
	TLabel *Label5;
	TEdit *EditInstall;
	TLabel *Label6;
	TEdit *EditPastaDeConfiguracao;
	TEdit *EditPastaMateriaisDeEstudo;
	TLabel *Label7;
	void __fastcall btnLayouClick(TObject *Sender);
	void __fastcall btnPastasClick(TObject *Sender);
	void __fastcall btnMaisOpcoesClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall ComboBoxStyleChange(TObject *Sender);
	void __fastcall btnSelecFont(TObject *Sender);
	void __fastcall ComboBoxTamFontChange(TObject *Sender);
	void __fastcall ColorBoxFontChange(TObject *Sender);
	void __fastcall FormCanResize(TObject *Sender, int &NewWidth, int &NewHeight, bool &Resize);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall btnSalvarClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TFormOpcoes(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormOpcoes *FormOpcoes;
//---------------------------------------------------------------------------

TForm *CriarFormOpcoes( TForm *_Parent){
	if (FormOpcoes == NULL)
	{
		Application->CreateForm(__classid(TFormOpcoes), &FormOpcoes);
	}
	return FormOpcoes;
}


#endif
