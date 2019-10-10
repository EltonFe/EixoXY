//---------------------------------------------------------------------------

#pragma hdrstop

#include "Arquivo.h"

#include <fstream>
#include <System.SysUtils.hpp>

using  Name_Arquivos::Objetos;
using Name_Arquivos::Arquivo;
using Name_Arquivos::Atributos;

//---------------------------------------------------------------------------
#pragma package(smart_init)

//Class Objetos-----------------------------------------------------

Objetos::Objetos(){

	Count_Line=0;



}

void Objetos::Draw_Parametros(Arquivo *arquivo,TPoint P1[300][2]){

float Mxyz1[100][2];
float Lxyz1[100][2];

float MZY[2];
float LZY[2];

Count_Line=arquivo->Contador9;
int i;



try{
	for(i=0;i<Count_Line;i++){
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


		Mxyz1[i][0]=(arquivo->MMVetorG9[i]*Cos(arquivo->MAlpha9[i]))*(Cos(arquivo->Alpha_Beta_Teta9[1])*Cos(arquivo->Alpha_Beta_Teta9[2])) -
		( (arquivo->MMVetorG9[i]*Sin(arquivo->MAlpha9[i]))*Cos( arquivo->Alpha_Beta_Teta9[1])*Sin(arquivo->Alpha_Beta_Teta9[2]))+arquivo->MZo9[i]*Sin(arquivo->Alpha_Beta_Teta9[1]);

		Mxyz1[i][1]=(arquivo->MMVetorG9[i]*Cos(arquivo->MAlpha9[i]))*(Sin(arquivo->Alpha_Beta_Teta9[0])*Sin(arquivo->Alpha_Beta_Teta9[1])*Cos(arquivo->Alpha_Beta_Teta9[2])+
		Cos(arquivo->Alpha_Beta_Teta9[0])*Sin(arquivo->Alpha_Beta_Teta9[2]))+(arquivo->MMVetorG9[i]*Sin(arquivo->MAlpha9[i]))*(-Sin(arquivo->Alpha_Beta_Teta9[0])*Sin(arquivo->Alpha_Beta_Teta9[1])*Sin(arquivo->Alpha_Beta_Teta9[2])+
		Cos(arquivo->Alpha_Beta_Teta9[0])*Cos(arquivo->Alpha_Beta_Teta9[2]))+arquivo->MZo9[i]*(-Sin(arquivo->Alpha_Beta_Teta9[0])*Cos(arquivo->Alpha_Beta_Teta9[1]));


		Lxyz1[i][0]=(arquivo->LMVetorG9[i]*Cos(arquivo->LAlpha9[i]))*(Cos(arquivo->Alpha_Beta_Teta9[1])*Cos(arquivo->Alpha_Beta_Teta9[2])) -
		( (arquivo->LMVetorG9[i]*Sin(arquivo->LAlpha9[i]))*Cos( arquivo->Alpha_Beta_Teta9[1])*
		Sin(arquivo->Alpha_Beta_Teta9[2]))+arquivo->LZo9[i]*Sin(arquivo->Alpha_Beta_Teta9[1]);

		Lxyz1[i][1]=(arquivo->LMVetorG9[i]*Cos(arquivo->LAlpha9[i]))*(Sin(arquivo->Alpha_Beta_Teta9[0])*Sin(arquivo->Alpha_Beta_Teta9[1])*Cos(arquivo->Alpha_Beta_Teta9[2])+
		Cos(arquivo->Alpha_Beta_Teta9[0])*Sin(arquivo->Alpha_Beta_Teta9[2]))+( arquivo->LMVetorG9[i]*Sin(arquivo->LAlpha9[i]) )*(-Sin(arquivo->Alpha_Beta_Teta9[0])*Sin(arquivo->Alpha_Beta_Teta9[1])*Sin(arquivo->Alpha_Beta_Teta9[2])+
		Cos(arquivo->Alpha_Beta_Teta9[0])*Cos(arquivo->Alpha_Beta_Teta9[2]))+arquivo->LZo9[i]*(-Sin(arquivo->Alpha_Beta_Teta9[0])*Cos(arquivo->Alpha_Beta_Teta9[1]));;


		this->P1[i][0].x= X(Mxyz1[i][0]);
		this->P1[i][0].y= Y(Mxyz1[i][1]);
		this->P1[i][1].x= X(Lxyz1[i][0]);
		this->P1[i][1].y= Y(Lxyz1[i][1]);
		P1[i][0].x= X(Mxyz1[i][0]);
		P1[i][0].y= Y(Mxyz1[i][1]);
		P1[i][1].x= X(Lxyz1[i][0]);
		P1[i][1].y= Y(Lxyz1[i][1]);


	}

}catch(Exception &ex){


}

}



int Objetos::X(int x){
	return x+Kx;
}

int Objetos::Y(int y){
	return Ky-y;
}

//Class Aquivo ----------------------------------------------------------------

