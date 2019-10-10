//---------------------------------------------------------------------------

#ifndef UnitArquivo2H
#define UnitArquivo2H
#include <System.Classes.hpp>
#include <System.Math.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>

#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>



//---------------------------------------------------------------------------

class Desenho{
public:


void SetMAlpha(float,int);
float GetMAlpha(int);
void SetLAlpha(float,int);
float GetLAlpha(int);
void SetMMVetorGr(float,int);
float GetMMVetorGr(int);
void SetLMVetorGr(float , int);
float GetLMVetorGr(int);
void SetBetaT(float);
float GetBetaT ();
void SetMZo(float,int);
float GetMzo(int);
void SetLZo(float,int);
float GetLzo(int);
void SetPosi(int);
int GetPosi();
int Posi;
float MAlpha[5000];
float LAlpha[5000];
float MMVetorGr[5000];
float LMVetorGr[5000];
float BetaT;
float MZo[5000];
float LZo[5000];
 float GetA(int);
   float GetB(int);
   float GetAZo(int);
   float GetBZo(int);
   int GetContCircle();
   float GetAlphaX1();
   void GetCenter(int,float [5000][3]);
   void SetA(int,float);
   void SetB(int,float);
   void SetAZo(int,float);
   void SetBZo(int,float);
   void SetCenter(int,float [5000][3]);
   void SetContCircle(int);
   void SetAlphaX1(float);


   TColor Get_Color(int Index);
   void Set_Color(DWORD *S_Color,int Index);
   void Set_Color_Circle(TColor *S_Color_Circle,int Index);
   TColor Get_Color_Circle(int Index);
  private:

   float A[5000];
   float B[5000];
   float AZo[5000];
   float BZo[5000];
   float Center[5000][3];
   int ContadorCircle;
   float AlphaX1;

   TColor Color[5000];
   TColor Color_Circle[5000];
};







#endif
