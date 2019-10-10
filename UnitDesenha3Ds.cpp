//---------------------------------------------------------------------------

#pragma hdrstop


#include <math.h>
#include "UnitDesenha3Ds.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

VetorDes3Ds::VetorDes3Ds(long double Beta1 ):Beta(M_PI/2),Kx(900),Ky(580),Contador(0),Teta(0) {

   Color=clBlack;

   MAlpha=(long double*)malloc(sizeof(long double));
   LAlpha=(long double*)malloc(sizeof(long double));
   MMVetorG=(long double*)malloc(sizeof(long double));
   LMVetorG=(long double*)malloc(sizeof(long double));
   MZo=(long double*)malloc(sizeof(long double));
   LZo=(long double*)malloc(sizeof(long double));
   memset(MAlpha,0,sizeof(long double));
   memset(LAlpha,0,sizeof(long double));
   memset(MMVetorG,0,sizeof(long double));
   memset(LMVetorG,0,sizeof(long double));
   memset(MZo,0,sizeof(long double));
   memset(LZo,0,sizeof(long double));


 }
 int  VetorDes3Ds::X(int x){
   return x+Kx;
   }
int VetorDes3Ds::Y(int y){

 return 500 - y;

   }

int VetorDes3Ds::OX(float x){
 return x-KOx;
	}


int VetorDes3Ds::OY(float y){

    return KOy-y;
	}
	float VetorDes3Ds::EixoXMo(long double Alphat,long double MVetort){

	return  MVetort*Cos(Alphat);

}
float VetorDes3Ds::EixoYMo(long double zo,long double Alphat,long double Betat, long double MVetort){



	  if (zo<=0) {
	  zo=-zo;
	  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }


  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);


}

int VetorDes3Ds::EixoYo(long double zo, long double Alphat,long double Betat,long double MVetor){




	  if (zo<=0) {
	  zo=-zo;
	  return MVetor *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }


  return MVetor *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);


}

long double VetorDes3Ds::EixoXo(long double xo,long double yo,  long double *Alphat,long double *MVetorXY){

long double MXYVetor;

long double MVetorXY1;
long double Alphat1=0;






MVetorXY1=sqrt((xo*xo) +(yo*yo));
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
   return  MXYVetor*cos(Alphat1);




}

long double   VetorDes3Ds::GetLAlpha(int i){
return LAlpha[i];
}
void   VetorDes3Ds::SetLAlpha(long double LAlphaSet,int i){
LAlpha[i]=LAlphaSet;
}
long double   VetorDes3Ds::GetMAlpha(int i){

return MAlpha[i];
}
void   VetorDes3Ds::SetMAlpha(long double MAlphaSet,int i){
MAlpha[i]=MAlphaSet;

}

long double   VetorDes3Ds::GetMMVetorG( int i){


  return MMVetorG[i];


}




long double   VetorDes3Ds::GetLMVetorG(int i){
  return LMVetorG[i];
}
long double  VetorDes3Ds::GetBetaT(){

return Beta;

}
void VetorDes3Ds::SetLMVetorG(long double LMVetorGSet,int i){

LMVetorG[i]=LMVetorGSet;

}
void VetorDes3Ds::SetBetaT(long double BetaTSet){
long double Beta=BetaTSet;

}
void  VetorDes3Ds::SetMMVetorG(long double MMVetorG,int i){
 VetorDes3Ds::MMVetorG[i]=MMVetorG;
}
int VetorDes3Ds::GetContador(){

return Contador;
}
void VetorDes3Ds::SetPosi1(int Contador){

VetorDes3Ds::Contador=Contador;
}
long double VetorDes3Ds::GetMZo(int i){

return MZo[i];

}
void  VetorDes3Ds::SetMZo(long double MZo1,int i){

MZo[i]=MZo1;

}
long double VetorDes3Ds::GetLZo(int i){

return LZo[i];
}

void VetorDes3Ds::SetLZo(long double LZo1,int i){

 LZo[i]=LZo1;
}


 long double   VetorDes3Ds::GetA(int i){
 return A[i];
 }
 long double VetorDes3Ds::GetB(int i) {
	 return B[i];
 }
 long double VetorDes3Ds::GetAZo(int i){
 return AZo[i];
 }

 long double VetorDes3Ds::GetBZo(int i){
 return BZo[i];
 }
 int VetorDes3Ds::GetContCircle(){

 return ContadorCircle;
 }
 void VetorDes3Ds::GetCenter(int i,float A[1000][3]){
 A[i][0]=Center[i][0];
 A[i][1]=Center[i][1];
 A[i][2]=Center[i][2];

 }
 void VetorDes3Ds::SetA(int i,float x){
 A[i]=x;

 }
 void VetorDes3Ds::SetB(int i,float x){
 B[i]=x;

 }
 void VetorDes3Ds::SetAZo(int i,float x){

 AZo[i]=x;
 }

 void VetorDes3Ds::SetBZo(int i,float x){

 BZo[i]=x;

 }


 void VetorDes3Ds::SetCenter(int i,float x,float y,float z){

 Center[i][0]=x;
 Center[i][1]=y;
 Center[i][2]=z;
 }
 void VetorDes3Ds::SetContCircle(int x){
 ContadorCircle=x;
 }
 long double VetorDes3Ds::GetTeta(){
 return Teta;
 }

 void VetorDes3Ds::RealocaMemoria( ){

 MAlpha=(long double *)realloc(MAlpha,(Contador+1) *sizeof(long double));
 LAlpha=(long double *)realloc(LAlpha,(Contador+1) *sizeof(long double));
 MMVetorG=(long double *)realloc(MMVetorG,(Contador+1) *sizeof(long double));
 LMVetorG=(long double *)realloc(LMVetorG,(Contador+1) *sizeof(long double));
 MZo=(long double *)realloc(MZo,(Contador+1) *sizeof(long double));
 LZo=(long double *)realloc(LZo,(Contador+1) *sizeof(long double));

 }

 void VetorDes3Ds::RotaXY(long double *x1,long double *y1,long double zo,long double Alphat,long double Betat,long double MVetort, long double Teta){
	 float k;
	 if (zo<=0) {
	  zo=-zo;
	  k= MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }else
	  k=MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);

	*x1= (MVetort*Cos(Alphat))*Cos(Teta) + (k)*Sin(Teta);
	*y1= -(MVetort*Cos(Alphat))*Sin(Teta)+ (k)*Cos(Teta);




}
void VetorDes3Ds::Set_Color(DWORD Set_Color){

Color=Set_Color;




}
TColor VetorDes3Ds::Get_Color(){

return Color;

}
void VetorDes3Ds::Set_Color_Camada(int *S_Color_Camada,int Index)
{
	Color_Camada[Index]=S_Color_Camada[Index];
}

int VetorDes3Ds::Get_Color_Camada(int Index)
{
 return  Color_Camada[Index];
}
