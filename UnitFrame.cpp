//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFrame.h"
#include "UnitArquivoG3D.h"
#include <fstream>
using std::ifstream;
using std::ios;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrame1 *Frame1;

//---------------------------------------------------------------------------
__fastcall TFrame1::TFrame1(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------

