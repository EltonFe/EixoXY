//---------------------------------------------------------------------------

#pragma hdrstop

#include "UnitArquivo2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


void Desenho::SetMAlpha(float AlphaS,int i){

MAlpha[i]=AlphaS;


}
float Desenho::GetMAlpha(int k){


return MAlpha[k];

}

void Desenho::SetMMVetorGr(float MMVetorGrS,int i){
MMVetorGr[i]=MMVetorGrS;
}
float Desenho::GetMMVetorGr(int k){
return MMVetorGr[k];
}
void Desenho::SetLAlpha(float LAlphaS,int i){
LAlpha[i]=LAlphaS;
}
float Desenho::GetLAlpha(int k){
return LAlpha[k];
}
void Desenho::SetBetaT (float BetaTS){
   BetaT= BetaTS;
}
float Desenho::GetBetaT(){
return BetaT;
}
void Desenho::SetLMVetorGr(float LMVetorGrS,int i){
LMVetorGr[i]=LMVetorGrS;
}
float Desenho::GetLMVetorGr(int k){
return LMVetorGr[k];
}

void Desenho::SetMZo(float MZoS,int i){

MZo[i]=MZoS;


}


float Desenho::GetMzo(int k){
return MZo[k];
}

void Desenho::SetLZo(float LZoS,int i){

LZo[i]=LZoS;
}

float Desenho::GetLzo(int k){

return LZo[k];
}

void Desenho::SetPosi(int PosiS){

Posi=PosiS;
}

int Desenho::GetPosi(){

return Posi;
}
float   Desenho::GetA(int i){
 return A[i];
 }
 float Desenho::GetB(int i) {
	 return B[i];
 }
 float Desenho::GetAZo(int i){
 return AZo[i];
 }

 float Desenho::GetBZo(int i){
 return BZo[i];
 }
 int Desenho::GetContCircle(){

 return ContadorCircle;
 }
 void Desenho::GetCenter(int i,float A[5000][3]){
 A[i][0]=Center[i][0];
 A[i][1]=Center[i][1];
 A[i][2]=Center[i][2];

 }
 float Desenho::GetAlphaX1(){

 return AlphaX1;
 }
 void Desenho::SetA(int i,float x){
 A[i]=x;

 }
 void Desenho::SetB(int i,float x){
 B[i]=x;

 }
 void Desenho::SetAZo(int i,float x){

 AZo[i]=x;
 }

 void Desenho::SetBZo(int i,float x){

 BZo[i]=x;

 }


 void Desenho::SetCenter(int i,float A[5000][3]){

 Center[i][0]=A[i][0];
 Center[i][1]=A[i][1];
 Center[i][2]=A[i][2];
 }
 void Desenho::SetContCircle(int x){
 ContadorCircle=x;
 }
 void   Desenho::SetAlphaX1(float x){

 AlphaX1=x;
 }




TColor Desenho::Get_Color(int Index)
{
	return Color[Index];
}
void Desenho::Set_Color(DWORD *S_Color,int Index)
{
	Color[Index]=S_Color[Index];
}

void Desenho::Set_Color_Circle(TColor *S_Color_Circle,int Index)
{
    Color_Circle[Index]=S_Color_Circle[Index];
}
TColor Desenho::Get_Color_Circle(int Index)
{
    return Color_Circle[Index];
}
