//---------------------------------------------------------------------------

#ifndef ArquivoH
#define ArquivoH
//---------------------------------------------------------------------------
#include <System.Types.hpp>
namespace Name_Arquivos{
	class Atributos{
		public:
		 int Contador9;
		 int ContadorCircle9;
		 float *MXo9;
		 float *LXo9;
		 float *MYo9;
		 float *LYo9;
		 float  *MZo9;
		 float  *LZo9;
		 DWORD *Color9;
		 float  *MAlpha9;
		 float  *LAlpha9;
		 float  *MMVetorG9;
		 float  *LMVetorG9;
		 float Alpha_Beta_Teta9[3];

		 float **Center9;
		 float *AZo9;
		 float *BZo9;
		 float *A9;
		 float *B9;
		 DWORD *Color_Circle9;
		 float Alpha_Beta_Teta_Circle9[3];

		 int Kx;
		 int Ky;


		//------------------------------------------------------------------
		Atributos();
		float  * Realocar(float *Poneteiro,int Tamanho);
		int  * Realocar(int *Ponteiro,int Tamanho);
		void AlocandoAtributos();
		float *Alocando(float *Ponteiro,int Tamanho);
		int *Alocando(int *Ponteiro,int Tamanho);




	};


	class Arquivo:public Atributos{
	public:
		int Count_Line;
		Arquivo();
		void AbrirArquivo(char *Nome_Arquivo,Arquivo *arquivo);
		Arquivo *AbrirArquivo(char *Nome_Arquivo);

	};

	class Objetos:public Atributos{
		public :

		//---------------------------------------------------------------------

		//---------------------------------------------------------------------
		TPoint P1[300][2];
		int Count_Line;
		Objetos();
		void Draw_Parametros(Arquivo *arquivo,TPoint P1[300][2]);
		int X(int x);
		int Y(int y);








    };








}


#endif
