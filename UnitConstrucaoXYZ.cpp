//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitConstrucaoXYZ.h"
#include "UnitDesenha3ds.h"
#include "UnitEixoXY.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
VetorDes3Ds Desenho3D(M_PI/2);
long double MMVetor1;
long double LMVetor1;
long double MAlpha1;
 long double LAlpha1;
long double BetaT1=M_PI/2;
bool Move1=false;
int Contador1=2;
int Cont;
int Contador1M=0;
long double MMVetor2[1000];
long double LMVetor2[1000];
long double MAlpha2[1000];
 long double LAlpha2[1000];
 long double MZo[1000];
 long double LZo[1000];
 int ContadorRecup=0;
 long double Ang;
 void Eixos1(TCanvas *);


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
if (Form1->Visible){
Edit1->SetFocus();
}
}
int EixoXo2(long double xo,long double yo,float zo,  long double *Alphat,long double *MVetorXY){

long double MXYVetor;

long double MVetorXY1;
long double Alphat1=0;






MVetorXY1=Sqrt((xo*xo) +(yo*yo));
if (MVetorXY1==0){

MVetorXY1=1;

}

MXYVetor=MVetorXY1;


 *MVetorXY=MVetorXY1;

   if (xo==0) {
	if (yo>0){
	  *Alphat=M_PI/2;
  Alphat1=asin(1.0);
  return 0;

	}
	 if (yo<0) {
	   *Alphat=M_PI+M_PI/2;
  Alphat1=asin(-1.0);
  return 0;
	 }

}else{

	  if (yo==0) {

		 Alphat1=acos(xo/MVetorXY1);

	  }

	  if ((xo<0)&&(yo<0)) {
		 xo=-xo;

		 Alphat1=acos(xo/MVetorXY1)+M_PI;
		 xo=-xo;



	  }


   if ((xo<0)&&(yo>0)) {
		xo=-xo;

			Alphat1=M_PI-acos(xo/MVetorXY1);

		xo=-xo;
   }

	 if ((xo>0)&&(yo<0)) {
		 Alphat1=2*M_PI-acos(xo/MVetorXY1);

	 }
	 if ((xo>0)&&(yo>0)) {
		 Alphat1=acos(xo/MVetorXY1);

	 }

	  }

	 if (MVetorXY1<=0) {
	   *MVetorXY=0;
	   return 0;
		}
	*Alphat=Alphat1;
   return floor( MXYVetor*Cos(Alphat1));



}
int TForm1::EixoXo2Move(long double xo,long double yo,float zo,  long double *Alphat,long double *MVetorXY){

long double MXYVetor;

long double MVetorXY1;
long double Alphat1=0;






MVetorXY1=Sqrt((xo*xo) +(yo*yo));
if (MVetorXY1==0){

MVetorXY1=1;

}

MXYVetor=MVetorXY1;


 *MVetorXY=MVetorXY1;

   if (xo==0) {
	if (yo>0){
	  *Alphat=M_PI/2;
  Alphat1=asin(1.0);
   return 0;

	}
	 if (yo<0) {
	   *Alphat=M_PI+M_PI/2;
  Alphat1=asin(-1.0);
  return 0;
	 }

}else{

	  if (yo==0) {

		 Alphat1=acos(xo/MVetorXY1);

	  }

	  if ((xo<0)&&(yo<0)) {
		 xo=-xo;

		 Alphat1=acos(xo/MVetorXY1)+M_PI;
		 xo=-xo;



	  }


   if ((xo<0)&&(yo>0)) {
		xo=-xo;

			Alphat1=M_PI-acos(xo/MVetorXY1);

		xo=-xo;
   }

	 if ((xo>0)&&(yo<0)) {
		 Alphat1=2*M_PI-acos(xo/MVetorXY1);

	 }
	 if ((xo>0)&&(yo>0)) {
		 Alphat1=acos(xo/MVetorXY1);

	 }

	  }

	 if (MVetorXY1<=0) {
	   *MVetorXY=0;
	   return 0;
		}
	*Alphat=Alphat1;

    return floor( MXYVetor*Cos(Alphat1));


}
int EixoYo2(float zo, long double Alphat,float Betat,float MVetor){




  if (zo<=0) {
  zo=-zo;
		 return floor(MVetor*Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat));
	 }


  return MVetor*Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);



}
int EixoYo2Move(float zo, long double Alphat,float Betat,float MVetor){




  if (zo<=0) {
  zo=-zo;
		 return floor(MVetor*Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat));
	 }


  return MVetor*Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);



}

//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
 if (Key=='\r'){

 Edit2->SetFocus();

 }



}
//---------------------------------------------------------------------------





