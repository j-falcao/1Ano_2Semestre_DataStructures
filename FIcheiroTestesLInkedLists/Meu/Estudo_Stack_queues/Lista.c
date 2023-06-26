#include "Conta_Bancaria.h"
#include "Lista.h"

Lista* CriarLista(){
    Lista *L = (Lista*) malloc(sizeof(Lista));
    L->head = NULL;
    L->Tail = NULL;
    L->n_el = 0;
    return L;
}


void addElem(Lista *L, Conta *C){
    if(!L || !C) return;

    NO *Caixinha = (NO*) malloc(sizeof(NO));
    Caixinha->info = C;
    Caixinha->next = L->head;
    L->head = Caixinha;
    L->n_el++;
    
}

void remElem(Lista *L){
    if(!L) return;

    NO *Aux = (NO*) malloc(sizeof(NO));
    Aux = L->head->next;
    free(L->head->info);
    free(L->head);
    L->head = Aux;
    L->n_el--;
}

void DestruirLista(Lista *L){
    if(!L) return;

    NO *Aux = (NO*) malloc(sizeof(NO)), *N = (NO*) malloc(sizeof(NO));
    N = L->head;
    while(N){
        Aux = N->next;
        free(N->info);
        free(N);
        N = Aux;
    }
    free(L);
}

void MostrarLista(Lista *L){
    if(!L) return;

    NO *N = (NO*) malloc(sizeof(NO));;
    N = L->head;

    while(N){
        MostrarConta(N->info);
        N = N->next;
    }
}

int ContarElementos(Lista *L){
    if(!L) return -1;

    int count = 0; 
    NO *Aux = (NO*) malloc(sizeof(NO));
    Aux = L->head;
    
    while(Aux){
        count++;
        Aux = Aux->next;
    }
    return count;
}




//Queue
void addElem_Queue(Lista *L, Conta *C){
    if(!L || !C) return;

    NO *Caixinha = (NO*) malloc(sizeof(NO));

    if(!L->head){
        L->head = Caixinha;
        L->Tail = Caixinha;
    }

    Caixinha->info = C;
    Caixinha->next = NULL;

    if(L->head){
    L->Tail->next = Caixinha;
    L->Tail = Caixinha;
    }

    L->n_el++;
}


//Ordered
void addElem_Order(Lista *L, Conta *C, int asc_desc){
    NO *PrevPtr = (NO*) malloc(sizeof(NO)), *CurrPtr = (NO*) malloc(sizeof(NO)), *Caixinha = (NO*) malloc(sizeof(NO));

    PrevPtr = NULL;
    CurrPtr = L->head;
    if(asc_desc == 0){
        while(CurrPtr != NULL && CurrPtr->info->balanco < C->balanco){
            PrevPtr = CurrPtr;
            CurrPtr = CurrPtr->next;
        }
    }
    else{
        while(CurrPtr != NULL && CurrPtr->info->balanco > C->balanco){
            PrevPtr = CurrPtr;
            CurrPtr = CurrPtr->next;
        }
    }
    
    Caixinha->info = C;

    if(!PrevPtr){
        Caixinha->next = L->head;
        L->head = Caixinha;
    }
    else{
        Caixinha->next = CurrPtr;
        PrevPtr->next = Caixinha;
    }
}