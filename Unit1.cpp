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
//��������� ��� ���������� � �������� ����� � �������
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
//���������� ��� ������ �������� � ��������
bool add;
//��������� ��� �������� �� ����������
bool save;
//���������� ��� ������ ���������� �����
int sum;
//���������� ��� ����������� ������
int str;
//��������� ��� ��������� � �����
FILE *A;

// �������� ������� �����
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	sum = 0;
	str = 0;
	save = true;
}
//---------------------------------------------------------------------------
// ������� ����������� ������
void __fastcall TForm1::StringGrid2SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect)
{
	str = ARow;
}

//���������� ������
__fastcall TForm1::TForm1(TComponent* Owner)
//---------------------------------------------------------------------------
//��������� ������� �����
	: TForm(Owner)
{
	StringGrid1->Cells[0][0] = "�.�.�. ������";
	StringGrid1->Cells[1][0] = "��� ��������";
	StringGrid1->Cells[2][0] = "���";
	StringGrid1->Cells[3][0] = "����� ����������";
	StringGrid1->Cells[4][0] = "�����������";
	StringGrid1->Cells[5][0] = "���������� �����";
	StringGrid1->Cells[6][0] = "����� ������";
	Button2->Enabled = false;
	Button3->Enabled = false;
	Button4->Enabled = false;
	Button5->Enabled = false;
	Button6->Enabled = false;
	Button7->Enabled = false;
}
//---------------------------------------------------------------------------

//���������� ������
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	add = true;
	Form2->Caption = "���������� ������";
	Form2->Button1->Caption = "��������";
	Form2->Edit1->Text = "� � �";
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


//��������� ������
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	add = false;
	Form2->Caption = "��������� ��������";
	Form2->Button1->Caption = "��������";
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
//�������� ������ �� ������
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
//�������������� ������
void __fastcall TForm1::Button4Click(TObject *Sender)
{
   Form3->ShowModal();
}
//---------------------------------------------------------------------------

//����� �� ����������
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Form5->ShowModal();
}
//---------------------------------------------------------------------------
//������������ ����������� � ����� ������
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Form6->ShowModal();
}
//---------------------------------------------------------------------------
//�������� ���� �����
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


//������� �������� ���������
void __fastcall TForm1::N5Click(TObject *Sender)
{
   ShowMessage("���������� �������� ��������� �������� � �����, ������� ��������� ���������: �.�.�. ������, ��� ��� ��������, ���, ����� ��������������� (�����), �����������, ���������� �����, ����� ������. �������� ���������, �������������� ��� �������� � ����������� ����������: ������� ������� ������� (�������, �������); ������� �������, ������� ������ �����������; ����� ���������� �����. ������������ ������ �������������, ����������� � ����� ������. ������������ ����� �������� � �������� �� ��� ������� � ���� �������� ");
}
//---------------------------------------------------------------------------
//������� �������� �� ���������
void __fastcall TForm1::N2Click(TObject *Sender)
{
  ShowMessage("������ alpha v1.0\n ���� ��������� ���������:13.11.22 \n");
}
//---------------------------------------------------------------------------
//������� �������� ��������
void __fastcall TForm1::N1Click(TObject *Sender)
{
   ShowMessage("������ ��������� ������������� ������ � �������� ���������. \n������ ���������� ������������� ��� ���������� �������� � �������� \n������ ���������� ������������� ��� �������� ��������� ������ � ��������. \n������ ���� ������ ������������ ��� �������������� �������������� ������ ����� ��������� �������. \n������ ������ ��������� ����� ���������� � ��������. \n������ ������� ��������� ����� ����� � ����������� ��������� ����������� � ����� ������. \n������ ��������� ��������� ��������� ������� ������ \n������ �������� ��� ��������� ������� ��� ��������� ������.");
}
//---------------------------------------------------------------------------

//������� ����������
void __fastcall TForm1::N3Click(TObject *Sender)
{
	if (SaveDialog1->Execute()) {
		if (FileExists(SaveDialog1->FileName))
		{
			if (MessageDlg("���� � ����� ������ ��� ����������. ������������?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrNo)
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
//������� �������� �����
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
		ShowMessage("���� �� ����������");
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
//������� �������� �� ����������
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (save != true)
	{
	   Form8->ShowModal();
	}
}
//---------------------------------------------------------------------------

//������� ��������� ������ ����� Enter
void __fastcall TForm1::Button1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
  if(Key=VK_RETURN)
  {
	 Form1->Button1Click(Sender);
  }
}
//---------------------------------------------------------------------------

