//---------------------------------------------------------------------------

#ifndef UnitConstrucaoXYZH
#define UnitConstrucaoXYZH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>


//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TLabel *Label1;
	TLabel *Label2;
	TButton *Button1;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit3KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	  void XYZO(long double[1000] ,long double[1000] , long double[1000] , int [3][1000],int);

	  int EixoXo2Move(long double ,long double ,float ,  long double * ,long double * );
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
