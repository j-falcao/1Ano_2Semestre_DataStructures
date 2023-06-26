#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "Conta_Bancaria.h"

typedef struct no{
    Conta* info;
    struct no *next;
}NO;

typedef struct{
    NO *head, *Tail;
    int n_el;
}Lista;


Lista* CriarLista();
void addElem(Lista *L, Conta *C);
void addElem_Queue(Lista *L, Conta *C);
void addElem_Order(Lista *L, Conta *C, int asc_desc);
void remElem(Lista *L);
void DestruirLista(Lista *L);
void MostrarLista(Lista *L);
int ContarElementos(Lista *L);



#endif







