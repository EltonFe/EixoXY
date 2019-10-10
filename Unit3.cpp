//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "UnitArquivo2.h"
#include "UnitConstrucaoXYZ.h"
#include "UnitEixoXY.h"
#include <fstream>
using std::ifstream;
using std::ios;
//---------------------------------------------------------------------------
#pragma package(smart_init)


#pragma resource "*.dfm"
TForm3 *Form3;
struct Graficos_Variaveis1{


	long double MXo[1000];
	long double LXo[1000];
	long double MYo[1000];
	long double LYo[1000];
    long double MZo[1000];
	long double LZo[1000];

	TColor Color[1000];



	long double AlphaGr;
	float A[1000];
	float B[1000];
	float AZo[1000];
	float BZo[1000];
	float Center[1000][3];
	int Contador;

	int ContadorCircle;
	long double LAlpha[1000];
	long double MAlpha[1000];
	long double MMVetorG[1000];
	long double LMVetorG[1000];

	TPoint P_Circle[1000][51];
	TColor Color_Circle[1000];
	long double AlphaX1;
	float Alpha_Beta_Teta1[3];
	float Alpha_Beta_Teta_Circle[3];
 };
 TColor Color1[1000];
 float Alpha_Beta_Teta_Circle1[3];
 int Kx=900;
int Ky=580;
int Contador1;
TPoint P_Circle1[1000][51];

float MYo1[1000];
float LYo1[1000];
float MXo1[1000];
float LXo1[1000];
 float Alpha_Beta_Teta1[3];
int FullMKx1[1000];
int FullMKy1[1000];
int FullLKx1[1000];
int FullLKy1[1000];

float AlphaX1=0;
TPoint P1[1000][51];
float MZo1[1000];
float MAlpha1[1000];
float MMVetorG1[1000];
float LZo1[1000];
float LAlpha1[1000];
float LMVetorG1[1000];
int   FullMKxDes[1000];
int   FullMKyDes[1000];
int   FullLKxDes[1000];
int   FullLKyDes[1000];
int Fullxy[4][1000];
int Fullxy2[4][1000];
int Fullxy3[4][1000];
int Kx1=300;
int Ky1=370;
int ContadorCircle1;

long double TetaXDes=0;
long double BetaT=M_PI/2;
long double BetaTDes=M_PI/2;
Desenho  Desenho3DS1;
int SentidoAlpha=1;
int SentidoBeta=1;
int SentidoTeta=1;
int Mxyz[3][1000];
int Lxyz[3][1000];
float A1[1000];
float B1[1000];
float AZo1[1000];
float BZo1[1000];
float Center1[1000][3];
TColor Color_Circle1[1000];
void Colorido1(TCanvas *,int );
int RotaXY1(float *,float *,long double ,float ,float ,float , float );
int X1(int ,int);
 int Y1(int ,int);
