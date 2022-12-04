//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit7.h"
#include "DateUtils.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
extern int sum;
extern int str;

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	Button3->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	 Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
	int Voz;
	int Otv = 0;
	int Otv2 = 0;
	int Chet = 0;
	int Chet2 = 0;
	//���������� ��������� ��������
	for (int i = 0; i < sum; i++){
	  if (Form1->StringGrid2->Cells[2][i] == "�"){
	  Voz = StrToInt(YearsBetween(Now(),StrToDate(Form1->StringGrid2->Cells[1][i])));
	  Otv = Otv + Voz;
	  Chet++;
	  }
	  else {

	  Voz = StrToInt(YearsBetween(Now(),StrToDate(Form1->StringGrid2->Cells[1][i])));
	  Otv2 = Otv2+ Voz;
	  Chet2++;
	  }
	}
	if (Otv > 0 && Otv2 > 0){

		Edit3->Text = Otv2/Chet2;
		Edit3->Left = 357;
		Edit3->Width = 41;
		Edit2->Text = Otv/Chet;
		Edit2->Left = 357;
		Edit2->Width = 41;
	   if (Otv2 < 10)
	   {
		  if (Otv2 == 1)
		  {
			 Label5->Caption = "���";
		  }
		  else if (Otv2 > 1 && Otv2 < 5)
		  {
			Label5->Caption = "����";
		  }
		  else
		  {
			Label5->Caption = "���";
		  }
	   }
	   else if(Otv2 > 10 && Otv2 < 21)
	   {
		  Label5->Caption = "���";
	   }

	   else if (Otv2 > 20)
	   {
		 if ((Otv2 % 10) == 1)
		 {
			Label5->Caption = "���";
		 }
		 else if ((Otv2 % 10) > 1 && (Otv2 % 10) < 5)
		 {
			Label5->Caption = "����";
		 }
		 else
		 {
			Label5->Caption = "���";
		 }

	   }


       	   if (Otv < 10)
	   {
		  if (Otv == 1)
		  {
			 Label6->Caption = "���";
		  }
		  else if (Otv > 1 && Otv < 5)
		  {
			Label6->Caption = "����";
		  }
		  else
		  {
			Label6->Caption = "���";
		  }
	   }
	   else if(Otv > 10 && Otv < 21)
	   {
		  Label6->Caption = "���";
	   }

	   else if (Otv > 20)
	   {
		 if ((Otv % 10) == 1)
		 {
			Label6->Caption = "���";
		 }
		 else if ((Otv % 10) > 1 && (Otv % 10) < 5)
		 {
			Label6->Caption = "����";
		 }
		 else
		 {
			Label6->Caption = "���";
		 }
	   }
	}
	else if  (Otv == 0 && Otv2 > 0)
	{
	   Edit3->Text = Otv2/Chet2;
	   Edit3->Left = 357;
	   Edit3->Width = 41;
	   Edit2->Text = "������ � ������ ���";
	   Edit2->Left = 315;
	   Edit2->Width = 123;
	   if (Otv2 < 10)
	   {
		  if (Otv2 == 1)
		  {
			 Label5->Caption = "���";
		  }
		  else if (Otv2 > 1 && Otv2 < 5)
		  {
			Label5->Caption = "����";
		  }
		  else
		  {
			Label5->Caption = "���";
		  }
	   }
	   else if(Otv2 > 10 && Otv2 < 21)
	   {
		  Label5->Caption = "���";
	   }

	   else if (Otv2 > 20)
	   {
		 if ((Otv2 % 10) == 1)
		 {
			Label5->Caption = "���";
		 }
		 else if ((Otv2 % 10) > 1 && (Otv2 % 10) < 5)
		 {
			Label5->Caption = "����";
		 }
		 else
		 {
			Label5->Caption = "���";
		 }
	   }
	}



	else
	{
		Edit2->Text = Otv/Chet;
		Edit2->Left = 357;
		Edit2->Width = 41;
		Edit3->Text = "������ � ������ ���";
		Edit3->Left = 315;
		Edit3->Width = 123;
	   if (Otv < 10)
	   {
		  if (Otv == 1)
		  {
			 Label6->Caption = "���";
		  }
		  else if (Otv > 1 && Otv < 5)
		  {
			Label6->Caption = "����";
		  }
		  else
		  {
			Label6->Caption = "���";
		  }
	   }
	   else if(Otv > 10 && Otv < 21)
	   {
		  Label6->Caption = "���";
	   }

	   else if (Otv > 20)
	   {
		 if ((Otv % 10) == 1)
		 {
			Label6->Caption = "���";
		 }
		 else if ((Otv % 10) > 1 && (Otv % 10) < 5)
		 {
			Label6->Caption = "����";
		 }
		 else
		 {
			Label6->Caption = "���";
		 }
	   }
	}



	//������� �������� ����� � ������ ������������
	Chet = 0;
	float proc;
	proc = 0;
	for (int i = 0; i<sum; i++){
	   if (Form1->StringGrid2->Cells[4][i] == "������"){
		 Chet++;
	   }
	}
	if (Chet == 0)
	{
	   Edit7->Text = "����� � ������ ������������ ���";
	   Edit7->Left = 316;
	   Edit7->Width = 125;
	}
	else
	{
	   proc = Chet/(float)sum;
	   Edit7->Text = FormatFloat("0",proc*100);
	   Edit7->Left = 357;
	   Edit7->Width = 41;
	}
	proc = 0;
	//����� ����� ����������� ������
	String max;
	String maxC;
	String *city = new String[sum];
	int *sumcity = new int[sum];
	bool flag = false;
	int temp = 1;
	int sort = 0;
	String sortcity = "";
	city[0] = Form1->StringGrid2->Cells[3][0];
	sumcity[0] = 1;
	for (int i = 1; i < sum; i++)
	{
		for (int j = 0; j < temp; j++) {
			if (Form1->StringGrid2->Cells[3][i].UpperCase() == city[j].UpperCase()) {
				sumcity[j]++;
				flag = true;
			}
		}
		if (flag == false) {
			temp++;
			city[temp - 1] = Form1->StringGrid2->Cells[3][i];
			sumcity[temp - 1] = 1;
		}
		flag = false;
	}
	for (int i = 0; i < temp - 1; i++) {
		 for (int j = i + 1; j < temp; j++) {
			if (sumcity[i] < sumcity[j]) {
				sort = sumcity[i];
				sortcity = city[i];
				sumcity[i] = sumcity[j];
				city[i] = city[j];
				sumcity[j] = sort;
				city[j] = sortcity;
			}
		 }
	}
	for (int i = 0; i < temp; i++) {
		Form7->StringGrid2->Cells[0][i] = city[i];
		Form7->StringGrid2->Cells[1][i] = sumcity[i];
	}
	max = sumcity[0];
	maxC = city[0];
	Chet = 0;
	for (int i = 1; i < temp; i++)
	{
	  if (max<sumcity[i])
	  {
		max = sumcity[i];
		maxC = city[i];
	  }
	}
	for (int i = 0; i < temp; i++)
	{
	   if (max == sumcity[i])
	   {
		 Chet++;
	   }
	}
	if (Chet > 1)
	{
	   Edit4->Text = "� ������ ��������� ������� ����� ������������ ���������";
	   Edit4->Left = 207;
	   Edit4->Width = 233;

	}
	else if (Chet == 1)
	{
	   Edit4->Text = maxC;
	   Edit4->Left = 352;
	   Edit4->Width = 88;
	}
	Chet = 0;
	Button3->Enabled = true;
}
//---------------------------------------------------------------------------

//�������� ������ � �������� � �� ����������
void __fastcall TForm3::Button3Click(TObject *Sender)
{
	Form7->ShowModal();
}
//---------------------------------------------------------------------------



