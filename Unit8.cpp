//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit8.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
extern int sum;
extern bool save;
FILE *A;
//Структура для сохранения и открытия
struct Save {
	char FIO[100];
	char Year[100];
	char Pol[100];
	char city[100];
	char obr[100];
	char Childern[100];
	char Work[100];
};
Save rec;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//Сохранение файла
void __fastcall TForm8::Button1Click(TObject *Sender)
{
	if (SaveDialog1->Execute()) {
		if (FileExists(SaveDialog1->FileName))
		{
			if (MessageDlg("Фаил с таким именем уже существует. Перезаписать?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
			{
				return;
			}
		}
		A = fopen(AnsiString(SaveDialog1->FileName).c_str(), "wt");
		for (int i = 0; i < sum; i++)
		{
			strcpy(rec.FIO, AnsiString(Form1->StringGrid2->Cells[0][i]).c_str());
			strcpy(rec.Year, AnsiString(Form1->StringGrid2->Cells[1][i]).c_str());
			strcpy(rec.Pol, AnsiString(Form1->StringGrid2->Cells[2][i]).c_str());
			strcpy(rec.city, AnsiString(Form1->StringGrid2->Cells[3][i]).c_str());
			strcpy(rec.obr, AnsiString(Form1->StringGrid2->Cells[4][i]).c_str());
			strcpy(rec.Childern, AnsiString(Form1->StringGrid2->Cells[5][i]).c_str());
			strcpy(rec.Work, AnsiString(Form1->StringGrid2->Cells[6][i]).c_str());
			fwrite(&rec, sizeof(Save), 1, A);
		}
		fclose(A);
	}
    save = true;
}
//---------------------------------------------------------------------------
//Закрытие формы
void __fastcall TForm8::Button2Click(TObject *Sender)
{
     Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
  if(Key=VK_RETURN)
  {
	 Form8->Button1Click(Sender);
  }
}
//---------------------------------------------------------------------------

