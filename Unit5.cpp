//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit4.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
extern int sum;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner): TForm(Owner)
{
}
//---------------------------------------------------------------------------
//Поиск сведений по параметрам
void __fastcall TForm5::Button1Click(TObject *Sender)
{
		int temp = 0;
		int str = 0;
		int n = 0;
	  if (Edit1->Text != "" && Edit2->Text != ""){
		while (temp <= sum){
		  n = Edit1->Text.Length();
		  if ((Form5->Edit2->Text == Form1->StringGrid2->Cells[1][temp] && Form5->Edit1->Text == Form1->StringGrid2->Cells[0][temp].SubString(1,Form1->StringGrid2->Cells[0][temp].Pos(" ")-1)) || (Form5->Edit2->Text == Form1->StringGrid2->Cells[1][temp] && Form5->Edit1->Text == Form1->StringGrid2->Cells[0][temp].SubString(1,Form1->StringGrid2->Cells[0][temp].Pos(" ")-2)) ||
		  (Form5->Edit2->Text == Form1->StringGrid2->Cells[1][temp] && Form5->Edit1->Text.SubString(1,n - 1) == Form1->StringGrid2->Cells[0][temp].SubString(1,Form1->StringGrid2->Cells[0][temp].Pos(" ")-1)))
		  {
					Form4->StringGrid2->Cells[0][str] = Form1->StringGrid2->Cells[0][temp];
					Form4->StringGrid2->Cells[1][str] = Form1->StringGrid2->Cells[1][temp];
					Form4->StringGrid2->Cells[2][str] = Form1->StringGrid2->Cells[2][temp];
					Form4->StringGrid2->Cells[3][str] = Form1->StringGrid2->Cells[3][temp];
					Form4->StringGrid2->Cells[4][str] = Form1->StringGrid2->Cells[4][temp];
					Form4->StringGrid2->Cells[5][str] = Form1->StringGrid2->Cells[5][temp];
					Form4->StringGrid2->Cells[6][str] = Form1->StringGrid2->Cells[6][temp];
					str++;
		  }
		  temp++;
		}
		if (str == 0)
		{
		  ShowMessage("Данные люди в таблице не найдены");
		}
		else
		{
		  Form4->ShowModal();
		}

	  }
	  else
	  {
		ShowMessage("Заполните все поля");
	  }
}
//---------------------------------------------------------------------------
//Закрытие формы
void __fastcall TForm5::Button2Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------


