//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "UnitEixoXY.h"
#include "UnitArquivo2.h"
#include "Unit3.h"
#include <fstream>
using std::ifstream;

#include <string.h>
#include <math.h>
#include "UnitConstrucaoXYZ.h"
#include "UnitColor.h"
#include "UnitElipse.h"

using Name_Arquivos::Objetos;
using Name_Arquivos::Arquivo;
using Name_Arquivos::Atributos;
using std::string;
using std::ostream;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//----------------------------------------------------------------------------

float Alpha_Beta_Teta_Circle[3];
float Kxyz[3];
float Angulo_Circle=0;
float MAngulo_X[100];
float LAngulo_X[100];
float MAngulo_Y[100];
float LAngulo_Y[100];
float MVetor_Y[100];
float LVetor_Y[100];
float MZo_Y[100];
float LZo_Y[100];
float LBeta[100];
float MBeta[100];
float MZo_X[100];
float LZo_X[100];
int Counter=0;
int Counter1=0;
float Angulo;
float BetaTDes=M_PI/2;
TPoint MP[2];
TPoint P1;
 int j=0;
int KOOx2=900;
int KOOy2=430;
int kx1;
int ky1;
int kx2=0;
int ky2=0;
float TetaX1=0;
float AlphaX1=0;
int Kx=900;
int Ky=580;
int KOx=900;
int KOy=580;
int KxO;
int KxOO=0;
int KyOO=500;
int Contar=0;
int Cont=2;
bool Move=false;
float LMVetorG[1000];
float MVetorG[1000];
int Y (int y);
int X (int x);
float EixoX(float xo,float yo,float zo,float *Alphat,float *Betat,float Tetat,float *MVetor);
float EixoY(float xo,float yo,float zo, float *Alphat,float Betat,float Tetat,float MVetor);
int Configura(float , int );
int EixoXo(float xo,float yo,float zo,  float *Alphat,float *MVetorXY);
float OX(float x);
float OY(float y);
void Colorido(TCanvas *,int );
int Zo[1000];
int *MYo;
int *LYo;
int Yo[1000];
int LMkx[1000];
int LLkx[1000];
int LMky[1000];
int LLky[1000];
int LBMkx[1000];
int LBLkx[1000];
int LBMky[1000];
int LBLky[1000];
float MVetor[100];
float LVetor[100];
float AngVetor;
float Mxyz[3];
float Lxyz[3];
//-------------------------------------------------------------------------------------------------------
Desenho Desenho3DS;
//-------------------------------------------------------------------------------------------------------
void MLimpaB(TCanvas *);
void GravaArquivo();
void RecebeUnicode(char *,UnicodeString);
void Eixos(TCanvas *);
float TetaX=0;
int FullMKx[1000];
int FullMKy[1000];
int FullLKx[1000];
int FullLKy[1000];
int FullMKxDes[1000];
int FullMKyDes[1000];
int FullLKxDes[1000];
int FullLKyDes[1000];
float AlphaGr=0.0;
int  Kr=1;
float Alpha_Beta_Teta[3];
float Alpha_Beta_Teta_X[3];
float Alpha_Beta_Teta_Y[3];
float Alpha_Alter=0;
float Beta_Alter=0;
float Teta_Alter=0;
float Mxyz1[100][3];
float Lxyz1[100][3];
void Limpa_Orientacao(TCanvas *);
void Rotacao_Vetores_3D(float xyz[3],float xe,float ye, float ze, float Alpha_Beta_Teta[3]);
void Graphics_Rotacao(TCanvas *,float Alpha_Beta_Teta[3]);
int EixoYMo(float zo,float Alphat,float Betat, float MVetort);

int EixoYMo1(float zo,float yo,float Betat,float Teta_Linha);
int EixoXMo1(float zo,float yo,float Beta_Linha,float Alphat);
Rotacional(float *x1,float *y1,float zo,float x,float y,float Alphat,float Betat,float MVetort, float Teta) ;
int RotaXY(float*,float,float ,float ,float ,float , float );
void GravaArquivo1();
double Converte_Angulo(float Angulo);
struct Graficos_Variaveis{


	long double MXo[1000];
	long double LXo[1000];
	long double MYo[1000];
	long double LYo[1000];
    long double MZo[1000];
	long double LZo[1000];

	TColor Color[2000];



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
	float Alpha_Beta_Teta[3];
	float Alpha_Beta_Teta_Circle[3];
 };
//--------------------------------------------------------------------------
struct Graficos_Variaveis Graficos_Variavel;
//---------------------------------------------------------------------------
#define MALLOC(x) HeapAlloc(GetProcessHeap(),0,(x));
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
 Contador=0;
 Form2->Center=NULL;

}
//----------------------------------------------------------------------------
void Grava_Arqui(char *Nome_Arquivo,int Contador,int ContadorCircle){
ofstream Arquivo_WR(Nome_Arquivo,ios::binary);

	if(!Arquivo_WR){
		ShowMessage("Problemas Ao Abrir Arquivo..!!");
	}else{

			Arquivo_WR.write(reinterpret_cast<const char *>(&Form2->Contador),sizeof(Form2->Contador));
			Arquivo_WR.write(reinterpret_cast<const char *>(&Form2->ContadorCircle),sizeof(Form2->ContadorCircle));


		if(Form2->Contador>0){
			Arquivo_WR.write(reinterpret_cast<const char *>(Form2->MXo),(Contador)*sizeof(float));
			Arquivo_WR.write(reinterpret_cast<const char *>(Form2->LXo),(Contador)*sizeof(float));
			Arquivo_WR.write(reinterpret_cast<const char *>(MYo),(Contador)*sizeof(int));
			Arquivo_WR.write(reinterpret_cast<const char *>(LYo),(Contador)*sizeof(int));
			Arquivo_WR.write(reinterpret_cast<const char *>(Form2->MZo),(Contador)*sizeof(float));
			Arquivo_WR.write(reinterpret_cast<const char *>(Form2->LZo),(Contador)*sizeof(float));
			Arquivo_WR.write(reinterpret_cast<const char *>(Form2->Color),(Contador)*sizeof(DWORD));


			Arquivo_WR.write(reinterpret_cast<const char *>(Form2->MAlpha),(Contador)*sizeof(float));
			Arquivo_WR.write(reinterpret_cast<const char *>(Form2->LAlpha),(Contador)*sizeof(float));
			Arquivo_WR.write(reinterpret_cast<const char *>(Form2->MMVetorG),(Contador)*sizeof(float));
			Arquivo_WR.write(reinterpret_cast<const char *>(Form2->LMVetorG),(Contador)*sizeof(float));
			Arquivo_WR.write(reinterpret_cast<const char *>(Alpha_Beta_Teta),sizeof(Alpha_Beta_Teta));

		}

		if(Form2->ContadorCircle>0){
		for(int i=0;i<Form2->ContadorCircle;i++)
		Arquivo_WR.write(reinterpret_cast<const char *>(Form2->Center[i]),3 *sizeof(float));
		Arquivo_WR.write(reinterpret_cast<const char *>(Form2->AZo),(Form2->ContadorCircle)*sizeof(float));
		Arquivo_WR.write(reinterpret_cast<const char *>(Form2->BZo),(Form2->ContadorCircle)*sizeof(float));
		Arquivo_WR.write(reinterpret_cast<const char *>(Form2->A),(Form2->ContadorCircle)*sizeof(float));
		Arquivo_WR.write(reinterpret_cast<const char *>(Form2->B),(Form2->ContadorCircle)*sizeof(float));

		Arquivo_WR.write(reinterpret_cast<const char *>(Form2->Color_Circle),(Form2->ContadorCircle)*sizeof(DWORD));

		Arquivo_WR.write(reinterpret_cast<const char *>(Alpha_Beta_Teta_Circle),sizeof(Alpha_Beta_Teta_Circle));
		}
		ShowMessage("Gravacao Completa");
		Arquivo_WR.close();
	}




}
//----------------------------------------------------------------------------
void Le_Arquivo(char *Nome_Arquivo){
int Contador=0;
int ContadorCircle=0;
	ifstream Arquivo_RR(Nome_Arquivo,ios::in|ios::binary);
	if(!Arquivo_RR){
	   ShowMessage("Problemas Ao Abrir Arquivo..!!");
	}else{
	 Arquivo_RR.read(reinterpret_cast< char *>(&Contador),sizeof(Contador));
	 Arquivo_RR.read(reinterpret_cast< char *>(&ContadorCircle),sizeof(ContadorCircle));
	Arquivo_RR.close();
	if((Contador>0)||(ContadorCircle>0)){

	if(Contador>0){
	Form2->MAlpha=new float[ (Contador) ];
	Form2->LAlpha=new float[ (Contador) ];
	Form2->MMVetorG=new float[ (Contador)];
	Form2->LMVetorG=new float [(Contador)];
	Form2->MZo=new float [(Contador)];
	Form2->LZo=new float [(Contador)];
	Form2->MXo=new float [(Contador)];
	Form2->LXo=new float [(Contador)];
	Form2->Color=new DWORD[ (Contador)];

	LYo=new int [(Contador)*sizeof(int)];
	MYo=new int [(Contador)*sizeof(int)];
	Form2->MAlpha=(float *)realloc(Form2->MAlpha,(Contador)*sizeof(float ));
	Form2->LAlpha=(float *)realloc(Form2->LAlpha,(Contador)*sizeof(float ));
	Form2->MMVetorG=(float *)realloc(Form2->MMVetorG,(Contador)*sizeof(float ));
	Form2->LMVetorG=(float *)realloc(Form2->LMVetorG,(Contador)*sizeof(float ));
	Form2->MZo=(float *)realloc(Form2->MZo,(Contador)*sizeof(float ));
	Form2->LZo=(float *)realloc(Form2->LZo,(Contador)*sizeof(float ));
	Form2->MXo=(float *)realloc(Form2->MXo,(Contador)*sizeof(float ));
	Form2->LXo=(float *)realloc(Form2->LXo,(Contador)*sizeof(float ));
	MYo=(int *)realloc(MYo,(Contador)*sizeof(int ));
	LYo=(int *)realloc(LYo,(Contador)*sizeof(int ));
	Form2->Color=(DWORD *)realloc(Form2->Color,(Contador)*sizeof(DWORD));
	}

	if(ContadorCircle>0){

	Form2->A=new float [(ContadorCircle)];
	Form2->B=new float [(ContadorCircle)];
	Form2->AZo=new float [(ContadorCircle)];
	Form2->BZo=new float [(ContadorCircle)];
	Form2->Center_Angulo=new float [(ContadorCircle)];
	Form2->Center_Vetor= new float [(ContadorCircle)];
	Form2->Color_Circle=new TColor[(ContadorCircle)];

	Form2->A=(float *)realloc(Form2->A,(ContadorCircle)*sizeof(float ));
	Form2->B=(float *)realloc(Form2->B,(ContadorCircle)*sizeof(float ));
	Form2->AZo=(float *)realloc(Form2->AZo,(ContadorCircle)*sizeof(float ));
	Form2->BZo=(float *)realloc(Form2->BZo,(ContadorCircle)*sizeof(float ));
	Form2->Color_Circle=(TColor *)realloc(Form2->Color_Circle,ContadorCircle*sizeof(TColor));

	Form2->Center_Angulo=(float *)realloc(Form2->Center_Angulo,ContadorCircle*sizeof(float));
	Form2->Center_Vetor=(float *)realloc(Form2->Center_Vetor,ContadorCircle*sizeof(float));


	Form2->Center=(float **)realloc(Form2->Center,ContadorCircle*sizeof(float));
	for(int i=0;i<ContadorCircle;i++){
	Form2->Center[i]=NULL;
	Form2->Center[i]=(float *)realloc(Form2->Center[i],3*sizeof(float));
	}
	Form2->P_Circle=NULL;
	Form2->P_Circle=(TPoint **)realloc(Form2->P_Circle,(ContadorCircle)*sizeof(TPoint));


	for(int i=0;i<ContadorCircle;i++){
	Form2->P_Circle[i]=NULL;
	Form2->P_Circle[i]=(TPoint*)realloc(Form2->P_Circle[i],51*sizeof(TPoint));


	}
	}
	Sleep(200);
  ifstream Arquivo_WR(Nome_Arquivo,ios::in|ios::binary);
  if(!Arquivo_WR){
		ShowMessage("Problemas Ao Abrir Arquivo..!!");
	}else{


		Arquivo_WR.read(reinterpret_cast< char *>(&Form2->Contador),sizeof(Form2->Contador));
		Arquivo_WR.read(reinterpret_cast< char *>(&Form2->ContadorCircle),sizeof(Form2->ContadorCircle));

		if(Form2->Contador>0){
		Arquivo_WR.read(reinterpret_cast< char *>(Form2->MXo),(Contador)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(Form2->LXo),(Contador)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(MYo),(Contador)*sizeof(int));
		Arquivo_WR.read(reinterpret_cast< char *>(LYo),(Contador)*sizeof(int));
		Arquivo_WR.read(reinterpret_cast< char *>(Form2->MZo),(Contador)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(Form2->LZo),(Contador)*sizeof(float));

		Arquivo_WR.read(reinterpret_cast< char *>(Form2->Color),(Contador)*sizeof(DWORD));


		Arquivo_WR.read(reinterpret_cast< char *>(Form2->MAlpha),(Contador)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(Form2->LAlpha),(Contador)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(Form2->MMVetorG),(Contador)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(Form2->LMVetorG),(Contador)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(Alpha_Beta_Teta),sizeof(Alpha_Beta_Teta));

		}











		if(Form2->ContadorCircle>0){


		for(int i=0;i< ContadorCircle;i++)
		Arquivo_WR.read(reinterpret_cast< char *>(Form2->Center[i]),3*sizeof(float));

		Arquivo_WR.read(reinterpret_cast< char *>(Form2->AZo),(ContadorCircle)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(Form2->BZo),(ContadorCircle)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(Form2->A),(ContadorCircle)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(Form2->B),(ContadorCircle)*sizeof(float));


		Arquivo_WR.read(reinterpret_cast< char *>(Form2->Color_Circle),ContadorCircle*sizeof(DWORD));

		Arquivo_WR.read(reinterpret_cast< char *>(Alpha_Beta_Teta_Circle),sizeof(Alpha_Beta_Teta_Circle));
		}
		ShowMessage("Leitura Completa");
		ShowMessage("Contador..:"+IntToStr(Form2->Contador));
		Arquivo_WR.close();
	}


	}


}

}
//----------------------------------------------------------------------------
void Modifica_Center(float **Center,float h){

	for (int i=0;i<Form2->ContadorCircle; i++) {
	  Center[i][0]=Form2->Center_Vetor[i] * Cos(Form2->Center_Angulo[i])*h;
	  Center[i][1]=Form2->Center_Vetor[i] * Sin(Form2->Center_Angulo[i])*h;
	  Center[i][2]= Center[i][2]*h;
	}


}

