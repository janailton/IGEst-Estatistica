//---------------------------------------------------------------------------


#pragma hdrstop

#include "ExportExcel.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)


ExportExcel::ExportExcel()
{
	//open excel application
	XL=Variant::CreateObject("excel.application");

	XL.OlePropertyGet("workbooks").OleFunction("add");

	//open the worksheet “example1″
	v0=XL.OlePropertyGet("Activesheet");

	//get a cell
	v1=v0.OlePropertyGet("Cells");

	Coluna=1; Linha=1;

}
ExportExcel::~ExportExcel()
{
	//XL.OleProcedure("Quit");
	XL=Unassigned;
}

void ExportExcel::setCell(int x, int y, AnsiString valor)
{
	v1.OlePropertyGet("Item",y,x).OlePropertySet("Value" ,valor.c_str());
}
void ExportExcel::ShowExcel()
{
 	XL.OlePropertySet("Visible",true);
}

void ExportExcel::nextLine()
{
 Linha++;
 Coluna=1;
}

void ExportExcel::setText( AnsiString texto)
{
	v1.OlePropertyGet("Item",Linha, Coluna).OlePropertySet("Value" ,texto.c_str());
	Coluna++;
}
