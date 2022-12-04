//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit8.h"
#include "DateUtils.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
//Структура для сохранения и открытия файла в таблицы
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
//Переменная для кнопок Добавить и Изменить
bool add;
//Переменна для проверки на сохранение
bool save;
//Переменная для записи количества строк
int sum;
//Переменная для запоминания строки
int str;
//Переменна для обращения к файлу
FILE *A;

// Создание главной формы
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	sum = 0;
	str = 0;
	save = true;
}
//---------------------------------------------------------------------------
// Функция запоминания строки
void __fastcall TForm1::StringGrid2SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect)
{
	str = ARow;
}

//Добавление жильца
__fastcall TForm1::TForm1(TComponent* Owner)
//---------------------------------------------------------------------------
//Заполение главной формы
	: TForm(Owner)
{
	StringGrid1->Cells[0][0] = "Ф.И.О. жителя";
	StringGrid1->Cells[1][0] = "год рождения";
	StringGrid1->Cells[2][0] = "пол";
	StringGrid1->Cells[3][0] = "Город проживания";
	StringGrid1->Cells[4][0] = "образование";
	StringGrid1->Cells[5][0] = "количество детей";
	StringGrid1->Cells[6][0] = "место работы";
	Button2->Enabled = false;
	Button3->Enabled = false;
	Button4->Enabled = false;
	Button5->Enabled = false;
	Button6->Enabled = false;
	Button7->Enabled = false;
}
//---------------------------------------------------------------------------

//Добавление жильца
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	add = true;
	Form2->Caption = "Добавление жильца";
	Form2->Button1->Caption = "Добавить";
	Form2->Edit1->Text = "Ф И О";
	Form2->Edit2->Text = "00.00.0000";
	Form2->ComboBox1->Text = "";
	Form2->Edit3->Text = "";
	Form2->ComboBox2->Text = "";
	Form2->Edit4->Text = "0";
	Form2->Edit5->Text = "";
	Form2->ShowModal();
	if (sum == 0) {
		Button2->Enabled = false;
		Button3->Enabled = false;
		Button4->Enabled = false;
		Button5->Enabled = false;
		Button6->Enabled = false;
		Button7->Enabled = false;
	}
	else {
		Button2->Enabled = true;
		Button3->Enabled = true;
		Button4->Enabled = true;
		Button5->Enabled = true;
		Button6->Enabled = true;
		Button7->Enabled = true;
	}
	save = false;
}
//----------------------------------------------------------------------


//Изменение жильца
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	add = false;
	Form2->Caption = "Изменение человека";
	Form2->Button1->Caption = "Изменить";
	Form2->Edit1->Text = Form1->StringGrid2->Cells[0][str];
	Form2->Edit2->Text = Form1->StringGrid2->Cells[1][str];
	Form2->ComboBox1->Text = Form1->StringGrid2->Cells[2][str];
	Form2->Edit3->Text = Form1->StringGrid2->Cells[3][str];
	Form2->ComboBox2->Text = Form1->StringGrid2->Cells[4][str];
	Form2->Edit4->Text = Form1->StringGrid2->Cells[5][str];
	Form2->Edit5->Text = Form1->StringGrid2->Cells[6][str];
	Form2->ShowModal();
	save = false;
}
//---------------------------------------------------------------------------
//Удаление строки по выбору
void __fastcall TForm1::Button2Click(TObject *Sender)
{
   int i, j;
	if (sum > 0) {
		for (i = str; i < StringGrid2->RowCount; i++) {
			for (j = 0; j < 7; j++) {
				StringGrid2->Cells[j][i] = StringGrid2->Cells[j][i + 1];
			}
		}
		sum--;
		if (sum > 0) {
			StringGrid2->RowCount = sum;
		}
	}
	if (sum == 0) {
		for (j = 0; j < 7; j++) {
			StringGrid2->Cells[j][0] = "";
		}
		Button2->Enabled = false;
		Button3->Enabled = false;
		Button4->Enabled = false;
		Button5->Enabled = false;
		Button6->Enabled = false;
		Button7->Enabled = false;
	}
	else {
		Button2->Enabled = true;
		Button3->Enabled = true;
		Button4->Enabled = true;
		Button5->Enabled = true;
		Button6->Enabled = true;
		Button7->Enabled = true;
	}
	save = false;
}
//---------------------------------------------------------------------------
//Дополнительные данные
void __fastcall TForm1::Button4Click(TObject *Sender)
{
   Form3->ShowModal();
}
//---------------------------------------------------------------------------