//----------------------------------------------------------------------------
void Graphics_RotacaoXY(TCanvas *h){
  float  Mxyz[3];
float Lxyz[3];
float MZY[2];
float LZY[2];
int i;

TPoint P1[2];
try{
for(i=0;i<Form2->Contador;i++){
//if(0){
//
// Rotacao_Vetores_3D (Mxyz,Form2->MMVetorG[i]*Cos(Form2->MAlpha[i]),Form2->MMVetorG[i]*Sin(Form2->MAlpha[i]),Form2->MZo[i],Alpha_Beta_Teta);
// Rotacao_Vetores_3D (Lxyz,Form2->LMVetorG[i]*Cos(Form2->LAlpha[i]),Form2->LMVetorG[i]*Sin(Form2->LAlpha[i]),Form2->LZo[i],Alpha_Beta_Teta);
//
//
// Mxyz1[i][0]=Mxyz[0];
// Mxyz1[i][1]=Mxyz[1];
// Mxyz1[i][2]=Mxyz[2];
// Lxyz1[i][0]=Lxyz[0];
// Lxyz1[i][1]=Lxyz[1];
// Lxyz1[i][2]=Lxyz[2];
// }
 if(1){

 Mxyz1[i][0]=(Form2->MMVetorG[i]*Cos(Form2->MAlpha[i]))*(Cos(Alpha_Beta_Teta[1])*Cos(Alpha_Beta_Teta[2])) -
 ( (Form2->MMVetorG[i]*Sin(Form2->MAlpha[i]))*Cos( Alpha_Beta_Teta[1])*Sin(Alpha_Beta_Teta[2]))+Form2->MZo[i]*Sin(Alpha_Beta_Teta[1]);

 Mxyz1[i][1]=(Form2->MMVetorG[i]*Cos(Form2->MAlpha[i]))*(Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Cos(Alpha_Beta_Teta[2])+
 Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[2]))+(Form2->MMVetorG[i]*Sin(Form2->MAlpha[i]))*(-Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Sin(Alpha_Beta_Teta[2])+
 Cos(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[2]))+Form2->MZo[i]*(-Sin(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[1]));


 Lxyz1[i][0]=(Form2->LMVetorG[i]*Cos(Form2->LAlpha[i]))*(Cos(Alpha_Beta_Teta[1])*Cos(Alpha_Beta_Teta[2])) -
 ( (Form2->LMVetorG[i]*Sin(Form2->LAlpha[i]))*Cos( Alpha_Beta_Teta[1])*
 Sin(Alpha_Beta_Teta[2]))+Form2->LZo[i]*Sin(Alpha_Beta_Teta[1]);

  Lxyz1[i][1]=(Form2->LMVetorG[i]*Cos(Form2->LAlpha[i]))*(Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Cos(Alpha_Beta_Teta[2])+
 Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[2]))+( Form2->LMVetorG[i]*Sin(Form2->LAlpha[i]) )*(-Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Sin(Alpha_Beta_Teta[2])+
 Cos(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[2]))+Form2->LZo[i]*(-Sin(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[1]));;



 }


 P1[0].x=FullMKx[i]= X(Mxyz1[i][0]);
 P1[0].y=FullMKy[i]= Y(Mxyz1[i][1]);
 P1[1].x=FullLKx[i]= X(Lxyz1[i][0]);
 P1[1].y=FullLKy[i]= Y(Lxyz1[i][1]);








 Form2->Colorido_Unico(h,i) ;

 h->Polyline(P1,1);

}
}catch(Exception &ex){

  Form2->Label14->Caption="Erro Ponteiros";
}

}

void Graphics_XY(Objetos *objetos,Arquivo *arquivo,TForm2 *Form){
int i=0;
TPoint P1[300][2];
objetos->Draw_Parametros(arquivo,P1);
for(i=0;i<objetos->Count_Line;i++){
	try{

		Form->Colorido_Unico(Form->Canvas,i);
		Form->Canvas->Polyline(P1[i],1);
	}   catch(Exception &ex){


	}

}

}


//----------------------------------------------------------------------------
void Recupera_Arquivo(struct Graficos_Variaveis Grafico_Variavel){
   int i;


	Form2->MAlpha=new float[ (Form2->Contador+1)*sizeof(float )];
	Form2->LAlpha=new float[ (Form2->Contador+1)*sizeof(float )];
	Form2->MMVetorG=new float[ (Form2->Contador+1)*sizeof(float )];
	Form2->LMVetorG=new float [(Form2->Contador+1)*sizeof(float)];
	Form2->MZo=new float [(Form2->Contador+1)*sizeof(float)];
	Form2->LZo=new float [(Form2->Contador+1)*sizeof(float)];
	Form2->MAlpha=(float *)realloc(Form2->MAlpha,(Form2->Contador+1)*sizeof(float ));
	Form2->LAlpha=(float *)realloc(Form2->LAlpha,(Form2->Contador+1)*sizeof(float ));
	Form2->MMVetorG=(float *)realloc(Form2->MMVetorG,(Form2->Contador+1)*sizeof(float ));
	Form2->LMVetorG=(float *)realloc(Form2->LMVetorG,(Form2->Contador+1)*sizeof(float ));
	Form2->MZo=(float *)realloc(Form2->MZo,(Form2->Contador+1)*sizeof(float ));
	Form2->LZo=(float *)realloc(Form2->LZo,(Form2->Contador+1)*sizeof(float ));

	if((Form2->MAlpha!=NULL)&&(Form2->LAlpha!=NULL)&&(Form2->MMVetorG!=NULL)&&(Form2->LMVetorG!=NULL)&&(Form2->MZo!=NULL)&&(Form2->LZo!=NULL)){
	Form2->Contador=Grafico_Variavel.Contador;
	Form2->ContadorCircle=Grafico_Variavel.ContadorCircle;
	Alpha_Beta_Teta[0]=Grafico_Variavel.Alpha_Beta_Teta[0];
	Alpha_Beta_Teta[1]=Grafico_Variavel.Alpha_Beta_Teta[1];
	Alpha_Beta_Teta[2]=Grafico_Variavel.Alpha_Beta_Teta[2];
	Alpha_Beta_Teta_Circle[0]=Graficos_Variavel.Alpha_Beta_Teta_Circle[0];
	Alpha_Beta_Teta_Circle[1]=Graficos_Variavel.Alpha_Beta_Teta_Circle[1];
	Alpha_Beta_Teta_Circle[2]=Graficos_Variavel.Alpha_Beta_Teta_Circle[2];

		for (i = 0; i < Form2->Contador; i++) {
			Form2->MAlpha[i]=Grafico_Variavel.MAlpha[i];
			Form2->LAlpha[i]=Grafico_Variavel.LAlpha[i];
			Form2->MMVetorG[i]=Grafico_Variavel.MMVetorG[i];
			Form2->LMVetorG[i]=Grafico_Variavel.LMVetorG[i];
			Form2->MZo[i]=Grafico_Variavel.MZo[i];
			Form2->LZo[i]=Grafico_Variavel.LZo[i];


			Form2->Color[i]=Grafico_Variavel.Color[i] ;
			Form2->Color_Circle[i]=Grafico_Variavel.Color_Circle[i];
			MYo[i]=Grafico_Variavel.MYo[i];
			LYo[i]=Grafico_Variavel.LYo[i];


			Form2->MXo[i]=Grafico_Variavel.MXo[i];
			Form2->LXo[i]=Grafico_Variavel.LXo[i];



		}


	for (int j=0;j<Form2->ContadorCircle;j++){
		Form2->A[j]=Grafico_Variavel.A[j];
		Form2->B[j]=Grafico_Variavel.B[j];
		Form2->AZo[j]=Grafico_Variavel.AZo[j];
		Form2->BZo[j]=Grafico_Variavel.BZo[j];
		Form2->Center[j][0]=Grafico_Variavel.Center[j][0];
		Form2->Center[j][1]=Grafico_Variavel.Center[j][1];
		Form2->Center[j][2]=Grafico_Variavel.Center[j][2];
		Form2->Color_Circle[j]=Grafico_Variavel.Color_Circle[j];


	}

   Form2->AlphaGr=Grafico_Variavel.AlphaGr;
   AlphaX1=Grafico_Variavel.AlphaX1;
	}else
		ShowMessage("Memorias Não Alocadas Tente Novamente");
  }

