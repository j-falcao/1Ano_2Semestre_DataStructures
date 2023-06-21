#include "Listas.h"

Lista* criarLista(){
    Lista *novaLista = (Lista*) malloc(sizeof(Lista));
    novaLista->head = NULL;
    novaLista->quantidadeElementos = 0;
    return novaLista;
}

Elemento* criarElemento(){
    Elemento *novoElemento = (Elemento*) malloc(sizeof(Elemento));
    novoElemento->pessoa = NULL;
    novoElemento->next = NULL;
    return novoElemento;
}

void lerElemento(Elemento *eleNovo){
    eleNovo->pessoa = gerarPessoaAleatoria();
}


void lerElementoManual(Elemento* eleNovo){
    eleNovo->pessoa = gerarPessoaManual();
}

void lerElementoManualNomeIdade(Elemento* eleNovo){
    eleNovo->pessoa = gerarPessoaManualNomeIdade();
}

int compararElementosIdade(Elemento *A, Elemento *B){
    if(!A || !B){
        printf("\n\tError! Given Element is NULL.\n");
        return 0;
    }

    if(A->pessoa->idade == B->pessoa->idade)
        return 1;
    return 0;
}

int elementosIguais(Elemento *A, Elemento *B){
    if(!A || !B){
        printf("\n\tError! Given element is NULL.\n");
        return 0;
    }

    if(strcmp(A->pessoa->nome, B->pessoa->nome) == 0 && A->pessoa->idade == B->pessoa->idade && A->pessoa->altura_metros == B->pessoa->altura_metros && A->pessoa->peso_quilos == B->pessoa->peso_quilos)
        return 1;
    return 0;
}

void inserirElementoOrdenadoIdade(Lista *L, Elemento *eleNovo){
    if(!L){
        printf("\n\tError! Given lista is NULL.\n");
        return;
    }
    if(!eleNovo){
        printf("\n\tError! Given element is NULL.\n");
        return;
    }
    if(L->head == NULL){
        L->head = eleNovo;
        L->quantidadeElementos++;
        return;
    }


    Elemento *prev = NULL, *curr = L->head;
    while(curr->pessoa->idade <= eleNovo->pessoa->idade){
        prev = curr;
        curr = curr->next;
        if(!curr)
            break;
    }
    if(prev == NULL){
        L->head = eleNovo;
    }
    else if(!elementosIguais(prev, eleNovo)){
        prev->next = eleNovo;
    }
    eleNovo->next = curr;
    L->quantidadeElementos++;
}

Elemento* pesquisarElemento(Lista *L, Elemento *elePesquisar){
    if(!L){
        printf("\n\tError! Given lista is NULL.\n");
        return NULL;
    }
    if(!elePesquisar){
        printf("\n\tError! Given element is NULL.\n");
        return NULL;
    }

    Elemento *aux = L->head;
    while(aux){
        if(elementosIguais(aux, elePesquisar)) 
            return aux;
        aux = aux->next;
    }
    return NULL;
}

Elemento* pesquisarElementoAutoComplete(Lista *L, Elemento *elePesquisar){
    if(!L){
        printf("\n\tError! Given lista is NULL.\n");
        return NULL;
    }
    if(!elePesquisar){
        printf("\n\tError! Given element is NULL.\n");
        return NULL;
    }

    Elemento *aux = L->head;
    while(aux){
        if(strcmp(aux->pessoa->nome, elePesquisar->pessoa->nome) == 0) 
            return aux;
        aux = aux->next;
    }
    return NULL;
}

void libertarElemento(Elemento *eleLibertar){
    free(eleLibertar->pessoa);
    free(eleLibertar);
}

Elemento* removerElemento(Lista *L, Elemento *eleRemover){
    if(!L){
        printf("\n\tError! Given lista is NULL.\n");
        return NULL;
    }
    if(!eleRemover){
        printf("\n\tError! Given element is NULL.\n");
        return NULL;
    }

    Elemento *prev = L->head, *curr = L->head, *removido;
    while(!elementosIguais(curr, eleRemover) && curr){
        prev = curr;
        curr = curr->next;
    }

    if(prev == curr){
        removido = eleRemover;
        L->head = L->head->next;
    }
    else if(!curr){
        printf("\n\tError! Given element is not in list\n");
        return NULL;
    }
    else{
        removido = curr;
        prev->next = prev->next->next;
    }
    L->quantidadeElementos--;
    printf("[green]\n\tElemento removido com sucesso![/green]\n");
    return removido;
}

void mostrarElemento(Elemento *eleMostrar){
    if(!eleMostrar){
        printf("\n\tError! Given element is NULL.\n");
        return;
    }
    
    printc("\n\t[green]NOME:[/green] %s  [green]IDADE:[/green] %d  [green]ALTURA:[/green] %.2f  [green]PESO:[/green] %.2f\n", eleMostrar->pessoa->nome, eleMostrar->pessoa->idade, eleMostrar->pessoa->altura_metros, eleMostrar->pessoa->peso_quilos);
}

void mostrarOrdenado(Lista *L){
    if(!L){
        printf("\n\tError! Given lista is NULL.\n");
        return;
    }
    printf("\n");

    Elemento *Aux = L->head;
    while(Aux){
        mostrarElemento(Aux);
        Aux = Aux->next;
    }
}
