//---------------------------------------------------------------------------

#ifndef UnitDesenha3DsH
#define UnitDesenha3DsH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>

class VetorDes3Ds{
public:
   VetorDes3Ds(long double);
   int X(int x);
   int Y(int y);
   int OX(float x);
   int OY(float y);
   int OXDes2(int x);
   int OYDes2(int y);
   long double EixoXo(long double ,long double  ,  long double *,long double *);
   int EixoYo(long double zo, long double Alphat,long double Betat,long double MVetor);
   float EixoXMo(long double ,long double );
   float EixoYMo(long double ,long double ,long double, long double );
   long double GetLAlpha(int );
   long double  GetMAlpha(int);
   long double GetLMVetorG(int );
   long double GetMMVetorG(int);
   long double GetBetaT();
   void SetLAlpha(long double  ,int );
   void  SetMAlpha(long double , int);
   void SetLMVetorG(long double ,int );
   void SetBetaT(long double);
   void SetMMVetorG(long double ,int i);
   int GetContador();
   long double GetMZo(int);
   void SetMZo(long double ,int  );
   long double GetLZo(int);
   void SetLZo(long double,int);
   void SetPosi1(int);
   long double GetA(int);
   long double GetB(int);
   long double GetAZo(int);
   long double GetBZo(int);
   int GetContCircle();
   void GetCenter(int,float [1000][3]);
   void SetA(int,float);
   void SetB(int,float);
   void SetAZo(int,float);
   void SetBZo(int,float);
   void SetCenter(int,float,float,float);
   void SetContCircle(int);
   long double GetTeta();

   void RealocaMemoria();
   void RotaXY(long double *x1,long double *y1,long double zo,long double Alphat,long double Betat,long double MVetort, long double Teta);

   void Set_Color(DWORD Set_Color);
   TColor Get_Color();
   void Set_Color_Camada(int *S_Color_Camada,int Index);
   int Get_Color_Camada(int Index);

   private:
    int Kx;
    int Ky;
    long double KOx;
	long double KOy;
    long double *LAlpha;
    long double *MAlpha;
    long double *LMVetorG;
    long double *MMVetorG;
    long double *MZo;
    long double *LZo;
	long double A[1000];
	long double B[1000];
	long double AZo[1000];
	long double BZo[1000];
	long double Center[1000][3];
    int ContadorCircle;
    int Contador;
    long double Beta;
    long double Teta;
	TColor  Color;
	int Color_Camada[2000];



};








#endif