struct Graficos_Variaveis1 Struct_Grafico;
int EixoXo1(long double xo,long double yo,float zo,  long double *Alphat,long double *MVetorXY);
float EixoXMo1(long double Alphat,long double MVetort);
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{

}
void Le_Arquivo1(char *Nome_Arquivo){
int Contador;
	ifstream Arquivo_RR(Nome_Arquivo,ios::in|ios::binary);
	if(!Arquivo_RR){
	   ShowMessage("Problemas Ao Abrir Arquivo..!!");
	}else{
	 Arquivo_RR.read(reinterpret_cast< char *>(&Contador1),sizeof(Contador1));
	Arquivo_RR.close();



	Sleep(200);
  ifstream Arquivo_WR(Nome_Arquivo,ios::in|ios::binary);
  if(!Arquivo_WR){
		ShowMessage("Problemas Ao Abrir Arquivo..!!");
	}else{
		Arquivo_WR.read(reinterpret_cast< char *>(&Contador1),sizeof(Form2->Contador));
		Arquivo_WR.read(reinterpret_cast< char *>(&ContadorCircle1),sizeof(Form2->ContadorCircle));
		if(Contador1>0){
		Arquivo_WR.read(reinterpret_cast< char *>(MXo1),(Contador1)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(LXo1),(Contador1)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(MYo1),(Contador1)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(LYo1),(Contador1)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(MZo1),(Contador1)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(LZo1),(Contador1)*sizeof(float));

		Arquivo_WR.read(reinterpret_cast< char *>(Color1),(Contador1)*sizeof(TColor));

		Arquivo_WR.read(reinterpret_cast< char *>(MAlpha1),(Contador1)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(LAlpha1),(Contador1)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(MMVetorG1),(Contador1)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(LMVetorG1),(Contador1)*sizeof(float));

		Arquivo_WR.read(reinterpret_cast< char *>(Alpha_Beta_Teta1),sizeof(Alpha_Beta_Teta1));
		}


		if(ContadorCircle1){
		for(int i=0;i<ContadorCircle1;i++)
		Arquivo_WR.read(reinterpret_cast< char *>(Center1[i]),3*sizeof(float));

		Arquivo_WR.read(reinterpret_cast< char *>(AZo1),ContadorCircle1*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(BZo1),ContadorCircle1*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(A1),ContadorCircle1*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(B1),ContadorCircle1*sizeof(float));







		Arquivo_WR.read(reinterpret_cast< char *>(Color_Circle1),ContadorCircle1*sizeof(TColor));

		Arquivo_WR.read(reinterpret_cast< char *>(Alpha_Beta_Teta_Circle1),sizeof(Alpha_Beta_Teta_Circle1));
		}

		ShowMessage("Leitura Completa");
		ShowMessage("Contador..:"+IntToStr(Contador1));
		Arquivo_WR.close();
	}


	}

   ShowMessage("LAlpha[0]..:"+FloatToStr(LAlpha1[0]));
}


void MLimpa2(TCanvas *h,TPoint P[1000][51]){
h->Pen->Color=clWhite;

for(int j=0;j<ContadorCircle1;j++){

h->Polyline(P[j],50);
}

}


void MLimpaBDes(TCanvas *h){
int i=0;
TPoint MP[2];

for (int i = 0; i < Contador1; i++) {









   MP[0].x=FullMKxDes[i];
   MP[0].y=FullMKyDes[i];
   MP[1].x=FullLKxDes[i];
   MP[1].y= FullLKyDes[i];

   h->Pen->Color=clWhite;
   h->Pen->Width=0;
   h->Polyline(MP,1);






}

}



 void MLimpaB2(TCanvas *h){
int i=0;
TPoint MP[2];
for (int i = 0; i <Contador1; i++) {









   MP[0].x=FullMKx1[i];
   MP[0].y=FullMKy1[i];
   MP[1].x=FullLKx1[i];
   MP[1].y= FullLKy1[i];

   h->Pen->Color=clWhite;
   h->Pen->Width=0;


   h->Polyline(MP,1);




}
 }
