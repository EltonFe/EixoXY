//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>


#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TOpenDialog *OpenDialog1;
	TTimer *Timer1;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TPanel *Panel1;
	TRadioButton *RadioButton1;
	TPanel *Panel2;
	TRadioButton *RadioButton2;
	TPanel *Panel3;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	TPanel *Panel4;
	TRadioButton *RadioButton5;
	TRadioButton *RadioButton6;
	TTimer *Timer2;
	TTimer *Timer3;
	TTimer *Timer4;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TLabel *Label1;
	TPanel *Panel5;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall RadioButton1Click(TObject *Sender);
	void __fastcall RadioButton2Click(TObject *Sender);
	void __fastcall RadioButton3Click(TObject *Sender);
	void __fastcall RadioButton4Click(TObject *Sender);
	void __fastcall RadioButton5Click(TObject *Sender);
	void __fastcall RadioButton6Click(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall Timer3Timer(TObject *Sender);
	void __fastcall Timer4Timer(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations

public:		// User declarations
	__fastcall TForm3(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
