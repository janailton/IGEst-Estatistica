//    Copyright (C) 2010, 2009 José Janaílton da Silva
//		<josejanailton@gmail.com>
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

#ifndef unit_form_estimativa_intervalarH
#define unit_form_estimativa_intervalarH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <TabNotBk.hpp>
//---------------------------------------------------------------------------
class TForm_Estimativa_Intervalar : public TForm
{
__published:	// IDE-managed Components
	TTabbedNotebook *TabbedNotebook1;
	TGroupBox *GroupBox1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label5;
	TEdit *EditProporcao;
	TEdit *EditPropN;
	TEdit *EditPropAlfa;
	TGroupBox *GroupBox2;
	TLabel *Label4;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TEdit *EditMediaMDPD;
	TEdit *EditVarianciaMDPD;
	TEdit *EditNMDPD;
	TEdit *EditAlfaMDPD;
	TGroupBox *GroupBox3;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TEdit *EditMediaDPC;
	TEdit *EditNDPC;
	TEdit *EditAlfaDPC;
	TEdit *EditVarianciaDPC;
	TButton *btnMDPC;
	TButton *btnProporcao;
	TButton *btnMDPD;
	void __fastcall btnProporcaoClick(TObject *Sender);
	void __fastcall btnMDPCClick(TObject *Sender);
	void __fastcall btnMDPDClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm_Estimativa_Intervalar(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_Estimativa_Intervalar *Form_Estimativa_Intervalar;
//---------------------------------------------------------------------------

void __fastcall Show_Form_Estimativa_Intervalar()
{
	TForm_Estimativa_Intervalar *form_estivat_inter = new TForm_Estimativa_Intervalar(Application);
	form_estivat_inter->Visible = false;
	form_estivat_inter->ShowModal();
    form_estivat_inter->Free();
}


#endif
