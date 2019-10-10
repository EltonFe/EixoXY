//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdlib.h>
#pragma hdrstop

#include "UnitElipse.h"
#include "UnitEixoXY.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;

//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{

Form2->P_Circle=NULL;
}
//---------------------------------------------------------------------------


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

//----------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
 float *AS=new float[1000];
 float *BS=new float[1000];
 float *ASZ=new float[1000];
 float *BSZ=new float[1000];
 int j=0;
 int i=0;

 Form2->Color_Circle=(TColor *)realloc(Form2->Color_Circle,(Form2->ContadorCircle+1)*sizeof(TColor));
 Form2->Color_Circle[Form2->ContadorCircle]=Form2->ColorBox1->Selected;


 if (Edit1->Text.IsEmpty()){
 Edit1->Text="0";

 }
 if (Edit2->Text.IsEmpty()){
 Edit2->Text="0";
 }
 if (Edit3->Text.IsEmpty()){

 Edit3->Text="0";
 }

 Form2->A=(float *)realloc(Form2->A,(Form2->ContadorCircle+1)*sizeof(float));
 Form2->B=(float *)realloc(Form2->B,(Form2->ContadorCircle+1)*sizeof(float));
 Form2->AZo=(float *)realloc(Form2->AZo,(Form2->ContadorCircle+1)*sizeof(float));
 Form2->BZo=(float *)realloc(Form2->BZo,(Form2->ContadorCircle+1)*sizeof(float));
 Form2->Center_Vetor=(float *)realloc(Form2->Center_Vetor,(Form2->ContadorCircle+1)*sizeof(float));
 Form2->Center_Angulo=(float *)realloc(Form2->Center_Angulo,(Form2->ContadorCircle+1)*sizeof(float));

 Form2->Center=(float**)realloc(Form2->Center,(Form2->ContadorCircle+1)*sizeof(float));
 Form2->Center[Form2->ContadorCircle]=NULL;
 for(i=0;i<(Form2->ContadorCircle+1);i++){

 Form2->Center[i]=(float *)realloc(Form2->Center[i],3*sizeof(float));

 }
 Form2->P_Circle=(TPoint **)realloc(Form2->P_Circle,(Form2->ContadorCircle+1)*sizeof(TPoint));
 Form2->P_Circle[Form2->ContadorCircle]=NULL;
 for(i=0;i<Form2->ContadorCircle+1;i++)
 Form2->P_Circle[i]=(TPoint*)realloc(Form2->P_Circle[i],51*sizeof(TPoint));




 

 Form2->A[Form2->ContadorCircle]= Edit1->Text.ToDouble();

 Form2->AZo[Form2->ContadorCircle]= Edit2->Text.ToDouble();

 Form2->B[Form2->ContadorCircle]=Edit3->Text.ToDouble();

 Form2->BZo[Form2->ContadorCircle]= Edit4->Text.ToDouble();


 Form2->Center[Form2->ContadorCircle][0]=Edit5->Text.ToDouble();
 Form2->Center[Form2->ContadorCircle][1]=Edit6->Text.ToDouble();
 Form2->Center[Form2->ContadorCircle][2]=Edit7->Text.ToDouble();
 EixoXo( Edit5->Text.ToDouble(),Edit6->Text.ToDouble(),0,&Form2->Center_Angulo[Form2->ContadorCircle],&Form2->Center_Vetor[Form2->ContadorCircle]);


 Form2->ContadorCircle++;
 Edit1->Text="0,0";
 Edit2->Text="0,0" ;
 Edit3->Text="0,0";
 Edit4->Text="0,0";
 Edit5->Text="0,0";
 Edit6->Text="0,0";
 Edit7->Text="0,0";

 if(Form2->RadioXoY->Checked)
	Form2->Circle_Vetor(Form2->A,Form2->AZo,Form2->B,Form2->BZo,Form2->P_Circle,Form2->Center);
 else
 Form2->Circle_VetorXZ(Form2->A,Form2->AZo,Form2->B,Form2->BZo,Form2->P_Circle,Form2->Center);
 Form2->CheckBox2->Checked=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormCreate(TObject *Sender)
{
Form2->ContadorCircle=0;
if(Form4->Visible)
Edit3->SetFocus();

}
//---------------------------------------------------------------------------
void __fastcall TForm4::Edit3Exit(TObject *Sender)
{
Button1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Edit1Exit(TObject *Sender)
{
Edit3->SetFocus();
}
//---------------------------------------------------------------------------