void Recupera_Arquivo1(struct Graficos_Variaveis1 Grafico_Variavel){
   int i;





	Contador1=Grafico_Variavel.Contador;
	ContadorCircle1=Grafico_Variavel.ContadorCircle;
	Alpha_Beta_Teta1[0]=Grafico_Variavel.Alpha_Beta_Teta1[0];
	Alpha_Beta_Teta1[1]=Grafico_Variavel.Alpha_Beta_Teta1[1];
	Alpha_Beta_Teta1[2]=Grafico_Variavel.Alpha_Beta_Teta1[2];
	Alpha_Beta_Teta_Circle1[0]=Grafico_Variavel.Alpha_Beta_Teta_Circle[0];
	Alpha_Beta_Teta_Circle1[1]=Grafico_Variavel.Alpha_Beta_Teta_Circle[1];
	Alpha_Beta_Teta_Circle1[2]=Grafico_Variavel.Alpha_Beta_Teta_Circle[2];

		for (i = 0; i < Contador1; i++) {
			MAlpha1[i]=Grafico_Variavel.MAlpha[i];
			LAlpha1[i]=Grafico_Variavel.LAlpha[i];
			MMVetorG1[i]=Grafico_Variavel.MMVetorG[i];
			LMVetorG1[i]=Grafico_Variavel.LMVetorG[i];
			MZo1[i]=Grafico_Variavel.MZo[i];
			LZo1[i]=Grafico_Variavel.LZo[i];


			Color1[i]=Grafico_Variavel.Color[i] ;
			Color_Circle1[i]=Grafico_Variavel.Color_Circle[i];
			MYo1[i]=Grafico_Variavel.MYo[i];
			LYo1[i]=Grafico_Variavel.LYo[i];


			MXo1[i]=Grafico_Variavel.MXo[i];
			LXo1[i]=Grafico_Variavel.LXo[i];



		}


	for (int j=0;j<ContadorCircle1;j++){
		A1[j]=Grafico_Variavel.A[j];
		B1[j]=Grafico_Variavel.B[j];
		AZo1[j]=Grafico_Variavel.AZo[j];
		BZo1[j]=Grafico_Variavel.BZo[j];
		Center1[j][0]=Grafico_Variavel.Center[j][0];
		Center1[j][1]=Grafico_Variavel.Center[j][1];
		Center1[j][2]=Grafico_Variavel.Center[j][2];
		Color_Circle1[j]=Grafico_Variavel.Color_Circle[j];


	}



  }
void Colorido_Unico1(TCanvas *h,int i){



		  h->Pen->Color=Color1[i];




}
 int X2(int x){
return x+Kx;
   }
	int Y2(int y){
return Ky-y;
   }

