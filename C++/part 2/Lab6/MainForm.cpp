//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include <cstring>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	isEncrypt = true;
	crypter = new CaesarCrypt(1);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	AnsiString text = Edit1->Text;
	int lenght = text.Length();
	char* data = new char[lenght];
	strcpy(data, text.c_str());
	char* result;
	if(isEncrypt)
	{
		result = crypter->Encrypt(data, lenght);
	}
	else
	{
		result = crypter->Decrypt(data, lenght);
	}
	LabelResult->Caption = AnsiString(result);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
	isEncrypt = !isEncrypt;
}
//---------------------------------------------------------------------------

