#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "Tipo_Carro.h"

typedef struct no
{
    Carro      *Info;
    struct no  *Prox;
}NO;

typedef struct
{
    NO *Inicio;
    int NEL;
}Lista;

Lista *CriarLista();
void DestruirLista(Lista *L);
void Add(Lista *L, Carro *X);
void ShowLista(Lista *L);
int ComprimentoLista(Lista *L);
int Remover(Lista *L, char *mat);

#endif // LISTA_H_INCLUDED