void Rotacao_Vetores_3D1(float xyz[3],float xe,float ye, float ze, float Alpha_Beta_Teta[3]){
  float AX;
  float AY;
  float AZ;
  float T1;
  float T2;
  float T3;
  xyz[0]= Cos( Alpha_Beta_Teta[1])*Cos( Alpha_Beta_Teta[2])*xe - Cos(Alpha_Beta_Teta[1])*Sin(Alpha_Beta_Teta[2])*ye + Sin(Alpha_Beta_Teta[1])*ze;
  T1=Cos( Alpha_Beta_Teta[1])*Cos( Alpha_Beta_Teta[2])*xe;
  T2= - Cos(Alpha_Beta_Teta[1])*Sin(Alpha_Beta_Teta[2])*ye;
  T3=  Sin(Alpha_Beta_Teta[1])*ze;

  AX= RoundTo( (Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Cos(Alpha_Beta_Teta[2])+ Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[2])),-8);
  AY= RoundTo((-Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Sin(Alpha_Beta_Teta[2])+Cos(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[2])),-8);
  AZ= RoundTo(-(Sin(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[1])),-8);

  xyz[1]=AX*xe+AY*ye+AZ*ze;






  xyz[2]=(-Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Cos(Alpha_Beta_Teta[2])+Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[2]))*xe
  +(Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Sin(Alpha_Beta_Teta[2])+Sin(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[2]))*ye
  +Cos(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[1])*ze;


}
void Graphics_Graphi(TCanvas *h){
  float  Mxyz[3];
float Lxyz[3];
float Mxyz1[1000][2];
float Lxyz1[1000][2];
float MZY[2];
float LZY[2];
int i;

TPoint P1[2];
try{
for(i=0;i<Contador1;i++){
if(0){
 Rotacao_Vetores_3D1 (Mxyz,MMVetorG1[i]*Cos(MAlpha1[i]),MMVetorG1[i]*Sin(MAlpha1[i]),-MZo1[i],Alpha_Beta_Teta1);
 Rotacao_Vetores_3D1 (Lxyz,LMVetorG1[i]*Cos(LAlpha1[i]),LMVetorG1[i]*Sin(LAlpha1[i]),-LZo1[i],Alpha_Beta_Teta1);



 }
 if(1){
 Mxyz1[i][0]=(MMVetorG1[i]*Cos(MAlpha1[i]))*(Sin(Alpha_Beta_Teta1[0])*Sin(Alpha_Beta_Teta1[1])*Cos(Alpha_Beta_Teta1[2])+
 Cos(Alpha_Beta_Teta1[0])*Sin(Alpha_Beta_Teta1[2]))+(MMVetorG1[i]*Sin(MAlpha1[i]))*(-Sin(Alpha_Beta_Teta1[0])*Sin(Alpha_Beta_Teta1[1])*Sin(Alpha_Beta_Teta1[2])+
 Cos(Alpha_Beta_Teta1[0])*Cos(Alpha_Beta_Teta1[2]))+MZo1[i]*(-Sin(Alpha_Beta_Teta1[0])*Cos(Alpha_Beta_Teta1[1]));

 Mxyz1[i][1]=(MMVetorG1[i]*Cos(MAlpha1[i]))*(-Cos(Alpha_Beta_Teta1[0])*Sin(Alpha_Beta_Teta1[1])*Cos(Alpha_Beta_Teta1[2])+
 Sin(Alpha_Beta_Teta1[0])*Sin(Alpha_Beta_Teta1[2]))+(MMVetorG1[i]*Sin(MAlpha1[i]))*(Cos(Alpha_Beta_Teta1[0])*Sin(Alpha_Beta_Teta1[1])*Sin(Alpha_Beta_Teta1[2])+
 Sin(Alpha_Beta_Teta1[0])*Cos(Alpha_Beta_Teta1[2]))+MZo1[i]*(Cos(Alpha_Beta_Teta1[0])*Cos(Alpha_Beta_Teta1[1]));

 Lxyz1[i][0]=(LMVetorG1[i]*Cos(LAlpha1[i]))*(Sin(Alpha_Beta_Teta1[0])*Sin(Alpha_Beta_Teta1[1])*Cos(Alpha_Beta_Teta1[2])+
 Cos(Alpha_Beta_Teta1[0])*Sin(Alpha_Beta_Teta1[2]))+( LMVetorG1[i]*Sin(LAlpha1[i]) )*(-Sin(Alpha_Beta_Teta1[0])*Sin(Alpha_Beta_Teta1[1])*Sin(Alpha_Beta_Teta1[2])+
 Cos(Alpha_Beta_Teta1[0])*Cos(Alpha_Beta_Teta1[2]))+LZo1[i]*(-Sin(Alpha_Beta_Teta1[0])*Cos(Alpha_Beta_Teta1[1]));;

 Lxyz1[i][1]=(  LMVetorG1[i]*Cos(LAlpha1[i])  )*(-Cos(Alpha_Beta_Teta1[0])*Sin(Alpha_Beta_Teta1[1])*Cos(Alpha_Beta_Teta1[2])+
 Sin(Alpha_Beta_Teta1[0])*Sin(Alpha_Beta_Teta1[2]))+(LMVetorG1[i]*Sin(LAlpha1[i])  )*(Cos(Alpha_Beta_Teta1[0])*Sin(Alpha_Beta_Teta1[1])*Sin(Alpha_Beta_Teta1[2])+
 Sin(Alpha_Beta_Teta1[0])*Cos(Alpha_Beta_Teta1[2]))+LZo1[i]*(Cos(Alpha_Beta_Teta1[0])*Cos(Alpha_Beta_Teta1[1]));


 }
 P1[0].x=FullMKx1[i]= X1(Mxyz1[i][0],Kx);
 P1[0].y=FullMKy1[i]= Y1(Mxyz1[i][1],Ky);
 P1[1].x=FullLKx1[i]= X1(Lxyz1[i][0],Kx);
 P1[1].y=FullLKy1[i]= Y1(Lxyz1[i][1],Ky);










 Colorido_Unico1(h,i) ;
 h->Polyline(P1,1);

}
}catch(Exception &ex){


}

}

