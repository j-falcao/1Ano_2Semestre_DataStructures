#ifndef HASHING_H_INCLUDED
#define HASHING_H_INCLUDED

#include "Listas.h"

typedef struct{
    int faixaEtaria;
    Lista *listaPessoas;
}Grupo;

typedef struct{
    Grupo hash[10];
}Hashing;



#endif