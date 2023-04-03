#include "Conta_Bancaria.h"

typedef struct no{
    Conta* info;
    struct no *esq, *dir;
}NO;

typedef struct{
    NO* raiz;
    int n_el, altura;
}Arvore;

Arvore* CriarArvore();
void mostrarArvore(Arvore* A);
void addElem(Arvore* A, NO* info);
void remElem(Arvore* A, NO* info);
void pesquisa(Arvore* A, NO* info);
void destruir(Arvore* A);