void MLimpa(TCanvas *h,TPoint P[1000][51]){
h->Pen->Color=clWhite;
for(int j=0;j<ContadorCircle1;j++){

h->Polyline(P[j],50);
}

}
void Colororico_Unico_Circle1(TCanvas *h,int i)
{
  h->Pen->Color=Color_Circle1[i];
}
void Rotacao_Vetores_3D_Circle_MP21(float xyz[3],float xe,float ye, float  ze, float Alpha_Beta_Teta[3])
{
  float AX;
  float AY;
  float AZ;
  float T1;
  float T2;
  float T3;
  xyz[0]= Cos( Alpha_Beta_Teta[1]+M_PI/2)*Cos( Alpha_Beta_Teta[2])*xe - Cos(Alpha_Beta_Teta[1]+M_PI/2)*Sin(Alpha_Beta_Teta[2])*ye + Sin(Alpha_Beta_Teta[1]+M_PI/2)*ze;
  T1=Cos( Alpha_Beta_Teta[1]+M_PI/2)*Cos( Alpha_Beta_Teta[2])*xe;
  T2= - Cos(Alpha_Beta_Teta[1]+M_PI/2)*Sin(Alpha_Beta_Teta[2])*ye;
  T3=  Sin(Alpha_Beta_Teta[1]+M_PI/2)*ze;

  AX= RoundTo( (Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1]+M_PI/2)*Cos(Alpha_Beta_Teta[2])+ Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[2])),-8);
  AY= RoundTo((-Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1]+M_PI/2)*Sin(Alpha_Beta_Teta[2])+Cos(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[2])),-8);
  AZ= RoundTo(-(Sin(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[1]+M_PI/2)),-8);

  xyz[1]=AX*xe+AY*ye+AZ*ze;






  xyz[2]=(-Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1]+M_PI/2)*Cos(Alpha_Beta_Teta[2])+Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[2]))*xe
  +(Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1]+M_PI/2)*Sin(Alpha_Beta_Teta[2])+Sin(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[2]))*ye
  +Cos(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[1]+M_PI/2)*ze;


}

void Circle_Vetor1(float A[1000],float AZ[1000],float B[1000],float BZ[1000],TPoint P[1000][51],float Center[1000][3]){


float sx1=300;
float sy1=150;
float sz1;
float x1;
float y1;
float Circle_XYZ[3];
long double  Ang;
long double  MVetor;
float Cnd=0;
float AngVar=((2*M_PI)/50);


for(int j=0;j<ContadorCircle1;j++){

		for (int i=0;i<51;i++){


		sx1=A[j]*Cos((i*((2*M_PI)/50)))+Center[j][0];
		sy1=B[j]*Sin(i*((2*M_PI)/50))+Center[j][1];
		sz1=AZ[j]*Cos((i*((2*M_PI)/50)))+BZ[j]*Sin((i*((2*M_PI)/50)))+Center[j][2];




		EixoXo1(sx1,sy1,0,&Ang,&MVetor);



				  Rotacao_Vetores_3D_Circle_MP21( Circle_XYZ,sx1,sy1,sz1,Alpha_Beta_Teta_Circle1);




		P_Circle1[j][i].x= X2(Circle_XYZ[0]);
		P_Circle1[j][i].y= Y2(Circle_XYZ[1]);
		}





	Colororico_Unico_Circle1(Form3->Canvas,j);
	Form3->Canvas->Polyline(P_Circle1[j],50);

	}

}
int EixoXo1(long double xo,long double yo,float zo,  long double *Alphat,long double *MVetorXY){

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
int EixoYMo(float zo,float Alphat,float Betat, float MVetort){



	  if (zo<=0) {
	  zo=-zo;
	  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }


  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);


}
//---------------------------------------------------------------------------
float EixoXMo1(long double Alphat,long double MVetort){

	return  MVetort*Cos(Alphat);

}
void Circle1(float A[1000],float AZ[1000],float B[1000],float BZ[1000],TPoint P[1000][51],float Center[1000][3]){

float sx1=300;
float sy1=150;
float sz1;
float x1;
float y1;
long double Ang;
long double MVetor;
float Cnd=0;
float AngVar=((2*M_PI)/50);
for(int j=0;j<ContadorCircle1;j++){
for (int i=0;i<51;i++){


sx1=A[j]*Cos((i*((2*M_PI)/50)))+Center[j][0];
sy1=B[j]*Sin(i*((2*M_PI)/50))+Center[j][1];
sz1=AZ[j]*Cos((i*((2*M_PI)/50)))+BZ[j]*Sin((i*((2*M_PI)/50)))+Center[j][2];




EixoXo1(sx1,sy1,0,&Ang,&MVetor);

x1=EixoXMo1(Ang+AlphaX1,MVetor);
y1=EixoYMo(sz1,Ang+AlphaX1,BetaTDes,MVetor);

RotaXY1(&x1,&y1,sz1,Ang+AlphaX1,BetaTDes,MVetor,TetaXDes);

P[j][i].x= X1(x1,Kx1);
P[j][i].y= Y1(y1,Ky1);
}
Form3->Canvas->Pen->Color=clGreen;
Form3->Canvas->Polyline(P[j],50);

}

}