Arquivo::Arquivo(){



}
void Arquivo::AbrirArquivo(char *Nome_Arquivo,Arquivo *arquivo){

	ifstream Arquivo_RR(Nome_Arquivo,ios::in|ios::binary);
	if(!Arquivo_RR){

	}else{
	 Arquivo_RR.read(reinterpret_cast< char *>(&this->Contador9),sizeof(int));
	 Arquivo_RR.read(reinterpret_cast< char *>(&this->ContadorCircle9),sizeof(int));
	Arquivo_RR.close();
	if((this->Contador9>0)||(this->ContadorCircle9>0)){







	}
	Sleep(200);
	ifstream Arquivo_WR(Nome_Arquivo,ios::in|ios::binary);
	if(!Arquivo_WR){

		}else{

		this->AlocandoAtributos();
		Arquivo_WR.read(reinterpret_cast< char *>(&this->Contador9),sizeof(int));
		Arquivo_WR.read(reinterpret_cast< char *>(&this->ContadorCircle9),sizeof(int));

		if(this->Contador9>0){
		Arquivo_WR.read(reinterpret_cast< char *>(this->MXo9),(this->Contador9)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(this->LXo9),(this->Contador9)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(this->MYo9),(this->Contador9)*sizeof(int));
		Arquivo_WR.read(reinterpret_cast< char *>(this->LYo9),(this->Contador9)*sizeof(int));
		Arquivo_WR.read(reinterpret_cast< char *>(this->MZo9),(this->Contador9)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(this->LZo9),(this->Contador9)*sizeof(float));

		Arquivo_WR.read(reinterpret_cast< char *>(this->Color9),(this->Contador9)*sizeof(DWORD));


		Arquivo_WR.read(reinterpret_cast< char *>(this->MAlpha9),(this->Contador9)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(this->LAlpha9),(this->Contador9)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(this->MMVetorG9),(this->Contador9)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(this->LMVetorG9),(this->Contador9)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(this->Alpha_Beta_Teta9),sizeof(this->Alpha_Beta_Teta9));

		}



		if(this->ContadorCircle9>0){


		for(int i=0;i< this->ContadorCircle9;i++)
		Arquivo_WR.read(reinterpret_cast< char *>(this->Center9[i]),3*sizeof(float));

		Arquivo_WR.read(reinterpret_cast< char *>(this->AZo9),(this->ContadorCircle9)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(this->BZo9),(this->ContadorCircle9)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(this->A9),(this->ContadorCircle9)*sizeof(float));
		Arquivo_WR.read(reinterpret_cast< char *>(this->B9),(this->ContadorCircle9)*sizeof(float));


		Arquivo_WR.read(reinterpret_cast< char *>(this->Color_Circle9),this->ContadorCircle9*sizeof(DWORD));

		Arquivo_WR.read(reinterpret_cast< char *>(this->Alpha_Beta_Teta_Circle9),sizeof(this->Alpha_Beta_Teta_Circle9));
		}


		Arquivo_WR.close();
		this->Count_Line=this->Contador9;
	}


//	//------------------------------
//	if(ContadorCircle>0){
//
//
//	}
//	}
//	Sleep(200);
//  ifstream Arquivo_WR(Nome_Arquivo,ios::in|ios::binary);
//  if(!Arquivo_WR){
//		ShowMessage("Problemas Ao Abrir Arquivo..!!");
//	}else{
//
//
//		Arquivo_WR.read(reinterpret_cast< char *>(&Form2->Contador),sizeof(Form2->Contador));
//		Arquivo_WR.read(reinterpret_cast< char *>(&Form2->ContadorCircle),sizeof(Form2->ContadorCircle));
//
//		if(Form2->Contador>0){
//		Arquivo_WR.read(reinterpret_cast< char *>(Form2->MXo),(Contador)*sizeof(float));
//		Arquivo_WR.read(reinterpret_cast< char *>(Form2->LXo),(Contador)*sizeof(float));
//		Arquivo_WR.read(reinterpret_cast< char *>(MYo),(Contador)*sizeof(int));
//		Arquivo_WR.read(reinterpret_cast< char *>(LYo),(Contador)*sizeof(int));
//		Arquivo_WR.read(reinterpret_cast< char *>(Form2->MZo),(Contador)*sizeof(float));
//		Arquivo_WR.read(reinterpret_cast< char *>(Form2->LZo),(Contador)*sizeof(float));
//
//		Arquivo_WR.read(reinterpret_cast< char *>(Form2->Color),(Contador)*sizeof(TColor));
//
//
//		Arquivo_WR.read(reinterpret_cast< char *>(Form2->MAlpha),(Contador)*sizeof(float));
//		Arquivo_WR.read(reinterpret_cast< char *>(Form2->LAlpha),(Contador)*sizeof(float));
//		Arquivo_WR.read(reinterpret_cast< char *>(Form2->MMVetorG),(Contador)*sizeof(float));
//		Arquivo_WR.read(reinterpret_cast< char *>(Form2->LMVetorG),(Contador)*sizeof(float));
//		Arquivo_WR.read(reinterpret_cast< char *>(Alpha_Beta_Teta),sizeof(Alpha_Beta_Teta));
//
//		}
//
//
//
//
//
//
//
//
//
//
//
//		if(Form2->ContadorCircle>0){
//
//
//		for(int i=0;i< ContadorCircle;i++)
//		Arquivo_WR.read(reinterpret_cast< char *>(Form2->Center[i]),3*sizeof(float));
//
//		Arquivo_WR.read(reinterpret_cast< char *>(Form2->AZo),(ContadorCircle)*sizeof(float));
//		Arquivo_WR.read(reinterpret_cast< char *>(Form2->BZo),(ContadorCircle)*sizeof(float));
//		Arquivo_WR.read(reinterpret_cast< char *>(Form2->A),(ContadorCircle)*sizeof(float));
//		Arquivo_WR.read(reinterpret_cast< char *>(Form2->B),(ContadorCircle)*sizeof(float));
//
//
//		Arquivo_WR.read(reinterpret_cast< char *>(Form2->Color_Circle),ContadorCircle*sizeof(TColor));
//
//		Arquivo_WR.read(reinterpret_cast< char *>(Alpha_Beta_Teta_Circle),sizeof(Alpha_Beta_Teta_Circle));
//		}
//		ShowMessage("Leitura Completa");
//		ShowMessage("Contador..:"+IntToStr(Form2->Contador));
//		Arquivo_WR.close();
//	}
//




	}


}


