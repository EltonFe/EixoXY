//---------------------------------------------------------------------------

#ifndef UnitEixoXYH
#define UnitEixoXYH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.Math.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Menus.hpp>
#include "Arquivo.h"
using Name_Arquivos::Objetos;
using Name_Arquivos::Arquivo;


//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TButton *Button22;
	TTimer *Timer1;
	TButton *Button24;
	TButton *Button25;
	TEdit *Edit1;
	TLabel *Label2;
	TPanel *Panel2;
	TCheckBox *CheckBox1;
	TPanel *Panel3;
	TRadioButton *RadioXoY;
	TRadioButton *RadioZoX;
	TPanel *Panel4;
	TRadioButton *RXoY;
	TRadioButton *RZoX;
	TPanel *Panel5;
	TEdit *Edit2;
	TLabel *Label4;
	TRadioButton *Cancel;
	TPanel *Panel6;
	TRadioButton *BetaT0;
	TRadioButton *BetaTMPI2;
	TRadioButton *RadioButton3;
	TButton *ButtonSalvar;
	TButton *ButtonRecupera;
	TSaveDialog *SaveDialog1;
	TOpenDialog *OpenDialog1;
	TButton *Button29;
	TButton *Button30;
	TPanel *Panel7;
	TButton *Button31;
	TButton *Button32;
	TButton *Button33;
	TButton *Button34;
	TPanel *Panel8;
	TLabel *Label7;
	TButton *Close;
	TPopupMenu *PopupMenu1;
	TMenuItem *LimpaDesenho1;
	TLabel *Label1;
	TTimer *Timer2;
	TMenuItem *PontoaPonto1;
	TButton *Button35;
	TPanel *Panel9;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TButton *Button36;
	TLabel *Label3;
	TLabel *Label5;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TCheckBox *CheckBox2;
	TMenuItem *Form31;
	TMenuItem *ConstruoEIxoXYZ1;
	TLabel *Label12;
	TMenuItem *ConstruoElipse1;
	TLabel *Label6;
	TPanel *Panel10;
	TEdit *Edit6;
	TEdit *Edit7;
	TLabel *Label8;
	TLabel *Label13;
	TTimer *Timer3;
	TColorBox *ColorBox1;
	TMenuItem *Voltar1;
	TMenuItem *VoltarCirculo1;
	TLabel *Label14;


















	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Button22Click(TObject *Sender);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);

	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button24Click(TObject *Sender);
	void __fastcall Button25Click(TObject *Sender);
	void __fastcall Edit1DblClick(TObject *Sender);


	void __fastcall Button28Click(TObject *Sender);
	void __fastcall RadioZoXClick(TObject *Sender);
	void __fastcall RadioXoYClick(TObject *Sender);
	void __fastcall BetaT0Click(TObject *Sender);
	void __fastcall BetaTMPI2Click(TObject *Sender);
	void __fastcall ButtonSalvarClick(TObject *Sender);
	void __fastcall ButtonRecuperaClick(TObject *Sender);



	void __fastcall RadioButton1Click(TObject *Sender);
	void __fastcall Button29Click(TObject *Sender);
	void __fastcall Button30Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall LimpaDesenho1Click(TObject *Sender);
	void __fastcall PontoaPonto1Click(TObject *Sender);
	void __fastcall Button36Click(TObject *Sender);

	void __fastcall RZoXClick(TObject *Sender);
	void __fastcall Button35Click(TObject *Sender);
	void __fastcall Form31Click(TObject *Sender);
	void __fastcall RXoYClick(TObject *Sender);
	void __fastcall ConstruoEIxoXYZ1Click(TObject *Sender);
	void __fastcall ConstruoElipse1Click(TObject *Sender);
	void __fastcall RadioButton3Click(TObject *Sender);
	void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Button32Click(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall Edit6Enter(TObject *Sender);
	void __fastcall Edit7Enter(TObject *Sender);
	void __fastcall Button34Click(TObject *Sender);
	void __fastcall Button31Click(TObject *Sender);
	void __fastcall Button33Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Voltar1Click(TObject *Sender);
	void __fastcall VoltarCirculo1Click(TObject *Sender);
	void __fastcall Timer3Timer(TObject *Sender);
	void __fastcall CloseClick(TObject *Sender);


private:	// User declarations
public:
Objetos * objetos;
DWORD *Color;

int Color_Camada_Count;
float  BetaT;
float  AlphaGr;
float *A;
float *B;
float *AZo;
float *BZo;
float **Center;
float *Center_Vetor;
float *Center_Angulo;
int Contador;
int ContadorCircle;
float  *LAlpha;
float  *MAlpha;
float  *MMVetorG;
float  *LMVetorG;

float  *MZo;
float  *LZo;
float *MXo;
float *LXo;
int Soma_100;

TPoint **P_Circle;
bool Lancar;
bool Eixo_Lancar;
float  t;
void MLimpa(TCanvas *,TPoint **);
void Circle(float [1000],float[1000],float[1000],float[1000],TPoint **,float ** );
void Circle_Vetor(float *,float *,float *,float *,TPoint **,float ** );
void Colorido_Unico(TCanvas *h,int i);
TColor *Color_Circle;
void Colororico_Unico_Circle(TCanvas *h,int i);
void Circle_VetorXZ(float *A,float *AZ,float *B,float *BZ,TPoint **P,float **Center);
	// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
