//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
extern int sum;
int str;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
	StringGrid1->Cells[0][0] = "Ф.И.О. жителя";
	StringGrid1->Cells[1][0] = "год рождения";
	StringGrid1->Cells[2][0] = "пол";
	StringGrid1->Cells[3][0] = "Город проживания";
	StringGrid1->Cells[4][0] = "образование";
	StringGrid1->Cells[5][0] = "количество детей";
	StringGrid1->Cells[6][0] = "место работы";
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button2Click(TObject *Sender)
{
//Создание массива в который записывают фамилию город а так же число людей удовлетворяющие условию
	String *fam = new String[sum];
	String *Gor = new String[sum];
	int *sumfamG = new int[sum];
	bool flag = false;
	int temp = 1;
	int n;
	fam[0] = Form1->StringGrid2->Cells[0][0].SubString(1,Form1->StringGrid2->Cells[0][0].Pos(" ")-1);
	Gor[0] = Form1->StringGrid2->Cells[3][0];
	sumfamG[0] = 1;
	int a = 0;
	for (int i = 1; i < sum; i++)
	{
		for (int j = 0; j < temp; j++) {
			n = fam[j].Length();
			if ((Form1->StringGrid2->Cells[0][i].SubString(1,Form1->StringGrid2->Cells[0][i].Pos(" ")-1) == fam[j] && Form1->StringGrid2->Cells[3][i].UpperCase() == Gor[j].UpperCase()) || (Form1->StringGrid2->Cells[0][i].SubString(1,Form1->StringGrid2->Cells[0][i].Pos(" ")-2) == fam[j] && Form1->StringGrid2->Cells[3][i].UpperCase() == Gor[j].UpperCase()) ||
			(Form1->StringGrid2->Cells[0][i].SubString(1,Form1->StringGrid2->Cells[0][i].Pos(" ")-1) == fam[j].SubString(1,n-1) && Form1->StringGrid2->Cells[3][i].UpperCase() == Gor[j].UpperCase()))
			{
				sumfamG[j]++;
				flag = true;
			}
		}
		if (flag == false) {
			temp++;
			fam[temp - 1] = Form1->StringGrid2->Cells[0][i].SubString(1,Form1->StringGrid2->Cells[0][i].Pos(" ")-1);
			Gor[temp - 1] = Form1->StringGrid2->Cells[3][i];
			sumfamG[temp - 1] = 1;
		}
		flag = false;
	}
	str = 0;
	int j = 0;
	int i = 0;
	//Проверка таблицы на наличие однафамильцев проживающих в одном городе
	while (i <= temp)
	{
	   if (sumfamG[i] > 1)
	   {
		 while(j <= sum)
		 {
			  n = fam[i].Length();
			  if ((Form1->StringGrid2->Cells[0][j].SubString(1,Form1->StringGrid2->Cells[0][j].Pos(" ")-1) == fam[i] && Form1->StringGrid2->Cells[3][j].UpperCase() == Gor[i].UpperCase()) ||
			   (Form1->StringGrid2->Cells[0][j].SubString(1,Form1->StringGrid2->Cells[0][j].Pos(" ")-2) == fam[i] && Form1->StringGrid2->Cells[3][j].UpperCase() == Gor[i].UpperCase()) || (Form1->StringGrid2->Cells[0][j].SubString(1,Form1->StringGrid2->Cells[0][j].Pos(" ")-1) == fam[i].SubString(1,n - 1) && Form1->StringGrid2->Cells[3][j].UpperCase() == Gor[i].UpperCase()))
			  {
					  Form6->StringGrid2->Cells[0][str] = Form1->StringGrid2->Cells[0][j];
					  Form6->StringGrid2->Cells[1][str] = Form1->StringGrid2->Cells[1][j];
					  Form6->StringGrid2->Cells[2][str] = Form1->StringGrid2->Cells[2][j];
					  Form6->StringGrid2->Cells[3][str] = Form1->StringGrid2->Cells[3][j];
					  Form6->StringGrid2->Cells[4][str] = Form1->StringGrid2->Cells[4][j];
					  Form6->StringGrid2->Cells[5][str] = Form1->StringGrid2->Cells[5][j];
					  Form6->StringGrid2->Cells[6][str] = Form1->StringGrid2->Cells[6][j];
					  str++;
			  }
			  j++;
		 }
	   }
	   i++;
	   j = 0;
	}
	Button2->Enabled = false;
}
//---------------------------------------------------------------------------
//Закрытие формы
void __fastcall TForm6::Button1Click(TObject *Sender)
{
   for(int i = 0; i < sum; i++){

	  Form6->StringGrid2->Cells[0][i] = "";
	  Form6->StringGrid2->Cells[1][i] = "";
	  Form6->StringGrid2->Cells[2][i] = "";
	  Form6->StringGrid2->Cells[3][i] = "";
	  Form6->StringGrid2->Cells[4][i] = "";
	  Form6->StringGrid2->Cells[5][i] = "";
	  Form6->StringGrid2->Cells[6][i] = "";
   }
	str = 0;
	Button2->Enabled = true;
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::FormClose(TObject *Sender, TCloseAction &Action)
{
   for(int i = 0; i < sum; i++){

	  Form6->StringGrid2->Cells[0][i] = "";
	  Form6->StringGrid2->Cells[1][i] = "";
	  Form6->StringGrid2->Cells[2][i] = "";
	  Form6->StringGrid2->Cells[3][i] = "";
	  Form6->StringGrid2->Cells[4][i] = "";
	  Form6->StringGrid2->Cells[5][i] = "";
	  Form6->StringGrid2->Cells[6][i] = "";
   }
	str = 0;
	Button2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
  if(Key=VK_RETURN)
  {
	 Form6->Button2Click(Sender);
  }
}
//---------------------------------------------------------------------------