//-----------------------------------------------------------------------------
void  RecuperaShow(Desenho Recupera){


    ShowMessage("recupera show");
	Form2->ContadorCircle=Recupera.GetContCircle();
	Form2->Contador=Recupera.GetPosi();






	for (int i=0;i<Form2->Contador;i++){
		Form2->MAlpha[i]=Recupera.MAlpha[i];
		Form2->LAlpha[i]=Recupera.LAlpha[i];
		Form2->MMVetorG[i]=Recupera.MMVetorGr[i];
		Form2->LMVetorG[i]=Recupera.LMVetorGr[i];
		Form2->MZo[i]=Recupera.MZo[i];
		Form2->LZo[i]=Recupera.LZo[i];

		Form2->Color[i]=Recupera.Get_Color(i);
		Form2->Color_Circle[i]=Recupera.Get_Color_Circle(i) ;






	}
}

//---------------------------------------------------------------------------
void Rotacao_Vetores_3D(float xyz[3],float xe,float ye, float ze, float Alpha_Beta_Teta[3]){
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
  if(0)
  xyz[2]=Sin(Alpha_Beta_Teta[1])*xe -Sin(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[1])*ye+Cos(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[1])*ze;
}
void Rotacao_Vetores_3D_Circle_MP2(float xyz[3],float xe,float ye, float  ze, float Alpha_Beta_Teta[3])
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


void Graphics_Rotacao(TCanvas *h,float Alpha_Beta_Teta[3]){
float  Mxyz[3];
float Lxyz[3];
float MZY[2];
float LZY[2];
int i;

TPoint P1[2];
 try{
for(i=0;i<Form2->Contador;i++){
if(0){
 Rotacao_Vetores_3D (Mxyz,Form2->MMVetorG[i]*Cos(Form2->MAlpha[i]),Form2->MMVetorG[i]*Sin(Form2->MAlpha[i]),Form2->MZo[i],Alpha_Beta_Teta);
 Rotacao_Vetores_3D (Lxyz,Form2->LMVetorG[i]*Cos(Form2->LAlpha[i]),Form2->LMVetorG[i]*Sin(Form2->LAlpha[i]),Form2->LZo[i],Alpha_Beta_Teta);


 Mxyz1[i][0]=Mxyz[0];
 Mxyz1[i][1]=Mxyz[1];
 Mxyz1[i][2]=Mxyz[2];
 Lxyz1[i][0]=Lxyz[0];
 Lxyz1[i][1]=Lxyz[1];
 Lxyz1[i][2]=Lxyz[2];
 }
 if(1){
 Mxyz1[i][0]=(Form2->MMVetorG[i]*Cos(Form2->MAlpha[i]))*(Cos(Alpha_Beta_Teta[1])*Cos(Alpha_Beta_Teta[2])) -
 ( (Form2->MMVetorG[i]*Sin(Form2->MAlpha[i]))*Cos( Alpha_Beta_Teta[1])*Sin(Alpha_Beta_Teta[2]))+Form2->MZo[i]*Sin(Alpha_Beta_Teta[1]);

 Mxyz1[i][1]=(Form2->MMVetorG[i]*Cos(Form2->MAlpha[i]))*(-Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Cos(Alpha_Beta_Teta[2])+
 Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[2]))+(Form2->MMVetorG[i]*Sin(Form2->MAlpha[i]))*(Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Sin(Alpha_Beta_Teta[2])+
 Sin(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[2]))+Form2->MZo[i]*(Cos(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[1]));


 Lxyz1[i][0]=(Form2->LMVetorG[i]*Cos(Form2->LAlpha[i]))*(Cos(Alpha_Beta_Teta[1])*Cos(Alpha_Beta_Teta[2])) -
 ( (Form2->LMVetorG[i]*Sin(Form2->LAlpha[i]))*Cos( Alpha_Beta_Teta[1])*
 Sin(Alpha_Beta_Teta[2]))+Form2->LZo[i]*Sin(Alpha_Beta_Teta[1]);

 Lxyz1[i][1]=(  Form2->LMVetorG[i]*Cos(Form2->LAlpha[i])  )*(-Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Cos(Alpha_Beta_Teta[2])+
 Sin(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[2]))+(Form2->LMVetorG[i]*Sin(Form2->LAlpha[i])  )*(Cos(Alpha_Beta_Teta[0])*Sin(Alpha_Beta_Teta[1])*Sin(Alpha_Beta_Teta[2])+
 Sin(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[2]))+Form2->LZo[i]*(Cos(Alpha_Beta_Teta[0])*Cos(Alpha_Beta_Teta[1]));


 }
 P1[0].x=FullMKx[i]= X(Mxyz1[i][0]);
 P1[0].y=FullMKy[i]= Y(Mxyz1[i][1]);
 P1[1].x=FullLKx[i]= X(Lxyz1[i][0]);
 P1[1].y=FullLKy[i]= Y(Lxyz1[i][1]);








 Form2->Colorido_Unico(h,i) ;
 h->Polyline(P1,1);

}
 }catch(Exception &ex){
 Form2->Label14->Caption="Erro Ponteiro";
 }

}
double Converte_Angulo(float Angulo){


return (Angulo/180)*M_PI;

}
void Limpa_Orientacao(TCanvas *h){

h->Pen->Color=clWhite;
h->Polyline(MP,1);


}
 int RotaXY(float *x1,float *y1,float zo,float Alphat,float Betat,float MVetort, float Teta){
	 float k;
	 if (zo<=0) {
	  zo=-zo;
	  k= MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }else
	  k=MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);

	*x1= (MVetort*Cos(Alphat))*Cos(Teta) + (k)*Sin(Teta);
	*y1= -(MVetort*Cos(Alphat))*Sin(Teta)+ (k)*Cos(Teta);




}
int Rotacional(float *x1,float *y1,float zo,float x,float y,float Alphat,float Betat,float MVetort, float Teta){
	 float k;
	 long double Ang;

	 if (zo<=0) {
	  zo=-zo;
	  k= MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }else
	  k=MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);

	*x1= x*Cos(Teta) - y*Sin(Teta);
	*y1= x*Sin(Teta)+ y*Cos(Teta);




}
void RecebeUnicode(char *File,UnicodeString FileEnter){
  int i=0;
  string Str;
  for (i=0;i<FileEnter.Length();i++){
  Str[i]=FileEnter[i];


  }

}
int OXDes2(int x){
return x+KOOx2;

}
int OYDes2(int y){
 return KOOy2-y;
}

float OX(float x){

return (int)(x-KOx);

}
int OXDes(int x){

return	x-1800;

}
float OY(float y){
  return (int)(KOy-y);
}
int OYDes(int y){
  return KyOO-y;
}
 int X(int x){
return x+Kx;
   }

   int Y(int y){
return Ky-y;
   }
 
   void Graphics3(TCanvas *h){
   TPoint MP[2];
 float kx1[2];
 float ky1[2];

 for (int i = 0; i < Form2->Contador; i++) {


RotaXY(&kx1[0],&ky1[0],Form2->MZo[i],Form2->MAlpha[i],Form2->BetaT,Form2->MMVetorG[i],TetaX);
RotaXY(&kx1[1],&ky1[1],Form2->LZo[i],Form2->LAlpha[i],Form2->BetaT,Form2->LMVetorG[i],TetaX);



	  FullMKx[i]=X(kx1[0]);
	  FullMKy[i]= Y(ky1[0]) ;
	  FullLKx[i]=X(kx1[1]);
	  FullLKy[i]=Y(ky1[1]);
	  MP[0].x=X(kx1[0]);
	  MP[0].y=Y(ky1[0]) ;
	  MP[1].x=X(kx1[1]);
      MP[1].y=Y(ky1[1]);


	  h->Pen->Width=1;
	  Form2->Colorido_Unico(Form2->Canvas,i);

      h->Polyline(MP,1);




}
}

void Grafics(TCanvas *h){
TPoint MP[2];
float kx1[2];
float ky1[2];

 if ((Form2->RZoX->Checked)||( Form2->RXoY->Checked)){
	if (Form2->RZoX->Checked){
 		  BetaTDes=0;

 	  }
 	if (Form2->RXoY->Checked){
 	BetaTDes=M_PI/2;

   	  }

 	for (int i = 0; i < Form2->Contador; i++) {


 		RotaXY(&kx1[0],&ky1[0],Form2->MZo[i],Form2->MAlpha[i],BetaTDes,Form2->MMVetorG[i],TetaX);
 		RotaXY(&kx1[1],&ky1[1],Form2->LZo[i],Form2->LAlpha[i],BetaTDes,Form2->LMVetorG[i],TetaX);



		int  MLLkx= X(kx1[0]);
		int   MLLky= Y(ky1[0]) ;
		int   LLLkx= X(kx1[1]);
		int   LLLky=Y(ky1[1]);
   		FullMKxDes[i]=MLLkx;
   		FullMKyDes[i]=MLLky;
   		FullLKxDes[i]=LLLkx;
   		FullLKyDes[i]=LLLky;
   		MP[0].x=MLLkx;
   		MP[0].y=MLLky;
   		MP[1].x=LLLkx;
   		MP[1].y= LLLky;


   		h->Pen->Width=0;


   		h->Polyline(MP,1);




		}
 	}

}








