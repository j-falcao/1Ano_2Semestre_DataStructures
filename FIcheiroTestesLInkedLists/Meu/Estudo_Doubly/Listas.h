#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include "TipoDados.h"

typedef struct no{
    info *info;
    struct no *next, *prev;
}NO;

typedef struct{
    NO *inicio, *fim;
    int n_el;
}head;


head* criarLista();
void destruirLista(head *L);
void addElemento(head *L , info* I);
void eliminarElemento(head *L, info* I);
void removeFinal(head *L);
void mostrarLista(head *L);

#endif // LISTA_H_INCLUDED
