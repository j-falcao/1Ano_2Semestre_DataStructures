#ifndef TIPOSDADOS_H_INCLUDED
#define TIPOSDADOS_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int ID_CAIXA;
    int ABERTOFECHADA;
}CAIXA;
typedef struct{
    int COD;
    char NOME[100];
}PESSOA;

CAIXA *CriarCAIXA(int _id, int af);
void ShowCaixa(void *X);
int FCompCAIXAS(void *X, void *Y);
void DestruirCAIXA(void *X);

PESSOA *CriarPESSOA(int _id, char *_nome);
void ShowPESSOA(void *X);
int FCompPESSOA(void *X, void *Y);
void DestruirPESSOA(void *X);

#endif // TIPOSDADOS_H_INCLUDED