void GiraAlpha(int h){
if (h>0){

if(Contador1>0)
Alpha_Beta_Teta1[0]+=M_PI/50;
if(ContadorCircle1>0)
Alpha_Beta_Teta_Circle1[0]+=M_PI/50;
} else{

if(Contador1>0)
Alpha_Beta_Teta1[0]-=M_PI/50;
if(ContadorCircle1>0)
Alpha_Beta_Teta_Circle1[0]-=M_PI/50;

}



}

void GiraBeta(int h){
if (h>0){
if(Contador1>0)
Alpha_Beta_Teta1[1]+=M_PI/50;
if(ContadorCircle1>0)
Alpha_Beta_Teta_Circle1[1]+=M_PI/50;

} else{
if(Contador1>0)
 Alpha_Beta_Teta1[1]-=M_PI/50;
 if(ContadorCircle1>0)
Alpha_Beta_Teta_Circle1[1]-=M_PI/50;
	}
}

void GiraTeta(int h){
if (h>0){
if(Contador1>0)
Alpha_Beta_Teta1[2]+=M_PI/50;
if(ContadorCircle1>0)
Alpha_Beta_Teta_Circle1[2]+=M_PI/50;

} else{
if(Contador1>0)
 Alpha_Beta_Teta1[2]-=M_PI/50;
 if(ContadorCircle1>0)
Alpha_Beta_Teta_Circle1[2]-=M_PI/50;
	}
}



 void MLimpaB1(TCanvas *h){
int i=0;
TPoint MP[2];
for (int i = 0; i < Contador1; i++) {
   MP[0].x=FullMKxDes[i];
   MP[0].y=FullMKyDes[i];
   MP[1].x=FullLKxDes[i];
   MP[1].y= FullLKyDes[i];

   h->Pen->Color=clWhite;
   h->Pen->Width=0;


   h->Polyline(MP,1);
}




}
void MLimpaB1Des(TCanvas *h,int Fullxy1[4][1000]){
int i=0;
TPoint MP[2];
for (int i = 0; i < Contador1; i++) {
   MP[0].x=Fullxy1[0][i];
   MP[0].y=Fullxy1[1][i];
   MP[1].x=Fullxy1[2][i];
   MP[1].y= Fullxy1[3][i];

   h->Pen->Color=clWhite;
   h->Pen->Width=0;


   h->Polyline(MP,1);
}




}

void RecuperaDes(Desenho Des){
for(int i=0;i<Contador1;i++){
MAlpha1[i]=Des.GetMAlpha(i);
MMVetorG1[i]=Des.GetMMVetorGr(i);
LAlpha1[i]=Des.GetLAlpha(i);
LMVetorG1[i]=Des.GetLMVetorGr(i);
MZo1[i]=Des.GetMzo(i);
LZo1[i]=Des.GetLzo(i);

}
BetaTDes=Des.BetaT;
AlphaX1=Des.GetAlphaX1();
for (int j=0;j<ContadorCircle1;j++){
A1[j]=Des.GetA(j);
B1[j]=Des.GetB(j);
AZo1[j]=Des.GetAZo(j);
BZo1[j]=Des.GetBZo(j);
Des.GetCenter(j,Center1);


}



}