int EixoXo(float xo,float yo,float zo,  float *Alphat,float *MVetorXY){

float MXYVetor;

float MVetorXY1;
float Alphat1=0;






MVetorXY1=Sqrt((xo*xo) +(yo*yo));
if (MVetorXY1<0) {
		*Alphat=0;
		*MVetorXY=0;
		return 0;
		 }

if((xo==0)&&(yo==0)){
*Alphat=0;
*MVetorXY=0;
return 0;
}

	MXYVetor=MVetorXY1;


	*MVetorXY=MVetorXY1;

	 if (xo==0) {
		 if (yo>0){
		*Alphat=M_PI/2;

			return 0;

			}
	 if (yo<0) {
	 *Alphat=-M_PI/2;

	 return 0;
	 }


}else{

	  if (yo==0) {
		if(xo>0){
		*Alphat=0;
		return 0;
		}
		if(xo<0){
			*Alphat=M_PI;
			return 0;

		}


	  }

	  if ((xo<0)&&(yo<0)) {
		 try{
		 xo=-xo;

		 Alphat1=acos(xo/MVetorXY1)+M_PI;
		 xo=-xo;
		 }catch(Exception &ex){
		  ShowMessage("Divisão por Zero");


		 }


	  }


		  if ((xo<0)&&(yo>0)) {
		  try{
		xo=-xo;

		Alphat1=M_PI-acos(xo/MVetorXY1);

		xo=-xo;
		  }catch(Exception &ex){
		  ShowMessage("Divisão por Zero");
		  }
		  }

	  if ((xo>0)&&(yo<0)) {
		 try{
		 Alphat1=2*M_PI-acos(xo/MVetorXY1);
		  }catch(Exception &ex){
		  ShowMessage("Divisão por Zero");
		  }
	  }

	  if ((xo>0)&&(yo>0)) {
		try{
		 Alphat1=acos(xo/MVetorXY1);
		 }
		 catch(Exception &ex){
		 ShowMessage("Divisão por Zero");
		 }
	  }

	  }



	*Alphat=Alphat1;



   return floor( MXYVetor*Cos(Alphat1));



}


int EixoYo(float zo, float Alphat,float Betat,float MVetor){




  if (zo<=0) {
  zo=-zo;
		 return MVetor*Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	 }


  return MVetor*Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);



}


float EixoXMo(long double Alphat,long double MVetort){

	return  MVetort*Cos(Alphat);

}


int EixoXMo1(float yo,float xo,float Teta_Linha,float Alpha_Linha){


	return  sqrt(xo*xo+yo*yo)*Cos(Teta_Linha);

}


float EixoXMoCircle(float Alphat,float MVetort){

	return  MVetort*Cos(Alphat);

}


int EixoYMo(float zo,float Alphat,float Betat, float MVetort){



	  if (zo<=0) {
	  zo=-zo;
	  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }


  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);


}


int EixoYMo1(float zo,float yo,float Betat, float Teta_Linha){

  if (zo<=0) {
	  zo=-zo;
	  return yo*Cos(Teta_Linha)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }



  return yo*Cos(Teta_Linha)*Sin(Betat)+zo*Sin(M_PI/2+Betat);


}


int EixoYMoCircle(float zo,float Alphat,float Betat, float MVetort){



	  if (zo<=0) {
	  zo=-zo;
	  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }


  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);


}






