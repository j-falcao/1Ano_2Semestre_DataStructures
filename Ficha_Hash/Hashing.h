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

void inicializarVectorHashing(Hashing *H);
int posicaoHashingElemento(Elemento *E);
int validarPosicaoHashing(int pos);
void inserirElementoHashing(Hashing *H, Elemento *eleInserir);
Elemento removerElementoHashing(Hashing *H, Elemento *eleRemover);
Elemento pesquisarElementoHashing(Hashing *H, Elemento *elePesquisa);
void mostrarElementosHashing(Hashing *H);

#endif