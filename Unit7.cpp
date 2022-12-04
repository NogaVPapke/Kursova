//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
extern int sum;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
	StringGrid1->Cells[0][0] = "Город";
	StringGrid1->Cells[1][0] = "Колл жителей";
}
//---------------------------------------------------------------------------
//Закрытие формы
void __fastcall TForm7::Button1Click(TObject *Sender)
{
	for (int i = 0; i < sum; i++) {
		StringGrid2->Cells[0][i] = "";
		StringGrid2->Cells[1][i] = "";
		Form3->Button3->Enabled = false;
	}
	Close();
}
//---------------------------------------------------------------------------

