#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include "TipoDados.h"

typedef struct no{
    Pessoa *pessoa;
    struct no *next;
}Elemento;

typedef struct{
    Elemento *head;
    int quantidadeElementos;
}Lista;

Lista* criarLista();
Elemento* criarElemento();
void lerElemento(Elemento *eleNovo);
void lerElementoManual(Elemento* eleNovo);
void lerElementoManualNomeIdade(Elemento* eleNovo);
int compararElementosIdade(Elemento *A, Elemento *B);
int elementosIguais(Elemento *A, Elemento *B);
void inserirElementoOrdenadoIdade(Lista *L, Elemento *eleNovo);
Elemento* pesquisarElemento(Lista *L, Elemento *elePesquisar);
Elemento* pesquisarElementoAutoComplete(Lista *L, Elemento *elePesquisar);
void libertarElemento(Elemento *eleLibertar);
Elemento* removerElemento(Lista *L, Elemento *eleRemover);
void mostrarElemento(Elemento *eleMostrar);
void mostrarOrdenado(Lista *L);

#endif