Arquivo *Arquivo::AbrirArquivo(char *Nome_Arquivo){

ifstream *Arquivo_WR;
int Tamanho=0;

	Arquivo_WR=new ifstream(Nome_Arquivo,std::ifstream::in|std::ifstream::binary);

	if(!Arquivo_WR){

	}else{
		Arquivo_WR->read(reinterpret_cast<char *>(&this->Contador9),sizeof(int));
		Arquivo_WR->read(reinterpret_cast<char *>(&this->ContadorCircle9),sizeof(int));


		if((this->Contador9>0)||(this->ContadorCircle9>0)){







		}




	 }







 return NULL;
}







//Class Atributos--------------------------------------------------------------

Atributos::Atributos(){

	Contador9=0;
	ContadorCircle9=0;
	MXo9=NULL;
	LXo9=NULL;
	MYo9=NULL;
	LYo9=NULL;
	MZo9=NULL;
	LZo9=NULL;
	Color9=NULL;
	MAlpha9=NULL;
	LAlpha9=NULL;
	MMVetorG9=NULL;
	LMVetorG9=NULL;
	Alpha_Beta_Teta9[3];

	Color_Circle9=NULL;

	A9=NULL;
	B9=NULL;
	AZo9=NULL;
	BZo9=NULL;
	Center9=NULL;
	Kx=1000;
	Ky=580;




}

float  * Atributos::Realocar(float *Ponteiro,int Tamanho){

   return (float*) realloc(Ponteiro,Tamanho*sizeof(float));

}
int  * Atributos::Realocar(int *Ponteiro,int Tamanho){

	return (int*) realloc(Ponteiro,Tamanho*sizeof(int));

}


void Atributos::AlocandoAtributos(){
	int i=0;
	if(ContadorCircle9>0){
		this->Color_Circle9=(DWORD *)realloc(this->Color_Circle9,(this->Contador9)*sizeof(DWORD));

		this->B9=Realocar(this->B9,this->Contador9);
		this->AZo9=Realocar(this->AZo9,this->Contador9);
		this->BZo9=	Realocar(this->BZo9,this->Contador9);



	//-------------------------------------------------------------------------
		this->Center9=(float**)realloc(this->Center9,(this->ContadorCircle9)*sizeof(float));
		this->Center9[this->ContadorCircle9]=NULL;
		for(i=0;i<(this->ContadorCircle9);i++){

		this->Center9[i]=(float *)realloc(this->Center9[i],3*sizeof(float));

		}
	}
	//--------------------------------------------------------------------------
	if(this->Contador9>0){
	this->Color9=(DWORD *)realloc(this->Color9,(this->Contador9)*sizeof(DWORD));
	this->LAlpha9=Realocar(this->LAlpha9,this->Contador9);

	this->MAlpha9=Realocar(this->MAlpha9,this->Contador9);
	this->MMVetorG9=Realocar(this->MMVetorG9,this->Contador9);
	this->LMVetorG9=Realocar(this->LMVetorG9,this->Contador9);
	this->MZo9=Realocar(this->MZo9,this->Contador9);
	this->LZo9=Realocar(this->LZo9,this->Contador9);
	this->MXo9=Realocar(this->MXo9,this->Contador9);
	this->LXo9=Realocar(this->LXo9,this->Contador9);
	this->MYo9=Realocar(this->MYo9,this->Contador9);
	this->LYo9=Realocar(this->LYo9,this->Contador9);
	}


}
