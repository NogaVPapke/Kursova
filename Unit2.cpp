// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
extern bool add;
extern int sum;
extern int str;
int d;
// ---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
//добавление/изменение жильца
void __fastcall TForm2::Button1Click(TObject *Sender) {
	if ((Edit4->Text != "" && Edit1->Text != "" && Edit2->Text != ""  && Edit3->Text != "" && ComboBox1->Text != "" && ComboBox2->Text != "")) {
	  if (Edit4->Text >= '0' && Edit4->Text <= '9')
	  {
		  if (add) {
				Form1->StringGrid2->RowCount = sum + 1;
				d = sum;
				sum++;
		  }
		  else
				d = str;
			Form1->StringGrid2->Cells[0][d] = Edit1->Text;
			Form1->StringGrid2->Cells[1][d] = Edit2->Text;
			Form1->StringGrid2->Cells[2][d] = ComboBox1->Text;
			Form1->StringGrid2->Cells[3][d] = Edit3->Text;
			Form1->StringGrid2->Cells[4][d] = ComboBox2->Text;
			Form1->StringGrid2->Cells[5][d] = Edit4->Text;
			Form1->StringGrid2->Cells[6][d] = Edit5->Text;
			Close();
	  }
	  else
	  {
		ShowMessage("Введите количество детей в виде числа");
	  }
	}
	else
	{
	   ShowMessage("Заполните все поля");
	}
}
// ---------------------------------------------------------------------------
//Закрытие формы
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	Close();
}
// ---------------------------------------------------------------------------