//Поиск по параметрам
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Form5->ShowModal();
}
//---------------------------------------------------------------------------
//Однофамильцы проживающие в одном городе
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Form6->ShowModal();
}
//---------------------------------------------------------------------------
//Удаление всех строк
void __fastcall TForm1::Button7Click(TObject *Sender)
{
   for (int i = 0; i < sum; i++)
   {
	   Form1->StringGrid2->Cells[0][i] = "";
	   Form1->StringGrid2->Cells[1][i] = "";
	   Form1->StringGrid2->Cells[2][i] = "";
	   Form1->StringGrid2->Cells[3][i] = "";
	   Form1->StringGrid2->Cells[4][i] = "";
	   Form1->StringGrid2->Cells[5][i] = "";
	   Form1->StringGrid2->Cells[6][i] = "";
	   Button2->Enabled = false;
	   Button3->Enabled = false;
	   Button4->Enabled = false;
	   Button5->Enabled = false;
	   Button6->Enabled = false;
	   Button7->Enabled = false;
   }
   sum = 0;
   save = true;
}
//---------------------------------------------------------------------------


//Функция открытия «Задания»
void __fastcall TForm1::N5Click(TObject *Sender)
{
   ShowMessage("Результаты переписи населения хранятся в файле, имеющем следующую структуру: Ф.И.О. жителя, его год рождения, пол, адрес местожительства (город), образование, количество детей, место работы. Написать программу, обрабатывающую эти сведения и позволяющую определить: средний возраст жителей (мужчины, женщины); процент россиян, имеющих высшее образование; самый населенный город. Сформировать списки однофамильцев, проживающих в одном городе. Организовать поиск сведений о человеке по его фамилии и году рождения ");
}
//---------------------------------------------------------------------------
//Функция открытия «О программе»
void __fastcall TForm1::N2Click(TObject *Sender)
{
  ShowMessage("Версия alpha v1.0\n Дата последних изменений:13.11.22 \n");
}
//---------------------------------------------------------------------------
//Функция открытия «Справка»
void __fastcall TForm1::N1Click(TObject *Sender)
{
   ShowMessage("Данная программа предостовляет данные о перепеси начеления. \nКнопка «Добавить» предназначена для добавления сведений о человеке \nКнопка «Изменить» предназначена для измнения введенных данных о человеке. \nКнопка «Доп данный» предназначна для предоставлении дополнительных данных после обработки таблицы. \nКнопка «Поиск» позволяет найти информацию о человеке. \nКнопка «Список» позволяет найти людей с одинаковыми фамилиями проживающих в одном городе. \nКнопка «Удалить» позволяет выборочно удалить данные \nКнопка «Удалить все» позволяет удалить все введенные данные.");
}
//---------------------------------------------------------------------------

//Функция сохранении
void __fastcall TForm1::N3Click(TObject *Sender)
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
			strcpy(rec.FIO, AnsiString(StringGrid2->Cells[0][i]).c_str());
			strcpy(rec.Year, AnsiString(StringGrid2->Cells[1][i]).c_str());
			strcpy(rec.Pol, AnsiString(StringGrid2->Cells[2][i]).c_str());
			strcpy(rec.city, AnsiString(StringGrid2->Cells[3][i]).c_str());
			strcpy(rec.obr, AnsiString(StringGrid2->Cells[4][i]).c_str());
			strcpy(rec.Childern, AnsiString(StringGrid2->Cells[5][i]).c_str());
			strcpy(rec.Work, AnsiString(StringGrid2->Cells[6][i]).c_str());
			fwrite(&rec, sizeof(Save), 1, A);
		}
		fclose(A);
	}
	save = true;
}
//---------------------------------------------------------------------------
//Функция открытия файла
void __fastcall TForm1::N4Click(TObject *Sender)
{
  if (OpenDialog1->Execute() && FileExists(OpenDialog1->FileName))
   {
		A = fopen(AnsiString(OpenDialog1->FileName).c_str(), "rt");
		StringGrid2->RowCount = 1;
		int i = 0;
		while (!feof(A))
		{
			fread(&rec, sizeof(Save), 1, A);
			StringGrid2->Cells[0][i] = rec.FIO;
			StringGrid2->Cells[1][i] = rec.Year;
			StringGrid2->Cells[2][i] = rec.Pol;
			StringGrid2->Cells[3][i] = rec.city;
			StringGrid2->Cells[4][i] = rec.obr;
			StringGrid2->Cells[5][i] = rec.Childern;
			StringGrid2->Cells[6][i] = rec.Work;
			StringGrid2->RowCount = i;
			sum = i + 1;
			i++;

		}
		for (int j = 0; j < 7; j++)
		{
			StringGrid2->Cells[j][i] = StringGrid2->Cells[j][i + 1];
		}
		sum--;
		fclose(A);
		save = true;
	}
	else
		ShowMessage("Файл не существует");
	if (sum > 0)
	{
		Button1->Enabled = true;
		Button2->Enabled = true;
		Button3->Enabled = true;
		Button4->Enabled = true;
		Button5->Enabled = true;
		Button6->Enabled = true;
		Button7->Enabled = true;
	}
}
//---------------------------------------------------------------------------
//Функция проверки на сохранение
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (save != true)
	{
	   Form8->ShowModal();
	}
}
//---------------------------------------------------------------------------

//Функция активации кнопки через Enter
void __fastcall TForm1::Button1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
  if(Key=VK_RETURN)
  {
	 Form1->Button1Click(Sender);
  }
}
//---------------------------------------------------------------------------

