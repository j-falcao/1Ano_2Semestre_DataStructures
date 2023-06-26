#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "TipoDados.h"

typedef struct elemento{
    Palavra* info;
    struct elemento *next, *prev;
}Elemento;

typedef struct{
    Elemento *head, *Tail;
    char Lingua[3];
    int n_el;
}Lista;


Lista* criarLista();
Elemento* criarElemento();
int validarElemento(Elemento* E);
void LerElemento(Elemento* E);
void inserir_elemento_inicio(Lista* L, Elemento* E);
void inserir_elemento_fim(Lista* L, Elemento* E);
int comparar_elementos(Elemento* A, Elemento* B);
int elementos_iguais(Elemento* A, Elemento* B);
void inserir_elemento_ordenado(Lista* L, Elemento*E);
Elemento* pesquisar_iterativo(Lista* L, Elemento* E);
Elemento* pesquisar_recursivo_algoritmo(Elemento* Lista, Elemento* E);
Elemento* pesquisar_recursivo(Lista* L, Elemento* E);
int elementos_repetidos(Lista* L);
void libertar_elemento(Elemento* E);
Elemento* remover_elemento(Lista* L, Elemento* E);
Elemento* remover_primeiro(Lista* L);
Elemento* remover_ultimo(Lista* L);
void mostrar_elemento(Elemento* E);
void mostrar_lista(Lista* L);
void mostrar_inversa_v1_algoritmo(Elemento* lista);
void mostrar_inversa_v1(Lista* L);
void mostrar_inversa_v2(Lista* L);
void destruirLista(Lista* L);
void exportar_ficheiro(Lista* L, char* nomeficheiro);
void importar_ficheiro(Lista* L, char* nomeficheiro);
void ordernar_lista_v1(Lista* L);
void ordenar_lista_v2(Lista* L);


//Extras
void Add_Fila_Libertar(Elemento* E);
void Limpar_Fila_Libertar();

#endif