void __fastcall TForm1::Edit2KeyPress(TObject *Sender, System::WideChar &Key)
{
int kx;
int ky;
int kx1;
int ky1;


if (Key=='\r'){

  Edit3->SetFocus();

}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit3KeyPress(TObject *Sender, System::WideChar &Key)
{

int kx;
int ky;
int kx1;
int ky1;
float j;
int i;
i=Contador1%2;
if (Key=='\r'){
long double xo=StrToFloat(Edit1->Text);
long double yo=StrToFloat(Edit2->Text);
 long double zo=Edit3->Text.ToDouble();
  if (i==0){

  EixoXo2(xo,yo,0,&MAlpha1,&MMVetor1);
  EixoYo2(zo,MAlpha1,BetaT1,MMVetor1);
  Label1->Caption="P:"+IntToStr(Contador1M)+"1 XYZ={"+FloatToStr(xo)+" , "+FloatToStr(yo)+" , "+FloatToStr(zo)+" }; º";

  }
  if (i==1){
	  Desenho3D.SetLZo(zo,Contador1M);
	 Desenho3D.EixoXo(xo,yo,&MAlpha1,&MMVetor1);
	Desenho3D.EixoYo(zo,MAlpha1,BetaT1,MMVetor1);
   Desenho3D.SetLAlpha(MAlpha1,Contador1M);
   Desenho3D.SetLMVetorG(MMVetor1,Contador1M);
	Desenho3D.SetBetaT(M_PI/2);
	Label2->Caption="P:"+IntToStr(Contador1M)+"2 XYZ={"+FloatToStr(xo)+" , "+FloatToStr(yo)+" , "+FloatToStr(xo)+" }; º";
	Desenho3D.SetPosi1(Contador1M+1);
	ShowMessage("j: "+FloatToStr(j));
   Contador1++;

  }


}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
int j=0;
 long double Ang;
 long double Mtar;
long double xo;
long double yo;
long double zo;

Form2->Color[Form2->Contador]=Form2->ColorBox1->Selected;
 if (Form2->RadioXoY->Checked) {
	 Form2->CheckBox2->Checked=true;

 }

 if (Form2->RadioZoX->Checked) {

	Form2->CheckBox2->Checked=true;
 }

 if (Edit1->Text.IsEmpty()){
 Edit1->Text="0";
 xo=0;
 }
 if(Edit2->Text.IsEmpty()){
 Edit2->Text="0";
 yo=0;
 }
 if(Edit3->Text.IsEmpty()){
 Edit3->Text="0";
 zo=0;
 }
xo=Edit1->Text.ToDouble();
yo=Edit2->Text.ToDouble();
zo=Edit3->Text.ToDouble();

  j=Cont%2;

Form2->MAlpha=(float *)realloc(Form2->MAlpha,(Form2->Contador+1)*sizeof(float ));
Form2->LAlpha=(float *)realloc(Form2->LAlpha,(Form2->Contador+1)*sizeof(float ));
Form2->MMVetorG=(float *)realloc(Form2->MMVetorG,(Form2->Contador+1)*sizeof(float ));
Form2->LMVetorG=(float *)realloc(Form2->LMVetorG,(Form2->Contador+1)*sizeof(float ));
Form2->MZo=(float *)realloc(Form2->MZo,(Form2->Contador+1)*sizeof(float ));
Form2->LZo=(float *)realloc(Form2->LZo,(Form2->Contador+1)*sizeof(float ));

 if (j==0){

 Form2->MZo[Form2->Contador]=zo;

  EixoXo2(xo,yo,0,&Ang,&Mtar);





   Form2->MAlpha[Form2->Contador]=Ang+Form2->AlphaGr;
   Form2->MMVetorG[Form2->Contador]=Mtar;

   Label1->Font->Color=clBlue;
   Label1->Caption="P" + IntToStr(Form2->Contador)+" : "+IntToStr(0)+"{ "+FloatToStr(xo)+ " , "+FloatToStr(yo)+" ,"+FloatToStr(zo)+" }; °°°";
   Cont++;
 } if (j==1)
   {
  Form2->LZo[Form2->Contador]=zo;

  EixoXo2(xo,yo,0,&Ang,&Mtar);

  Cont++;
  Label2->Font->Color=clBlue;
  Label2->Caption="P" + IntToStr(Form2->Contador)+" : "+IntToStr(1)+"{ "+FloatToStr(xo)+ " , "+FloatToStr(yo)+" ,"+FloatToStr(zo)+" }; °°°";



   Form2->LAlpha[Form2->Contador]=Ang;
   Form2->LMVetorG[Form2->Contador]=Mtar;


 Form2->Contador=Form2->Contador+1;


 }
 Edit1->Text="0,0";
 Edit2->Text="0,0";
 Edit3->Text="0,0";
 Sleep(2000);



 }
 void TForm1::XYZO(long double Vetor[1000],long double Alphat[1000], long double Mzo[1000], int Mxyz[3][1000],int Contador){
 for (int i=0;i<Contador;i++){
 Mxyz[0][i]=Vetor[i]*Cos(Alphat[i]);
 Mxyz[1][i]=Vetor[i]*Sin(Alphat[i]);
 Mxyz[2][i]=Mzo[i];
 }

 }

void XYZ(long double xo,long double yo, long double zo,long double xyz[3][1000]){
xyz[0][Form2->Contador]=xo;
xyz[1][Form2->Contador]=yo;
xyz[2][Form2->Contador]=zo;

}


//---------------------------------------------------------------------------
void Desenhando(){







}

