#include "Lista.h"

Lista* criarLista(){
    Lista* L = (Lista*) malloc(sizeof(Lista));
    L->head = NULL;
    L->Tail = NULL;
    L->n_el = 0;
    return L;
}

/* typedef struct{
    char nome[30];
    int idade;
    float altura, peso;
}Pessoa; */

void lerPessoa(Elemento* novo){
    printf("Insira o nome da pessoa: ");
    scanf("%s", novo->info->nome);
    printf("Insira a idade da pessoa: ");
    scanf("%d", novo->info->idade);
    printf("Insira a altura da pessoa: ");
    scanf("%f", novo->info->altura);
    printf("Insira o peso da pessoa: ");
    scanf("%f", novo->info->peso);
}

Elemento* criarElemento(){
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    lerPessoa(novo);
    novo->next = NULL;
    novo->prev = NULL;
    return novo;
}

Hashing* criar_vetor_hashing(){
    Hashing* vetor = (Hashing*) malloc(sizeof(Hashing));
    for(int i = 0; i < 10; i++){
        vetor->vetor[i].faixa_etaria = i*10;
        vetor->vetor[i].lista = criarLista();
    }
}

