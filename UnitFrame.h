//---------------------------------------------------------------------------

#ifndef UnitFrameH
#define UnitFrameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFrame1 : public TFrame
{
__published:	// IDE-managed Components
	TButton *Button1;
	TOpenDialog *OpenDialog1;
	TImage *Image2;
private:	// User declarations
public:		// User declarations
	__fastcall TFrame1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame1 *Frame1;
//---------------------------------------------------------------------------
#endif
