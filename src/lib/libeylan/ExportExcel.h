//---------------------------------------------------------------------------

#ifndef ExportExcelH
#define ExportExcelH

#include <vcl.h>

#include <string>
using namespace std;

class ExportExcel{
	public:
		ExportExcel();
		~ExportExcel();

		void setCell(int x, int y, AnsiString valor);
		void ShowExcel();
		void nextLine();
		void setText( AnsiString texto);

	private:

		Variant XL,v0,v1;
		int Linha;
		int Coluna;
};


//---------------------------------------------------------------------------
#endif
