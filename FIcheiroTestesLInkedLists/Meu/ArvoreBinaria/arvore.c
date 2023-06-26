#include "arvore.h"

Arvore* CriarArvore(){
    Arvore* A = (Arvore*) malloc(sizeof(Arvore));
    A->altura = 0;
    A->n_el = 0;
    A->raiz = NULL;
}

void mostrarArvoreRecursivo(NO* Elemento){
    if(Elemento->esq == NULL)
        MostrarConta(Elemento->info);
}

void mostrarOrderedArvore(Arvore* A){
    if(!A) return;
    mostrarArvoreRecursivo(A->raiz);
}

NO* criarNO(Conta* info){
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->info = info;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void addEsq(NO* raiz, NO* novo){
    if(!raiz->esq)
        raiz->esq = novo;
    else if(novo->info->balanco > raiz->esq->info->balanco)
        addDir(raiz->esq, novo);
    else if(novo->info->balanco < raiz->esq->info->balanco)
        addEsq(raiz->esq, novo);
}

void addDir(NO* raiz, NO* novo){
    if(!raiz->dir)
        raiz->dir = novo;
    else if(novo->info->balanco > raiz->dir->info->balanco)
        addDir(raiz->dir, novo);
    else if(novo->info->balanco < raiz->dir->info->balanco)
        addEsq(raiz->dir, novo);
}

void addElem(Arvore* A, NO* no){
    if(!A||!no) return;

    if(A->raiz == NULL){
        NO* novo = (NO*) malloc(sizeof(NO));
        novo->esq = NULL;
        novo->dir = NULL;
        novo->info = no;
    }
    else{
        if(no->info->balanco > A->raiz->info->balanco)
            addDir(A->raiz, no);
        else if(no->info->balanco < A->raiz->info->balanco)
            addEsq(A->raiz, no);
    }
}

void inverterOrdenacao(NO* raiz){
    if(!raiz) return;
    NO* aux = raiz->esq;
    raiz->esq = raiz->dir;
    raiz->dir = aux;
    inverterOrdenacao(raiz->esq);
    inverterOrdenacao(raiz->dir);
}

int numVerticesNivel(NO* raiz, int nivel){
    if(!nivel && !raiz){
        return 1;
    }
    return numVerticesNivel(raiz->esq, nivel-1) + numVerticesNivel(raiz->dir, nivel-1);
}

void travessia(NO* Aux, NO* objetivo){
    
}

void remElem(Arvore* A, NO* info){

}
void pesquisa(Arvore* A, NO* info){

}
void destruir(Arvore* A){

}
