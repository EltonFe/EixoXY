#ifndef  UnitArquivoH
#define UnitArquivoH


class Desenho{
public:
int Posi;
float MAlpha[1000];
float LAlpha[1000];
float MMVetorGr[1000];
float LMVetorGr[1000];
float BetaT;
float MZo[1000];
float LZo[1000];

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



};


#endif