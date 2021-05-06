//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "Calc.h"
TForm1 *Form1;
//Calc A();
//Calc B();

void zerocheck(const int n, TStringGrid *Grid )
{
	for (int i = /*1*/ 0 ; i < n; i++)
	 {
		for (int j = /*1*/ 0 ; j < n; j++)
		{
		  if (Grid->Cells[i][j].IsEmpty())
		  {
			Grid->Cells[i][j] = FloatToStr(0.0);
		  }

		  if (Grid->Cells[i][j] < '0' || Grid->Cells[i][j] > '9' )
		  {
			Grid->Cells[i][j] = FloatToStr(0.0);
		  }

		}
	 }
}

void checklabeled(TLabeledEdit *Labeled)
{
	if (Labeled->Text.IsEmpty())
	{
		Labeled->Text = IntToStr(0);
		ShowMessage("����������, ������� ������ ������ �� �������� �� ����� ��������.");
	}
}



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	ComboBox1->DoubleBuffered = true;
	ComboBox1->AutoComplete = true;
	ComboBox1->AddItem("������� �",NULL);
	ComboBox1->AddItem("������� �",NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	checklabeled(LabeledEdit1);

	zerocheck(StrToInt(LabeledEdit1->Text),StringGrid1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	checklabeled(LabeledEdit1);


	if (ComboBox1->Text == "������� �")
	{
		 zerocheck(StrToInt(LabeledEdit1->Text),StringGrid1);

		 Calc A(StrToInt(LabeledEdit1->Text),StringGrid1);
		 int k = A.determinant(A.arr,A.rows);
		 A.deleting(A.arr, A.rows);
		 Edit2->Text = IntToStr(k);
	}
	else
	{
		 zerocheck(StrToInt(LabeledEdit1->Text),StringGrid2);

		 Calc B(StrToInt(LabeledEdit1->Text),StringGrid2);
		 int k = B.determinant(B.arr,B.rows);
		 B.deleting(B.arr, B.rows);
		 Edit2->Text = IntToStr(k);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	for(int i = /*1*/ 0 ; i <StringGrid3->ColCount;i++)
	{
		for(int j = /*1*/ 0 ; j <StringGrid3->RowCount;j++)
		{
		  StringGrid3->Cells[i][j] = "";
		}
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
  for(int i = /*1*/ 0 ; i <StringGrid1->ColCount;i++)
  {
	for(int j = /* 1 */ 0; j <StringGrid1->RowCount;j++)
	{
	  StringGrid1->Cells[i][j] = "";
	}
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	for(int i = /*1*/ 0 ; i <StringGrid2->ColCount;i++)
	{
		for(int j = /* 1 */ 0; j <StringGrid2->RowCount;j++)
		{
		  StringGrid2->Cells[i][j] = "";
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	 checklabeled(LabeledEdit1);


	 if (ComboBox1->Text == "������� �")
	{
		zerocheck(StrToInt(LabeledEdit1->Text),StringGrid1);

		Calc A(StrToInt(LabeledEdit1->Text),StringGrid1);
		A.transp(A.arr,A.rows,StringGrid3);
	}
	else
	{
		zerocheck(StrToInt(LabeledEdit1->Text),StringGrid2);

		Calc B(StrToInt(LabeledEdit1->Text),StringGrid2);
		B.transp(B.arr,B.rows,StringGrid3);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	checklabeled(LabeledEdit1);


	if (ComboBox1->Text == "������� �")
	{
		  zerocheck(StrToInt(LabeledEdit1->Text),StringGrid1);

		  Calc A(StrToInt(LabeledEdit1->Text),StringGrid1);
		  A.obrmatrix(StringGrid3);
	}
	else
	{
		  zerocheck(StrToInt(LabeledEdit1->Text),StringGrid2);

		  Calc B(StrToInt(LabeledEdit1->Text),StringGrid2);
		  B.obrmatrix(StringGrid3);

	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	  checklabeled(LabeledEdit1);

	  zerocheck(StrToInt(LabeledEdit1->Text),StringGrid1);
	  Calc A(StrToInt(LabeledEdit1->Text),StringGrid1);

	  zerocheck(StrToInt(LabeledEdit1->Text),StringGrid2);
	  Calc B(StrToInt(LabeledEdit1->Text),StringGrid2);

	  A.plus(A.arr,B.arr,A.rows,StringGrid3);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	checklabeled(LabeledEdit1);

	zerocheck(StrToInt(LabeledEdit1->Text),StringGrid1);
	Calc A(StrToInt(LabeledEdit1->Text),StringGrid1);

	zerocheck(StrToInt(LabeledEdit1->Text),StringGrid2);
	Calc B(StrToInt(LabeledEdit1->Text),StringGrid2);

	A.minus(A.arr,B.arr,A.rows,StringGrid3);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
	  checklabeled(LabeledEdit1);

	  zerocheck(StrToInt(LabeledEdit1->Text),StringGrid1);
	  Calc A(StrToInt(LabeledEdit1->Text),StringGrid1);

	  zerocheck(StrToInt(LabeledEdit1->Text),StringGrid2);
	  Calc B(StrToInt(LabeledEdit1->Text),StringGrid2);

	  A.myltyply(B.arr,A.arr,A.rows,StringGrid3);
}
//---------------------------------------------------------------------------