void Colorido(TCanvas *h,int i){

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
void TForm2::Colorido_Unico(TCanvas *h,int i){



		  h->Pen->Color=Color[i];




}

void TForm2::Circle(float A[1000],float AZ[1000],float B[1000],float BZ[1000],TPoint **P,float **Center){

float sx1=300;
float sy1=150;
float sz1;
float x1;
float y1;
float  Ang;
float  MVetor;
float Cnd=0;
float AngVar=((2*M_PI)/50);


for(int j=0;j<Form2->ContadorCircle;j++){

	for (int i=0;i<51;i++){


		sx1=A[j]*Cos((i*((2*M_PI)/50)))+Center[j][0];
		sy1=B[j]*Sin(i*((2*M_PI)/50))+Center[j][1];
		sz1=AZ[j]*Cos((i*((2*M_PI)/50)))+BZ[j]*Sin((i*((2*M_PI)/50)))+Center[j][2];




		EixoXo(sx1,sy1,0,&Ang,&MVetor);

		x1=EixoXMo(Ang+AlphaX1,MVetor);
		y1=EixoYMo(sz1,Ang+AlphaX1,Form2->BetaT,MVetor);

		RotaXY(&x1,&y1,sz1,Ang+AlphaX1,Form2->BetaT,MVetor,TetaX);

		P[j][i].x= X(x1);
		P[j][i].y= Y(y1);
	}

Form2->Canvas->Pen->Color=clGreen;
Form2->Canvas->Polyline(P[j],50);

	}

}
//------------------------------------------------------------------------------

void TForm2::Circle_Vetor(float *A,float *AZ,float *B,float *BZ,TPoint **P,float **Center){


float sx1=300;
float sy1=150;
float sz1;
float x1;
float y1;
float Circle_XYZ[3];
float  Ang;
float  MVetor;
float Cnd=0;
float AngVar=((2*M_PI)/50);


for(int j=0;j<Form2->ContadorCircle;j++){

		for (int i=0;i<51;i++){


		sx1=A[j]*Cos((i*((2*M_PI)/50)))+Center[j][0];
		sy1=B[j]*Sin(i*((2*M_PI)/50))+Center[j][1];
		sz1=AZ[j]*Cos((i*((2*M_PI)/50)))+BZ[j]*Sin((i*((2*M_PI)/50)))+Center[j][2];




		EixoXo(sx1,sy1,0,&Ang,&MVetor);

		x1=EixoXMo(Ang+AlphaX1,MVetor);
		y1=EixoYMo(sz1,Ang+AlphaX1,Form2->BetaT,MVetor);

				  Rotacao_Vetores_3D_Circle_MP2( Circle_XYZ,sx1,sy1,sz1,Alpha_Beta_Teta_Circle);




		Form2->P_Circle[j][i].x= X(Circle_XYZ[0]);
		Form2->P_Circle[j][i].y= Y(Circle_XYZ[1]);
		}





	Form2->Colororico_Unico_Circle(Form2->Canvas,j);
	Form2->Canvas->Polyline(Form2->P_Circle[j],50);

	}

}

void TForm2::Circle_VetorXZ(float *A,float *AZ,float *B,float *BZ,TPoint **P,float **Center){


float sx1=300;
float sy1=150;
float sz1;
float x1;
float y1;
float Circle_XYZ[3];
float  Ang;
float  MVetor;
float Cnd=0;
float AngVar=((2*M_PI)/50);


for(int j=0;j<Form2->ContadorCircle;j++){

		for (int i=0;i<51;i++){


		sx1=A[j]*Cos((i*((2*M_PI)/50)))+Center[j][0];
		sy1=B[j]*Sin(i*((2*M_PI)/50))+Center[j][1];
		sz1=AZ[j]*Cos((i*((2*M_PI)/50)))+BZ[j]*Sin((i*((2*M_PI)/50)))+Center[j][2];




		EixoXo(sx1,sy1,0,&Ang,&MVetor);

		x1=EixoXMo(Ang+AlphaX1,MVetor);
		y1=EixoYMo(sz1,Ang+AlphaX1,Form2->BetaT,MVetor);

				  Rotacao_Vetores_3D_Circle_MP2( Circle_XYZ,sx1,sy1,sz1,Alpha_Beta_Teta_Circle);




		Form2->P_Circle[j][i].x= X(Circle_XYZ[0]);
		Form2->P_Circle[j][i].y= Y(Circle_XYZ[2]);
		}





	Form2->Colororico_Unico_Circle(Form2->Canvas,j);
	Form2->Canvas->Polyline(Form2->P_Circle[j],50);

	}

}


void LimpaMemoria(){



memset(&Form2->LZo,0,sizeof(Form2->LZo));
memset(&Form2->MZo,0,sizeof(Form2->MZo));
memset(&Form2->MAlpha,0,sizeof(Form2->MAlpha));
memset(&Form2->LAlpha,0,sizeof(Form2->LAlpha));
memset(&Form2->MMVetorG,0,sizeof(Form2->MMVetorG));
memset(&Form2->LMVetorG,0,sizeof(Form2->LMVetorG));
memset(&Form2->A,0,sizeof(Form2->A));
memset(&Form2->B,0,sizeof(Form2->B));
memset(&Form2->AZo,0,sizeof(Form2->AZo));
memset(&Form2->BZo,0,sizeof(Form2->BZo));
memset(&Form2->Center,0,sizeof(Form2->Center));
memset(&Form2->ContadorCircle,0,sizeof(Form2->ContadorCircle));
memset(&AlphaX1,0,sizeof(AlphaX1));
memset(&Cont,0,sizeof(Cont));
memset(&Kr,0,sizeof(Kr));
memset(&Alpha_Beta_Teta,0,sizeof(Alpha_Beta_Teta));
memset(&Alpha_Beta_Teta_Circle,0,sizeof(Alpha_Beta_Teta_Circle));
j=0;
Kr=1;

AlphaX1=0;
AlphaGr=0;
Form2->Contador=0;
Contar=0;

	 if (Form2->RadioXoY->Checked){

		Form2->BetaT=M_PI/2;
	}


	if (  Form2->RadioZoX->Checked){
		Form2->BetaT=0;

	}


	TetaX=0;
	Form2->Label10->Caption="PXYZ(0,0,0};";
	Form2->Label11->Caption="PXYZ(0,0,0};";
	Form2->CheckBox2->Checked=true;


}










void Eixos(TCanvas *p){
float  kx;
float  ky;
float  Ang;
float  Mtar;
float Mtar1;
float Ang1;

Form2->Canvas->Pen->Width=0  ;
Form2->Canvas->Pen->Color=clBlack;
EixoXo(-1000,0,0,&Ang,&Mtar);
EixoXo(1000,0,0,&Ang1,&Mtar1);
kx=EixoXMo(Ang,Mtar);
kx=Configura(kx,1);
ky=EixoYMo(0,Ang,Form2->BetaT,Mtar);
ky=Configura(ky,1);
Form2->Canvas->MoveTo(X(kx),Y(ky));
kx=EixoXMo(Ang1,Mtar1);
kx=Configura(kx,1);
ky=EixoYMo(0,Ang1,Form2->BetaT,Mtar1);
ky=Configura(ky,1);
Form2->Canvas->LineTo(X(kx),Y(ky));
 Form2->Canvas->Pen->Color=clBlack;
p->LineTo(X(kx),Y(ky));
	if ( Form2->RadioXoY->Checked ){

		Form2->Canvas->Pen->Color=clPurple;
	}else
  		Form2->Canvas->Pen->Color=clLime;

kx=EixoXo(0.0,1000.0,0.0,&Ang,&Mtar);
kx=Configura(kx,1);
ky=EixoYo(0.0,Ang,M_PI/2,Mtar);
ky=Configura(ky,-1);
p->MoveTo(X(kx),Y(ky));
kx=EixoXo(0.0,-1000.0,0.0,&Ang,&Mtar);
kx=Configura(kx,1);
ky=EixoYo(0,Ang,M_PI/2,Mtar);
ky=Configura(ky,-1);
p->LineTo(X(kx),Y(ky));

}


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------



//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------



//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

void __fastcall TForm2::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{

float  Ang;
float  Mtar;
	 if (Button== mbLeft){


if (Edit1->Text.IsEmpty() ) {
	 Edit1->Text="0";}
if (Edit2->Text.IsEmpty()) {
	 Edit2->Text="0";
}
 if (RadioXoY->Checked) {
	 CheckBox2->Checked=true;

 }

 if (RadioZoX->Checked) {

	CheckBox2->Checked=true;
 }


Contar=Contar+1;
 if(Button==mbLeft){

if ((RadioButton1->Checked)&&(Contar==1)&&(RadioXoY->Checked)) {
  kx1=OX(X);
  ky1=OY(Y);
  MZo[Contador]=Edit1->Text.ToInt();

  EixoXo(OX(X),OY(Y),MZo[Contador],&Ang,&Mtar);
  EixoYo(MZo[Contador],Ang,BetaT,Mtar);




   MAlpha[Contador]=Ang;

   MMVetorG[Contador]=Mtar;


	::Move=true;
  }
   }
if ((RadioButton1->Checked)&&(Contar==2)&&(RadioXoY->Checked)) {

  ::Move=false;
  Contar=0;
   LZo[Contador]=Edit1->Text.ToInt();

  EixoXo(OX(X),OY(Y),0,&Ang,&Mtar);
  EixoYo(LZo[Contador],Ang,BetaT,Mtar);
  LAlpha[Contador]=Ang;

  LMVetorG[Contador]=Mtar;





  Contador=Contador+1;
   Desenho3DS.SetPosi(Contador);
   MLimpaB(Form2->Canvas);
  Graphics3(Form2->Canvas);
  }
	if(Button==mbLeft){
  if ((RadioButton1->Checked)&&(Contar==1)&&(RadioZoX->Checked)) {
  kx1=OX(X);
  ky1=OY(Y);
   MZo[Contador]=OY(Y);
   MYo[Contador]=Edit2->Text.ToInt();

  EixoXo(OX(X),MYo[Contador],0,&Ang,&Mtar);
  EixoYo(OY(Y),Ang,BetaT,Mtar);





   MAlpha[Contador]=Ang;

   MMVetorG[Contador]=Mtar;


	::Move=true;
  }
  }

   if ((RadioButton1->Checked)&&(Contar==2)&&(RadioZoX->Checked)) {
  ::Move=false;
  Contar=0;
   LZo[Contador]=OY(Y);
   LYo[Contador]=Edit2->Text.ToInt();
  EixoXo(OX(X),LYo[Contador],0,&Ang,&Mtar);
  EixoYo(OY(Y),Ang,BetaT,Mtar);
  LAlpha[Contador]=Ang;

  LMVetorG[Contador]=Mtar;


  Contador=Contador+1;
  MLimpaB(Form2->Canvas);
  Desenho3DS.SetPosi(Contador);
   Grafics(Form2->Canvas);

   }


  if (RadioButton2->Checked) {
	 Contar=0;
  }
  if (Contar>4) {
	 Contar=0;
  }

   }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button22Click(TObject *Sender)
{
float kx=0;
float ky=0;
float Mtar[10];
float Lado;
float  Ang[10];
Eixos(Form2->Canvas);

AlphaX1=AlphaX1+M_PI/50;
Application->Terminate();

}
//---------------------------------------------------------------------------


void __fastcall TForm2::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{

  int kx[5000];
int ky[5000];
int LLLkx;
int LLLky;
int MLLkx;
int MLLky;
TRect P;
TPoint MP[2];
float  Ang;
float  Mtar;

Form2->Canvas->Brush->Color=clWhite;

	if ((RadioButton1->Checked)&&(::Move)&&(RadioXoY->Checked)) {


kx[1]=EixoXo(OX(X),OY(Y),Zo[Contador],&Ang,&Mtar);
 ky[1]=EixoYo(Zo[Contador],Ang,M_PI/2,Mtar);

  Form2->Canvas->Pen->Color=clRed;





   MLLkx= ::X(kx1);
   MLLky= ::Y(ky1) ;
   LLLkx= ::X(kx[1]);
   LLLky=::Y(ky[1]);

  FullMKx[Contador]=MP[0].x=MLLkx;
  FullMKy[Contador]= MP[0].y=MLLky;
  FullLKx[Contador]= MP[1].x=X;
  FullLKy[Contador]=MP[1].y=Y;
   Form2->Canvas->Pen->Color=clWhite;
   Form2->Canvas->Pen->Width=80;
	 Form2->Canvas->Polyline(MP,1);
	 Form2->Canvas->Pen->Color=clRed;
	 Form2->Canvas->Pen->Width=0;
	 Form2->Canvas->Polyline(MP,1);





  }

	if ((RadioButton1->Checked)&&(::Move)&&(RadioZoX->Checked)) {

	kx[1]=EixoXo(OX(X),0,Zo[Contador],&Ang,&Mtar);
	ky[1]=EixoYo(OY(Y),Ang,0,Mtar);

   MLLkx= ::X(kx1);
   MLLky= ::Y(ky1) ;
   LLLkx= ::X(kx[1]);
   LLLky=::Y(ky[1]);



  FullMKx[Contador]= MP[0].x=MLLkx;
  FullMKy[Contador]= MP[0].y=MLLky;
  FullLKx[Contador]= MP[1].x=X;
  FullLKy[Contador]= MP[1].y=Y;
   Form2->Canvas->Pen->Color=clWhite;
   Form2->Canvas->Pen->Width=80;
	 Form2->Canvas->Polyline(MP,1);
	 Form2->Canvas->Pen->Color=clRed;
	 Form2->Canvas->Pen->Width=0;


		Form2->Canvas->Polyline(MP,1);

	}

  Label1->Top=Y+235;
  Label1->Left=X+15;

  kx[0]=X;
  ky[0]=Y;
  Label1->Caption="{ "+FloatToStr(::OX(X))+" ; "+FloatToStr(OY(Y))+" };";

}
//---------------------------------------------------------------------------
  void MLimpaB(TCanvas *h){
int i=0;
TPoint MP[2];
for (int i = 0; i < Form2->Contador; i++) {









   MP[0].x=FullMKx[i];
   MP[0].y=FullMKy[i];
   MP[1].x=FullLKx[i];
   MP[1].y= FullLKy[i];

   h->Pen->Color=clWhite;
   h->Pen->Width=0;


   h->Polyline(MP,1);




}




}
void TForm2::MLimpa(TCanvas *h,TPoint **P){
h->Pen->Color=clWhite;

for(int j=0;j<Form2->ContadorCircle;j++){

h->Polyline(P[j],50);
}
h->Pen->Color=clPurple;
}
void MLimpaBDes(TCanvas *h){
int i=0;
TPoint MP[2];

for (int i = 0; i < Form2->Contador; i++) {









   MP[0].x=FullMKxDes[i];
   MP[0].y=FullMKyDes[i];
   MP[1].x=FullLKxDes[i];
   MP[1].y= FullLKyDes[i];

   h->Pen->Color=clWhite;
   h->Pen->Width=0;
   h->Polyline(MP,1);






}

}






//---------------------------------------------------------------------------

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{




 if ((Contador>0)||(ContadorCircle>0)) {



 if (CheckBox2->Checked){
   if(RadioXoY->Checked){
	BetaT=M_PI/2;
	Graphics_RotacaoXY(Form2->Canvas);


   }

 }
if(RadioZoX->Checked){
BetaT=0;

Graphics_Rotacao(Form2->Canvas,Alpha_Beta_Teta);

}




}

if(ContadorCircle>0){
 if (CheckBox2->Checked){
   if(RadioXoY->Checked){


	Form2->Circle_Vetor(A,AZo,B,BZo,P_Circle,Center);

   }

 }
if(RadioZoX->Checked){



Form2->Circle_VetorXZ(A,AZo,B,BZo,P_Circle,Center);
}




}


}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button24Click(TObject *Sender)
{
int i=0;
int kx=0;
int ky =0;


 MLimpaB(Form2->Canvas);
 Alpha_Beta_Teta_X[0]+=M_PI/50;


 for(int i=0;i<Form2->Contador;i++){




 Rotacao_Vetores_3D(Mxyz,MVetor[i]*Cos(MAngulo_X[i]),MVetor[i]*Sin(MAngulo_X[i]),MZo_X[i],Alpha_Beta_Teta_X);
 Rotacao_Vetores_3D(Lxyz,LVetor[i]*Cos(LAngulo_X[i]),LVetor[i]*Sin(LAngulo_X[i]),LZo_X[i],Alpha_Beta_Teta_X);




 EixoXo(Mxyz[0],Mxyz[1],0,&MAlpha[i],&MMVetorG[i]);
 EixoXo(Lxyz[0],Lxyz[1],0,&LAlpha[i],&LMVetorG[i]);
 MZo[i]=Mxyz[2];
 LZo[i]=Lxyz[2];




 }


}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button25Click(TObject *Sender)
{
int i=0;
float kx=0;
float ky=0;




 Alpha_Beta_Teta_Y[1]+=M_PI/50;
 MLimpaB(Form2->Canvas);

 for(int i=0;i<Form2->Contador;i++){

 Rotacao_Vetores_3D(Mxyz,MVetor_Y[i]*Cos(MAngulo_Y[i]),MVetor_Y[i]*Sin(MAngulo_Y[i]),MZo_Y[i],Alpha_Beta_Teta_Y);
 Rotacao_Vetores_3D(Lxyz,LVetor_Y[i]*Cos(LAngulo_Y[i]),LVetor_Y[i]*Sin(LAngulo_Y[i]),LZo_Y[i],Alpha_Beta_Teta_Y);



 EixoXo(Mxyz[0],Mxyz[1],0,&MAlpha[i],&MMVetorG[i]);
 EixoXo(Lxyz[0],Lxyz[1],0,&LAlpha[i],&LMVetorG[i]);
 MZo[i]=Mxyz[2];
 LZo[i]=Lxyz[2];

 }
}

//---------------------------------------------------------------------------

void __fastcall TForm2::Edit1DblClick(TObject *Sender)
{
Edit1->Clear();
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------


//---------------------------------------------------------------------------



void __fastcall TForm2::Button28Click(TObject *Sender)
{
MLimpaB(Form2->Canvas);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::RadioZoXClick(TObject *Sender)
{
BetaT=0;


RadioButton3->Checked=true;
Cancel->Checked=true;
MLimpaBDes(Form2->Canvas);
MLimpaB(Form2->Canvas);
MLimpa(Form2->Canvas,P_Circle);
Label12->Font->Color=clLime;
Label12->Caption="Eixo Zo";
Label6->Caption="Eixo Xo";
CheckBox2->Checked=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioXoYClick(TObject *Sender)
{
BetaT=M_PI/2;
RadioButton3->Checked=true;

Cancel->Checked=true;
MLimpaBDes(Form2->Canvas);
MLimpaB(Form2->Canvas);
MLimpa(Form2->Canvas,P_Circle);
Label12->Font->Color=clPurple;
Label12->Caption="Eixo Yo";
Label6->Caption="Eixo Xo";
CheckBox2->Checked=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BetaT0Click(TObject *Sender)
{
BetaT=0;
MLimpa(Form2->Canvas,P_Circle);
MLimpaB(Form2->Canvas);
Circle(A,AZo,B,BZo,P_Circle,Center);
CheckBox2->Checked=true;
Graphics3(Form2->Canvas);

}
//---------------------------------------------------------------------------

void __fastcall TForm2::BetaTMPI2Click(TObject *Sender)
{
BetaT=M_PI/2;
MLimpa(Form2->Canvas,P_Circle);
MLimpaB(Form2->Canvas);
CheckBox2->Checked=true;
Graphics3(Form2->Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonSalvarClick(TObject *Sender)
{
int k;
int i;
int Cont=0;

UnicodeString FileNome;
char FileUni[500];
if (SaveDialog1->Execute()){
ShowMessage(SaveDialog1->FileName );
FileNome=SaveDialog1->FileName;
}
Cont= FileNome.Length();
for(i=0;i<FileNome.Length();i++){
FileUni[i]=FileNome[i+1];

}
 FileUni[ FileNome.Length()]='\0';













   Grava_Arqui(FileUni,Form2->Contador,Form2->ContadorCircle);

}
//---------------------------------------------------------------------------

//----------------------------------------------------------------------------
void GravaArquivo1(){
   int i;
	ShowMessage(IntToStr(Form2->Contador));
	Graficos_Variavel.Contador=Form2->Contador;
	Graficos_Variavel.ContadorCircle=Form2->ContadorCircle;
	Graficos_Variavel.Alpha_Beta_Teta[0]=Alpha_Beta_Teta[0];
	Graficos_Variavel.Alpha_Beta_Teta[1]=Alpha_Beta_Teta[1];
	Graficos_Variavel.Alpha_Beta_Teta[2]=Alpha_Beta_Teta[2];
    Graficos_Variavel.Alpha_Beta_Teta_Circle[0]=Alpha_Beta_Teta_Circle[0];
	Graficos_Variavel.Alpha_Beta_Teta_Circle[1]=Alpha_Beta_Teta_Circle[1];
	Graficos_Variavel.Alpha_Beta_Teta_Circle[2]=Alpha_Beta_Teta_Circle[2];
		for (i = 0; i < Form2->Contador; i++) {
			Graficos_Variavel.MAlpha[i]=Form2->MAlpha[i];
			Graficos_Variavel.LAlpha[i]=Form2->LAlpha[i];
			Graficos_Variavel.MMVetorG[i]=Form2->MMVetorG[i];
			Graficos_Variavel.LMVetorG[i]=Form2->LMVetorG[i];
			Graficos_Variavel.MZo[i]=Form2->MZo[i];
			Graficos_Variavel.LZo[i]=Form2->LZo[i];


			Graficos_Variavel.Color[i] =Form2->Color[i];
			Graficos_Variavel.Color_Circle[i]=Form2->Color_Circle[i];
			Graficos_Variavel.MYo[i]=MYo[i];
			Graficos_Variavel.LYo[i]=LYo[i];


			Graficos_Variavel.MXo[i]=Form2->MXo[i];
			Graficos_Variavel.LXo[i]=Form2->LXo[i];



   }

	for (int j=0;j<Form2->ContadorCircle;j++){
		Graficos_Variavel.A[j]=Form2->A[j];
		Graficos_Variavel.B[j]=Form2->B[j];
		Graficos_Variavel.AZo[j]=Form2->AZo[j];
		Graficos_Variavel.BZo[j]=Form2->BZo[j];
		Graficos_Variavel.Center[j][0]=Form2->Center[j][0];
		Graficos_Variavel.Center[j][1]=Form2->Center[j][1];
		Graficos_Variavel.Center[j][2]=Form2->Center[j][2];
		Graficos_Variavel.Color_Circle[j]=Form2->Color_Circle[j];

	}
   ShowMessage(FloatToStr(Graficos_Variavel.Contador));
   Graficos_Variavel.AlphaGr=Form2->AlphaGr;
   Graficos_Variavel.AlphaX1=AlphaX1;
  }
//----------------------------------------------------------------------------
void __fastcall TForm2::ButtonRecuperaClick(TObject *Sender)
{



int i=0;







 UnicodeString FileNome;
char FileUni[500];
MLimpaB(Form2->Canvas);
LimpaMemoria();
if (OpenDialog1->Execute()){
LimpaMemoria();
FileNome=OpenDialog1->FileName;
}
 int Cont= FileNome.Length();
for(i=0;i<FileNome.Length();i++){
FileUni[i]=FileNome[i+1];

}

FileUni[Cont]='\0';
ShowMessage(FileUni);








Le_Arquivo(FileUni);


 Form2->Canvas->Pen->Width=1;




  if(Form2->RadioXoY->Checked)
		Form2->Circle_Vetor(A,AZo,B,BZo,P_Circle,Center);
	else
		Form2->Circle_VetorXZ(A,AZo,B,BZo,P_Circle,Center);



  if(RadioXoY->Checked)
	Graphics_RotacaoXY(Form2->Canvas);
else
	Graphics_Rotacao(Form2->Canvas,Alpha_Beta_Teta);


}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

  void GravaArquivo(){
   int i;
	ShowMessage(IntToStr(Form2->Contador));
	Desenho3DS.SetPosi(Form2->Contador);
	Desenho3DS.SetBetaT(Form2->BetaT);
    Desenho3DS.SetAlphaX1(AlphaX1);
	Desenho3DS.SetContCircle(Form2->ContadorCircle);
   for (i = 0; i < Form2->Contador; i++) {



   Desenho3DS.SetMAlpha(Form2->MAlpha[i],i);
   Desenho3DS.SetLAlpha(Form2->LAlpha[i],i);
   Desenho3DS.SetMMVetorGr(Form2->MMVetorG[i],i);
   Desenho3DS.SetLMVetorGr(Form2->LMVetorG[i],i);

   Desenho3DS.SetMZo(Form2->MZo[i],i);
   Desenho3DS.SetLZo(Form2->LZo[i],i);

   Desenho3DS.Set_Color( Form2->Color,i);
   }

   for (int j=0;j<Form2->ContadorCircle;j++){

   Desenho3DS.SetA(j,Form2->A[j]);
   Desenho3DS.SetB(j,Form2->B[j]);
   Desenho3DS.SetAZo(j,Form2->AZo[j]);
   Desenho3DS.SetBZo(j,Form2->BZo[j]);
   Desenho3DS.SetCenter(j,0);
   Desenho3DS.Set_Color_Circle(Form2->Color_Circle,i);

   }



  }

//---------------------------------------------------------------------------





void __fastcall TForm2::RadioButton1Click(TObject *Sender)
{     if ( RadioXoY->Checked){
BetaT=M_PI/2;
}
if (  RadioZoX->Checked){
BetaT=0;

}
 MLimpaB(Form2->Canvas);
 Alpha_Beta_Teta[0]=0;
 Alpha_Beta_Teta[1]=0;
 Alpha_Beta_Teta[2]=0;
	  CheckBox2->Checked=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button29Click(TObject *Sender)
{
int i=0;

float kx=0.0;
float ky=0.0;
MLimpa(Form2->Canvas,P_Circle);

MLimpaB(Form2->Canvas);

for(i=0;i<ContadorCircle;i++){
A[i]*=1.1;
AZo[i]*=1.1;
B[i]*=1.1;
BZo[i]*=1.1;



}
Modifica_Center(Center,1.1);

for (i = 0; i < Contador; i++) {
MMVetorG[i]=MMVetorG[i]*1.1;
 LMVetorG[i]=LMVetorG[i]*1.1;
 MZo[i]=MZo[i]*1.1;
 LZo[i]=LZo[i]*1.1;
}
if(RadioXoY->Checked)
		Graphics_RotacaoXY(Form2->Canvas);
	else
		Graphics_Rotacao(Form2->Canvas,Alpha_Beta_Teta);

	if(Form2->RadioXoY->Checked)
		Form2->Circle_Vetor(A,AZo,B,BZo,P_Circle,Center);
	else
		Form2->Circle_VetorXZ(A,AZo,B,BZo,P_Circle,Center);

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button30Click(TObject *Sender)
{
int i=0;
float kx=0.0;
float ky=0.0;



MLimpa(Form2->Canvas,P_Circle);
MLimpaB(Form2->Canvas);



for(i=0;i<ContadorCircle;i++){
A[i]/=1.1;
AZo[i]/=1.1;
B[i]/=1.1;
BZo[i]/=1.1;

}
Modifica_Center(Center,1/1.1);
for (i = 0; i < Contador; i++) {
MMVetorG[i]=MMVetorG[i]/1.1;
 LMVetorG[i]=LMVetorG[i]/1.1 ;
 MZo[i]=MZo[i]/1.1;
 LZo[i]=LZo[i]/1.1;
}
if(RadioXoY->Checked)
		Graphics_RotacaoXY(Form2->Canvas);
	else
		Graphics_Rotacao(Form2->Canvas,Alpha_Beta_Teta);

	if(Form2->RadioXoY->Checked)
		Form2->Circle_Vetor(A,AZo,B,BZo,P_Circle,Center);
	else
		Form2->Circle_VetorXZ(A,AZo,B,BZo,P_Circle,Center);

}


//---------------------------------------------------------------------------



//---------------------------------------------------------------------------




//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void ConfiguraBut(TButton * But){
But->Top=Configura( But->Top,-1);
But->Left=Configura( But->Left,1);
But->Height=Configura( But->Height,-1);
But->Width=Configura( But->Width,1);
But->Font->Height=Configura(But->Font->Height,-1);
}
void ConfiguraForm(TForm * But){
But->Top=Configura( But->Top,-1);
But->Left=Configura( But->Left,1);
But->Height=Configura( But->Height,-1);
But->Width=Configura( But->Width,1);

}
void ConfiguraBox(TCheckBox * But){
But->Top=Configura( But->Top,-1);
But->Left=Configura( But->Left,1);


But->Font->Height=Configura(But->Font->Height,-1);
}
void ConfiguraRadioBut(TRadioButton * But){
But->Top=Configura( But->Top,-1);
But->Left=Configura( But->Left,1);
But->Height=Configura( But->Height,-1);
But->Width=Configura( But->Width,1);
But->Font->Height=Configura(But->Font->Height,-1);

}
void ConfiguraEd(TEdit * But){
But->Top=Configura( But->Top,-1);
But->Left=Configura( But->Left,1);
But->Height=Configura( But->Height,-1);
But->Width=Configura( But->Width,1);
But->Font->Height=Configura(But->Font->Height,-1);
}

void ConfiguraPan(TPanel * But){
But->Top=Configura( But->Top,-1);
But->Left=Configura( But->Left,1);
But->Height=Configura( But->Height,-1);
But->Width=Configura( But->Width,1);

}
void ConfiguraLab(TLabel * But){
But->Top=Configura( But->Top,-1);
But->Left=Configura( But->Left,1);
But->Font->Height=Configura(But->Font->Height,-1);

}
void ConfiguraImg(TImage * But){
But->Top=Configura( But->Top,-1);
But->Left=Configura( But->Left,1);
But->Height=Configura( But->Height,-1);
But->Width=Configura( But->Width,1);

}
int Configura_Panel(TPanel * Panel){




}
void __fastcall TForm2::FormCreate(TObject *Sender)
{
objetos=new Objetos();

Soma_100=0;
Alpha_Beta_Teta_Circle[1]=-M_PI/2;
Alpha_Beta_Teta_Circle[0]=0;
Alpha_Beta_Teta_Circle[2]=0;
Eixo_Lancar=true;

Alpha_Beta_Teta[0]=0;
Alpha_Beta_Teta[1]=0;
Alpha_Beta_Teta[2]=0;
Alpha_Beta_Teta_X[0]=0;
Lancar=false;
BetaT=M_PI/2;
Form2->Height=Screen->DesktopHeight;
Label12->Top=Form2->Top+Configura(Panel10->Height,-1)+20;
Label12->Left=920;
Label12->Font->Color=clPurple;
Label12->Caption="Eixo Yo";
//configuração do visual proporcional;


Kx=Configura(Kx,1);
Ky=Configura(Ky,-1);
KOx= Configura(KOx,1);
KOy=Configura(KOy,-1);
ConfiguraBut(Button22);
ConfiguraBut(Button35);
ConfiguraBut(Close);

ConfiguraBut(Button31);
ConfiguraBut(Button32);
ConfiguraBut(Button33);
ConfiguraBut(Button34);

ConfiguraBut(Button24);
ConfiguraBut(Button25);
ConfiguraBut(Button29);
ConfiguraBut(Button30);
ConfiguraBut(ButtonRecupera);
ConfiguraBut(ButtonSalvar);
ConfiguraBut(Button36);
//labels
ConfiguraLab(Label1);
ConfiguraLab(Label12);
ConfiguraLab(Label2);
ConfiguraLab(Label6);
ConfiguraLab(Label4);
ConfiguraLab(Label7);
ConfiguraLab(Label10);
ConfiguraLab(Label11);
ConfiguraLab(Label3);
ConfiguraLab(Label5);
ConfiguraLab(Label9);

//panels
ConfiguraPan(Panel1);
ConfiguraPan(Panel2);
ConfiguraPan(Panel3);
ConfiguraPan(Panel4);
ConfiguraPan(Panel5);
ConfiguraPan(Panel6);
ConfiguraPan(Panel7);
ConfiguraPan(Panel8);
ConfiguraPan(Panel9);
//Edit
ConfiguraEd(Edit1);
ConfiguraEd(Edit2);
ConfiguraEd(Edit3);
ConfiguraEd(Edit4);
ConfiguraEd(Edit5);
//RadioButton

ConfiguraRadioBut(RadioButton1);
ConfiguraRadioBut(RadioButton2);
ConfiguraRadioBut(RadioXoY);
ConfiguraRadioBut(RadioZoX);
ConfiguraRadioBut(Cancel);
ConfiguraRadioBut(RXoY);
ConfiguraRadioBut(RZoX);
ConfiguraRadioBut(BetaT0);
ConfiguraRadioBut(BetaTMPI2);
ConfiguraRadioBut(RadioButton3);
//CheckBox
ConfiguraBox(CheckBox2);
ConfiguraBox(CheckBox1);
}


//---------------------------------------------------------------------------

void __fastcall TForm2::LimpaDesenho1Click(TObject *Sender)
{

MLimpa(Form2->Canvas,P_Circle);
MLimpaB(Form2->Canvas);
AlphaGr=0;

LimpaMemoria();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::PontoaPonto1Click(TObject *Sender)
{
Form1->Visible=true;
Form1->Edit1->SetFocus();
}
//---------------------------------------------------------------------------





void __fastcall TForm2::Button36Click(TObject *Sender)
{

 float  Ang;
 float  Mtar;
float  xo;
float  yo;
float  zo;

 if (RadioXoY->Checked) {
	 CheckBox2->Checked=true;

 }

 if (RadioZoX->Checked) {

	CheckBox2->Checked=true;
 }
 if (Edit3->Text.IsEmpty()){
 Edit3->Text="0";
 xo=0;
 }
 if(Edit4->Text.IsEmpty()){
 Edit4->Text="0";
 yo=0;
 }
 if(Edit5->Text.IsEmpty()){
 Edit5->Text="0";
 zo=0;
 }
 xo=Edit3->Text.ToDouble();
 yo=Edit4->Text.ToDouble();
 zo=Edit5->Text.ToDouble();

  j=Cont%2;






 	if (j==0){

      	 	 MZo[Contador]=zo;

 		 EixoXo(xo,yo,0,&Ang,&Mtar);
  		 EixoYo(zo,Ang,BetaT,Mtar);




  		 MAlpha[Contador]=Ang+AlphaGr;
  		 MMVetorG[Contador]=Mtar;

  		 Label10->Font->Color=clBlue;
  		 Label10->Caption="P" + IntToStr(Contador)+" : "+IntToStr(0)+"{ "+FloatToStr(xo)+ " , "+FloatToStr(yo)+" ,"+FloatToStr(zo)+" }; °°°";
  		 Cont++;
 	}
 	if (j==1)
  	 {
 		LZo[Contador]=zo;

 		EixoXo(xo,yo,0,&Ang,&Mtar);
 		EixoYo(zo,Ang,BetaT,Mtar);
  		Cont++;
  		Label11->Font->Color=clBlue;
  		Label11->Caption="P" + IntToStr(Contador)+" : "+IntToStr(1)+"{ "+FloatToStr(xo)+ " , "+FloatToStr(yo)+" ,"+FloatToStr(zo)+" }; °°°";



  		LAlpha[Contador]=Ang+AlphaGr;
  		LMVetorG[Contador]=Mtar;


 		Contador=Contador+1;


	 }

 	Sleep(2000);

}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------

void __fastcall TForm2::RZoXClick(TObject *Sender)
{
MLimpaBDes(Form2->Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button35Click(TObject *Sender)
{

int i=0;
float kx=0;
float ky=0;
float kx1;
float ky1;
TPoint MP[2];

	MLimpa(Form2->Canvas,P_Circle);
	MLimpaB(Form2->Canvas);
	TetaX=TetaX+M_PI/50;
	Graphics3(Form2->Canvas);
	Circle(A,AZo,B,BZo,P_Circle,Center);


}
//---------------------------------------------------------------------------

void __fastcall TForm2::Form31Click(TObject *Sender)
{
Form3->Visible=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::RXoYClick(TObject *Sender)
{
  MLimpaBDes(Form2->Canvas);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::ConstruoEIxoXYZ1Click(TObject *Sender)
{
Form1->Visible=true;
}
//---------------------------------------------------------------------------

int Configura(float Desk, int x){
float k;
float k2;

	if (x<1){
		k=1080;
		k2=Screen->DesktopHeight;
	}else {
 		 k=1920;
 		 k2=Screen->DesktopWidth;
 	 }

return (k2/k)*Desk;
}

void __fastcall TForm2::ConstruoElipse1Click(TObject *Sender)
{
 Form4->Visible=true;
 if(Form4->Visible)
 Form4->Edit1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton3Click(TObject *Sender)
{
CheckBox2->Checked=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
TPoint P1;
float Ang;
float Mtar;
Arquivo *arquivo=new Arquivo();

 Form2->Color=(DWORD *)realloc(Form2->Color,(Form2->Contador+1)*sizeof(DWORD));
 Color[Contador]=ColorBox1->Selected;

Form2->MAlpha=(float *)realloc(Form2->MAlpha,(Form2->Contador+1)*sizeof(float ));
Form2->LAlpha=(float *)realloc(Form2->LAlpha,(Form2->Contador+1)*sizeof(float ));
Form2->MMVetorG=(float *)realloc(Form2->MMVetorG,(Form2->Contador+1)*sizeof(float ));
Form2->LMVetorG=(float *)realloc(Form2->LMVetorG,(Form2->Contador+1)*sizeof(float ));
Form2->MZo=(float *)realloc(Form2->MZo,(Form2->Contador+1)*sizeof(float ));
Form2->LZo=(float *)realloc(Form2->LZo,(Form2->Contador+1)*sizeof(float ));
Form2->MXo=(float *)realloc(Form2->MZo,(Form2->Contador+1)*sizeof(float ));
Form2->LXo=(float *)realloc(Form2->LZo,(Form2->Contador+1)*sizeof(float ));
LYo=(int *)realloc(LYo,(Form2->Contador+1)*sizeof(int ));
MYo=(int *)realloc(MYo,(Form2->Contador+1)*sizeof(int ));





	 if (Button== mbLeft){
		P1=Form2->ScreenToClient(Mouse->CursorPos);

		if (Edit1->Text.IsEmpty() ) {
			 Edit1->Text="0,0";
                }

		if (Edit2->Text.IsEmpty()) {
			 Edit2->Text="0,0";
		}

 		if (RadioXoY->Checked) {
			 CheckBox2->Checked=true;

		 }

		 if (RadioZoX->Checked) {

			CheckBox2->Checked=true;
		 }




		Contar++;



		if ((RadioButton1->Checked)&&(Contar==1)&&(RadioXoY->Checked)) {


			 FullMKx[Contador]=MP[0].x=P1.x;
			 FullMKy[Contador]= MP[0].y=P1.y;


			 MZo[Contador]=Edit1->Text.ToDouble();

			 MZo_X[Contador]=MZo[Contador];
			 MZo_Y[Contador]=MZo[Contador];



			 EixoXo(OX(P1.x),OY(P1.y),MZo[Contador],&Ang,&Mtar);





  			 MAlpha[Contador]=Ang;

			 MMVetorG[Contador]=Mtar;
             MVetor[Contador]=MMVetorG[Contador];

			  MAngulo_X[Contador]=MAlpha[Contador];
			 MAngulo_Y[Contador]=MAlpha[Contador];
			 MVetor_Y[Contador]=MMVetorG[Contador];
			::Move=true;
  		}

		if ((RadioButton1->Checked)&&(Contar==2)&&(RadioXoY->Checked)) {

 			 ::Move=false;

  			 Contar=0;
			 LZo[Contador]=Edit1->Text.ToDouble();
			 LZo_X[Contador]=LZo[Contador];
			 LZo_Y[Contador]= LZo[Contador];
			 EixoXo(OX(P1.x),OY(P1.y),0,&Ang,&Mtar);

			 LAlpha[Contador]=Ang;

 			 LMVetorG[Contador]=Mtar;
			 LVetor[Contador]=LMVetorG[Contador];

			  LAngulo_X[Contador]=LAlpha[Contador];
			  LAngulo_Y[Contador]= LAlpha[Contador];
			  LVetor_Y[Contador]=LMVetorG[Contador];


 			 Contador=Contador+1;
 			 Desenho3DS.SetPosi(Contador);

					 MP[1].x=P1.x;
					 MP[1].y=P1.y;


              MLimpaB(Form2->Canvas);
					if(RadioXoY->Checked)
		Graphics_RotacaoXY(Form2->Canvas);
	else
		Graphics_Rotacao(Form2->Canvas,Alpha_Beta_Teta);

	if(Form2->RadioXoY->Checked)
		Form2->Circle_Vetor(A,AZo,B,BZo,P_Circle,Center);
	else
		Form2->Circle_VetorXZ(A,AZo,B,BZo,P_Circle,Center);
				}


 		 if ((RadioButton1->Checked)&&(Contar==1)&&(RadioZoX->Checked)) {

			  FullMKx[Contador]=MP[0].x=P1.x;
			  FullMKy[Contador]= MP[0].y=P1.y;
			  MZo[Contador]=OY(P1.y);
  			  MYo[Contador]=Edit2->Text.ToDouble();

			  EixoXo(OX(P1.x),MYo[Contador],0,&Ang,&Mtar);

			  float  Ang2;
			  float  Mtar2;

			  EixoXo(OX(P1.x),OY(P1.y),0,&Ang2,&Mtar2);


			  MAlpha[Contador]=Ang;

			  MMVetorG[Contador]=Mtar;
			  MVetor[Contador]=MMVetorG[Contador];
			  MAngulo_X[Contador]=MAlpha[Contador];
			  MZo_X[Contador]=MZo[Contador];


			 ::Move=true;
  		}


  		 if ((RadioButton1->Checked)&&(Contar==2)&&(RadioZoX->Checked)) {
      			::Move=false;
  			Contar=0;
			LZo[Contador]=OY(P1.y);
   			LYo[Contador]=Edit2->Text.ToDouble();
			EixoXo(OX(P1.x),LYo[Contador],0,&Ang,&Mtar);



  			LAlpha[Contador]=Ang;

			LMVetorG[Contador]=Mtar;
			 LVetor[Contador]=LMVetorG[Contador];
			  LAngulo_X[Contador]=LAlpha[Contador];
			  LZo_X[Contador]=LZo[Contador];


  			Contador=Contador+1;
  			MLimpaB(Form2->Canvas);
			Desenho3DS.SetPosi(Contador);
			MLimpaB(Form2->Canvas);

	if(RadioXoY->Checked)
		Graphics_RotacaoXY(Form2->Canvas);
	else
		Graphics_Rotacao(Form2->Canvas,Alpha_Beta_Teta);

	if(Form2->RadioXoY->Checked)
		Form2->Circle_Vetor(A,AZo,B,BZo,P_Circle,Center);
	else
		Form2->Circle_VetorXZ(A,AZo,B,BZo,P_Circle,Center);
   		}


  		if (RadioButton2->Checked) {
	 		Contar=0;
  		}

  		if (Contar>4) {
			 Contar=0;
  		}

   	}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)

{
  TPoint P1;
  float Ang,Mtar;






	if ((RadioButton1->Checked)&&(::Move)) {

        	Form2->Canvas->Pen->Color=clWhite;
			if((MP[1].x>0)||(MP[1].y>0)){

			Form2->Canvas->Polyline(MP,1);

			}
				P1=Form2->ScreenToClient(Mouse->CursorPos);
			FullLKx[Contador]=MP[1].x=P1.x;
			FullLKy[Contador]=MP[1].y=P1.y;

			Form2->Canvas->Pen->Color=clRed;

			Form2->Canvas->Polyline(MP,1);







  	}


        Label1->Top=Y+20;
        Label1->Left=X+15;


	Label1->Caption="{ "+FloatToStr(::OX(X))+" ; "+FloatToStr(OY(Y))+" };";

}
//---------------------------------------------------------------------------




void __fastcall TForm2::Button32Click(TObject *Sender)
{
Lancar=true;
t=0;
Eixo_Lancar=false;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer2Timer(TObject *Sender)
{
float Vo;

int i;

float Angulo;
	if(Lancar==true){
		if((!Edit6->Text.IsEmpty())&&(!Edit7->Text.IsEmpty())){
                  Angulo=Converte_Angulo(Edit7->Text.ToDouble());
                  Vo=Edit6->Text.ToDouble();
				if(Lancar==true){

					if(t==0){
                        Kx=400;
                        Ky=700;


					}

					if(t<35) {


					   Kx=400+Vo *Cos(Angulo )*t;
					   Ky=700-(Vo*Sin(Angulo)*t -(10*t*t)/2.0);
						Alpha_Beta_Teta[0]+=M_PI/50;
						Alpha_Beta_Teta[1]+=M_PI/50;
						Alpha_Beta_Teta[2]+=M_PI/50;
                        if(RadioXoY->Checked)
							Graphics_RotacaoXY(Form2->Canvas);
						else
							Graphics_Rotacao(Form2->Canvas,Alpha_Beta_Teta);

						if(Form2->RadioXoY->Checked)
							Form2->Circle_Vetor(A,AZo,B,BZo,P_Circle,Center);
						else
							Form2->Circle_VetorXZ(A,AZo,B,BZo,P_Circle,Center);




					   t+=0.05;

					}else
				   Lancar=false;
				}
		} else{
				 Lancar=false;
				 ShowMessage("Preencha os Campos velocidade e Angulo" );
				}
	}
 Eixo_Lancar=false;
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Edit6Enter(TObject *Sender)
{
Lancar=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit7Enter(TObject *Sender)
{
Lancar=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button34Click(TObject *Sender)
{


MLimpaB(Form2->Canvas);
Angulo_Circle+=M_PI/50;
MLimpa(Form2->Canvas,P_Circle);
Alpha_Beta_Teta[0]+=M_PI/50;
Alpha_Beta_Teta_Circle[0]+=M_PI/50;
if(RadioXoY->Checked)
	Graphics_RotacaoXY(Form2->Canvas);
else
	Graphics_Rotacao(Form2->Canvas,Alpha_Beta_Teta);


if(Form2->RadioXoY->Checked)
	Form2->Circle_Vetor(A,AZo,B,BZo,P_Circle,Center);
 else
 Form2->Circle_VetorXZ(A,AZo,B,BZo,P_Circle,Center);

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button31Click(TObject *Sender)
{

Counter++;

MLimpa( Form2->Canvas,P_Circle);
MLimpaB(Form2->Canvas);
Alpha_Beta_Teta[1]+=M_PI/50;
Alpha_Beta_Teta_Circle[1]+=M_PI/50;
if(RadioXoY->Checked)
	Graphics_RotacaoXY(Form2->Canvas);
else
	Graphics_Rotacao(Form2->Canvas,Alpha_Beta_Teta);
if(Form2->RadioXoY->Checked)
	Form2->Circle_Vetor(A,AZo,B,BZo,P_Circle,Center);
 else
 Form2->Circle_VetorXZ(A,AZo,B,BZo,P_Circle,Center);


}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button33Click(TObject *Sender)
{

Counter1++;

MLimpaB(Form2->Canvas);
MLimpa(Form2->Canvas,P_Circle);
Alpha_Beta_Teta[2]+=M_PI/50;
Alpha_Beta_Teta_Circle[2]+=M_PI/50;
Counter++;
	if(RadioXoY->Checked)
		Graphics_RotacaoXY(Form2->Canvas);
	else
		Graphics_Rotacao(Form2->Canvas,Alpha_Beta_Teta);

	if(Form2->RadioXoY->Checked)
		Form2->Circle_Vetor(A,AZo,B,BZo,P_Circle,Center);
	else
		Form2->Circle_VetorXZ(A,AZo,B,BZo,P_Circle,Center);

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
Angulo+=M_PI/50;
Graphics_Rotacao(Form2->Canvas,Alpha_Beta_Teta);
}
//---------------------------------------------------------------------------







void __fastcall TForm2::Voltar1Click(TObject *Sender)
{

   if(Contador>0)
   {
   		MLimpaB(Form2->Canvas);
		Contador--;

   }

}
//---------------------------------------------------------------------------
void TForm2::Colororico_Unico_Circle(TCanvas *h,int i)
{
  h->Pen->Color=Color_Circle[i];
}
void __fastcall TForm2::VoltarCirculo1Click(TObject *Sender)
{
	if(ContadorCircle>0)
	{
		MLimpa(Form2->Canvas,P_Circle);
        ContadorCircle--;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer3Timer(TObject *Sender)
{
if(Eixo_Lancar);
   Eixos(Form2->Canvas);
}
//---------------------------------------------------------------------------




void __fastcall TForm2::CloseClick(TObject *Sender)
{
MLimpaB(Form2->Canvas);
Arquivo *arquivo1=new Arquivo();
Arquivo *arquivo=new Arquivo();
Objetos *objetos=new Objetos();

int i=0;







 UnicodeString FileNome;
char FileUni[500];

LimpaMemoria();
if (OpenDialog1->Execute()){
LimpaMemoria();
FileNome=OpenDialog1->FileName;
}

 int Cont= FileNome.Length();
for(i=0;i<FileNome.Length();i++){
FileUni[i]=FileNome[i+1];

}

FileUni[Cont]='\0';
ShowMessage(FileUni);
int testa=0;

	 if(1){
	 memset(arquivo,0,sizeof(arquivo));
	 arquivo->AbrirArquivo(FileUni,arquivo1);
	 Le_Arquivo(FileUni);
	if (arquivo->Count_Line>0) {
		if(arquivo->MAlpha9!=NULL)
			Label14->Caption="Form2->MAlpha[]:="+FloatToStr(MAlpha[0])+"   MAlpha[Contador]:="+FloatToStr(arquivo->MAlpha9[0]);

		else
		   Label14->Caption="Erro no Objeto";
  }else
		Label14->Caption="falha";
	 }
	 TPoint P1[300][2];



	 objetos->Draw_Parametros( arquivo,P1) ;

	 Graphics_XY(objetos,arquivo,Form2);
}
//---------------------------------------------------------------------------

