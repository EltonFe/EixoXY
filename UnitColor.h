//---------------------------------------------------------------------------

#ifndef UnitColorH
#define UnitColorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
	TRadioButton *RadioclBlack;
	TRadioButton *Radio_clYellow;
	TRadioButton *Radio_clBlue;
	TRadioButton *Radio_clPurple;
	TRadioButton *Radio_clLime;
	TRadioButton *Radio_clGreen;
	TRadioButton *Radio_clGray;
	TRadioButton *Radio_clAqua;
private:	// User declarations
public:		// User declarations
	__fastcall TForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
