#ifndef Lista_H_INCLUDED
#define Lista_H_INCLUDED

#include "TipoDados.h"



typedef struct no{
    Pessoa* info;
    struct no* next, *prev;
}Elemento;

typedef struct{
    Elemento* head, *Tail;
    int n_el;
}Lista;

typedef struct{
    int faixa_etaria;
    Lista* lista;
}Grupo;

typedef struct{
    Grupo vetor[10];
}Hashing;



#endif
