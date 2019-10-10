

#include "UnitArquivo.h"



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












