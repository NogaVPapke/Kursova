//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit5.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
	StringGrid1->Cells[0][0] = "�.�.�. ������";
	StringGrid1->Cells[1][0] = "��� ��������";
	StringGrid1->Cells[2][0] = "���";
	StringGrid1->Cells[3][0] = "����� ����������";
	StringGrid1->Cells[4][0] = "�����������";
	StringGrid1->Cells[5][0] = "���������� �����";
	StringGrid1->Cells[6][0] = "����� ������";
}
//---------------------------------------------------------------------------
