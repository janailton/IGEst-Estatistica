//    Copyright (C) 2010, 2009 José Janaílton da Silva <josejanailton@gmail.com>
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

#ifndef Unit_resultado_anovaH
#define Unit_resultado_anovaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm_resultado_anova : public TForm
{
__published:	// IDE-managed Components
	TRichEdit *RichEditResultado;
private:	// User declarations
public:		// User declarations
	__fastcall TForm_resultado_anova(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_resultado_anova *Form_resultado_anova;
//---------------------------------------------------------------------------
#endif
