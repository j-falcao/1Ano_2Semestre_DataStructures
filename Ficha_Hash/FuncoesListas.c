#include "Listas.h"


Lista *criarLista(){
    Lista *novaLista = (Lista*) malloc(sizeof(Lista));
    novaLista->head = NULL;
    novaLista->quantidadeElementos = 0;
    return novaLista;
}

Elemento *criarElemento(){
    Elemento *novoElemento = (Elemento*) malloc(sizeof(Elemento));
    novoElemento->pessoa = NULL;
    novoElemento->next = NULL;
    return novoElemento;
}

void ler_elemento(Elemento eleNovo){
    eleNovo.pessoa = gerarPessoaAleatoria();
}

int compararElementosIdade(Elemento *A, Elemento *B){

}

int elementosIguais(Elemento *A, Elemento *B){

}

void inserirElementoOrdenadoIdade(Lista *L, Elemento *eleNovo){

}

Elemento pesquisarElemento(Lista *L, Elemento *elePesquisar){

}

void libertarElemento(Elemento *eleLibertar){

}

Elemento removerElemento(Lista *L, Elemento *eleRemover){

}

void mostrarElemento(Elemento *eleMostrar){

}

void mostrarOrdenado(Lista *L){

}
