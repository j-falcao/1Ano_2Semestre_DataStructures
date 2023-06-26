#include "Listas.h"

head* criarLista(){
    head *L = (head*) malloc(sizeof(head));
    L->inicio = NULL;
    L->n_el = 0;
    return L;
}

void destruirLista(head *L){
    if(!L) return;

    NO* Temp = (NO*) malloc(sizeof(NO));
    NO* Aux = (NO*) malloc(sizeof(NO));
    Aux = L->inicio;

    while(Aux){
        Temp = Aux->next;
        free(Aux->info);
        free(Aux);
        Aux = Temp;
    }
    free(L);
}

void addElemento(head *L, info *I){ //Adiciona ao fim 
    if(!L || !I) return;

    NO* Caixinha = (NO*) malloc(sizeof(NO));

    if(!L->inicio){
        printf("teste primeira vez\n\n");
        Caixinha->info = I;
        Caixinha->next = L->inicio;
        Caixinha->prev = NULL;
        L->inicio = Caixinha;
        L->fim = Caixinha;
        L->n_el++;
    }
    else{
        Caixinha->info = I;
        Caixinha->next = NULL;
        Caixinha->prev = L->fim;
        L->fim->next = Caixinha;
        L->fim = Caixinha;    
        L->n_el++;
    }

}

void eliminarElemento(head *L, info* I){
    if(!L || !I) return;

    NO* Caixinha = (NO*) malloc(sizeof(NO));
    Caixinha = L->inicio;

    int STOP = 0, flag = 0;

    while(Caixinha && !STOP){

        if(Caixinha->info->idade == I->idade && strcmp(Caixinha->info->nome, I->nome) == 0){
            if(Caixinha->prev){
                Caixinha->prev->next = Caixinha->next;
                flag = 1;
            }
            if(Caixinha->next != NULL){
                Caixinha->next->prev = Caixinha->prev;
                flag = 1;
            }
            if(flag == 0){
                L->inicio = NULL;
                L->fim = NULL;
            }
            
            free(Caixinha->info);
            free(Caixinha);
            L->n_el--;
            STOP = 1;
        }
        Caixinha = Caixinha->next;
    }
}

void removeFinal(head *L){
    if(!L) return;

    NO* temp = (NO*) malloc(sizeof(NO));

    temp = L->fim;
    L->fim = L->fim->prev;
    L->fim->next = NULL;
    free(temp->info);
    free(temp);
}

void mostrarLista(head *L){
    if(!L) return;

    NO* Aux = (NO*) malloc(sizeof(NO));
    Aux = L->inicio;

    printf("\n");
    while(Aux){
        mostraInfo(Aux->info);
        Aux = Aux->next;
    }
    printf("------------------------------\n");
}