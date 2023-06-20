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

void criarLista();
void criarElemento();
void ler_elemento(Elemento eleNovo);
int compararElementosIdade(Elemento A, Elemento B);
int elementosIguais(Elemento A, Elemento B);
void inserirElementoOrdenadoIdade(Lista L, Elemento eleNovo);
Elemento pesquisarElemento(Lista L, Elemento elePesquisar);
void libertarElemento(Elemento ele_libertar);
Elemento removerElemento(Lista L, Elemento ele_remover);
void mostrarElemento(Elemento ele_mostrar);
void mostrarOrdenado(Lista L);



#endif