int X1(int x,int Kx){
return x+Kx;
   }

   int Y1(int y,int Ky){
return Ky-y;
   }

int RotaXY1(float *x1,float *y1,long double zo,float Alphat,float Betat,float MVetort, float Teta){
	 float k;
     if (zo<=0) {
	  zo=-zo;
	  k= MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }else
	  k=MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);

	*x1= (MVetort*Cos(Alphat))*Cos(Teta) + (k)*Sin(Teta);
	*y1= -(MVetort*Cos(Alphat))*Sin(Teta)+ (k)*Cos(Teta);




}

   void Grafics5(TCanvas *h){
 TPoint MP[2];
 float kx1[2];
 float ky1[2];



 for (int i = 0; i < Contador1; i++) {


  RotaXY1(&kx1[0],&ky1[0],MZo1[i],MAlpha1[i],BetaTDes,MMVetorG1[i],TetaXDes);
  RotaXY1(&kx1[1],&ky1[1],LZo1[i],LAlpha1[i],BetaTDes,LMVetorG1[i],TetaXDes);



int  MLLkx= X1(kx1[0],Kx1);
int   MLLky= Y1(ky1[0],Ky1) ;
int   LLLkx= X1(kx1[1],Kx1);
int   LLLky=Y1(ky1[1],Ky1);
   FullMKxDes[i]=MLLkx;
   FullMKyDes[i]=MLLky;
   FullLKxDes[i]=LLLkx;
   FullLKyDes[i]=LLLky;
   MP[0].x=MLLkx;
   MP[0].y=MLLky;
   MP[1].x=LLLkx;
   MP[1].y= LLLky;

   h->Pen->Color=clGreen;
   h->Pen->Width=0;


   h->Polyline(MP,1);




}

}
  void Grafics6(TCanvas *h,int Kx1,int Ky1,int Fullxy1[4][1000]){
 TPoint MP[2];
 float kx1[2];
 float ky1[2];



 for (int i = 0; i < Contador1; i++) {


  RotaXY1(&kx1[0],&ky1[0],MZo1[i],MAlpha1[i],BetaTDes,MMVetorG1[i],TetaXDes);
  RotaXY1(&kx1[1],&ky1[1],LZo1[i],LAlpha1[i],BetaTDes,LMVetorG1[i],TetaXDes);



int  MLLkx= X1(kx1[0],Kx1);
int   MLLky= Y1(ky1[0],Ky1) ;
int   LLLkx= X1(kx1[1],Kx1);
int   LLLky=Y1(ky1[1],Ky1);
   Fullxy1[0][i]=MLLkx;
   Fullxy1[1][i]=MLLky;
   Fullxy1[2][i]=LLLkx;
   Fullxy1[3][i]=LLLky;
   MP[0].x=MLLkx;
   MP[0].y=MLLky;
   MP[1].x=LLLkx;
   MP[1].y= LLLky;

   Colorido1(Form3->Canvas,i);
   h->Pen->Width=0;


   h->Polyline(MP,1);




}

}
void __fastcall TForm3::Button1Click(TObject *Sender)
{
int Posi;

int i=0;
int j=0;
int kx=0;
int ky=0;
TPoint MP[2];
char Chr;



 UnicodeString FileNome;
char FileUni[500];

if (OpenDialog1->Execute()){

FileNome=OpenDialog1->FileName;
}
int Cont= FileNome.Length();
for(i=0;i<FileNome.Length();i++){
FileUni[i]=FileNome[i+1];

}


FileUni[Cont]='\0';
ShowMessage(FileUni);







if(0){
ifstream Recupera(FileUni,ios::in|ios::binary);

if (!Recupera) {
	ShowMessage("Arquivo Não Pode Ser Lido...");
}else {

while ((Recupera)&&(!Recupera.eof())){
Recupera.read(reinterpret_cast<char *>(&Struct_Grafico),sizeof (Struct_Grafico));

	 }
}
Recupera.close();
Contador1=Struct_Grafico.Contador;
ContadorCircle1= Struct_Grafico.ContadorCircle;


 Recupera_Arquivo1( Struct_Grafico);
}
Le_Arquivo1(FileUni);

 Graphics_Graphi(Form3->Canvas);
 Circle_Vetor1(A1,AZo1,B1,BZo1,P1,Center1);

   if(0){
   Circle1(A1,AZo1,B1,BZo1,P1,Center1);
   Grafics6(Form3->Canvas,Kx1,Ky1,Fullxy);
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
if ((CheckBox1->Checked)||(CheckBox2->Checked)||(CheckBox3->Checked)){


 MLimpaB2(Form3->Canvas);



 MLimpa2(Form3->Canvas,P_Circle1);
 Circle_Vetor1(A1,AZo1,B1,BZo1,P1,Center1);
 Graphics_Graphi(Form3->Canvas);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RadioButton1Click(TObject *Sender)
{
SentidoAlpha=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RadioButton2Click(TObject *Sender)
{
SentidoAlpha=-1;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RadioButton3Click(TObject *Sender)
{
SentidoBeta=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RadioButton4Click(TObject *Sender)
{
SentidoBeta=-1;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RadioButton5Click(TObject *Sender)
{
SentidoTeta=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RadioButton6Click(TObject *Sender)
{
SentidoTeta=-1;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Timer2Timer(TObject *Sender)
{
if( CheckBox1->Checked){
GiraAlpha(SentidoAlpha);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Timer3Timer(TObject *Sender)
{
if (CheckBox2->Checked){
GiraBeta(SentidoBeta);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Timer4Timer(TObject *Sender)
{
if (CheckBox3->Checked){
GiraTeta(SentidoTeta);}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
if (Timer2->Interval>80){
Timer2->Interval= Timer2->Interval-50;
}
if (Timer2->Interval>40){
Timer2->Interval= Timer2->Interval-20;
}
if (Timer2->Interval>10){
Timer2->Interval= Timer2->Interval-2;
}
if (Timer2->Interval==0){
Timer2->Interval=1;
}
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Button5Click(TObject *Sender)
{
long double Ang;
long double Vetor;



}
//---------------------------------------------------------------------------
 void Colorido1(TCanvas *h,int i){

int  j;
j=i%7;

if (j==0){
h->Pen->Color=clGreen;

}
if(j==1){

h->Pen->Color=clYellow;
}
if (j==2){

h->Pen->Color=clLime;
}
if (j==3){
 h->Pen->Color=clPurple;

}
if (j==4){
h->Pen->Color=clRed;
}

if (j==5){

h->Pen->Color=clBlue;

}
if (j==6){

h->Pen->Color=clGray;
}







}


void __fastcall TForm3::Button3Click(TObject *Sender)
{
if (Timer3->Interval>80){
Timer3->Interval= Timer3->Interval-50;
}
if (Timer3->Interval>40){
Timer3->Interval= Timer3->Interval-20;
}
if (Timer3->Interval>10){
Timer3->Interval= Timer3->Interval-2;
}
if (Timer3->Interval==0){
Timer3->Interval=1;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button4Click(TObject *Sender)
{
if (Timer4->Interval>80){
Timer4->Interval= Timer4->Interval-50;
}
if (Timer4->Interval>40){
Timer4->Interval= Timer4->Interval-20;
}
if (Timer4->Interval>10){
Timer4->Interval= Timer4->Interval-2;
}
if (Timer4->Interval==0){
Timer4->Interval=1;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormCreate(TObject *Sender)
{
Alpha_Beta_Teta_Circle1[1]=-M_PI/2;
Alpha_Beta_Teta_Circle1[0]=0;
Alpha_Beta_Teta_Circle1[2]=0;
}
//---------------------------------------------------------------------------

