#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


#include "TipoDadosPapel.h"

typedef struct no{
    Papel *info;
    struct no *next;
}NO;

typedef struct{
    NO *inicio, *Tail;
    int N_El;
}ListHead;

ListHead *CriarLista();
void DestruirLista(ListHead *L);
void addElem(ListHead *L, Papel *P);
void RemELem(ListHead *L, Papel *P);
void MostrarLista(ListHead *L);

#endif //Lista_H_INCLUDED

