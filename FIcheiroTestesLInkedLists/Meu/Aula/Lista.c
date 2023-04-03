#include "Lista.h"

ListHead *CriarLista(){
    ListHead *L = (ListHead*) malloc(sizeof(ListHead));
    L->inicio = NULL;
    L->N_El = 0;
    return L;
}
void DestruirLista(ListHead *L){
    if(!L) return;
    NO *Temp, *N = L->inicio;
    while(N){
        Temp = N->next;
        free(N->info);
        free(N);
        N = Temp;
    }
    free(L);
}
void addElem(ListHead *L, Papel *P){
    if(!L || !P) return;

    int flag = 0, escolha = -1;
    NO *Caixinha = (NO*) malloc(sizeof(NO)), *Aux, *Aux2;

    if(L->N_El < 1){
        Caixinha->info = P;
        Caixinha->next = L->inicio;
        L->inicio = Caixinha;
        L->Tail = Caixinha;
        L->N_El++;
        flag = 1;
    }

    if(flag == 0){
        printf("Quer por no inicio, algures no meio, ou no fim? (0 --> inicio | 1 --> meio | 2 --> fim)");
        scanf("%d", &escolha);
    }

    if(escolha == 0){
    Caixinha->next = L->inicio;
    Caixinha->info = P;
    L->inicio = Caixinha;
    L->N_El++;
    }

    else if(escolha == 1){
        if(L->N_El == 1){
            Caixinha->next = L->inicio;
            Caixinha->info = P;
            L->inicio = Caixinha;
            L->N_El++;
        }
        else{
        Aux = L->inicio;
        Caixinha->info = P;
        for (int i = 0; i < (L->N_El)/2; i++){
            Caixinha->next = Aux->next;
            Aux2 = Aux;
            Aux = Aux->next;
        }
        Aux2->next = Caixinha;
        L->N_El++;
        }
    }

    else if(escolha == 2){
        Caixinha->info = P;
        Caixinha->next = NULL;
        L->Tail->next = Caixinha;
        L->Tail = Caixinha;
        L->N_El++;
    }
}

void RemELem(ListHead *L, Papel *P){
    if(!L || !P) return;

    NO *Aux = L->inicio, *Aux_Passado;

    while(Aux->info->altura != P->altura || Aux->info->largura != P->largura){
        Aux_Passado = Aux;
        Aux = Aux->next;
    }
    printf("\n\nObjetivo: %d %d\nEncontrado: %d %d\nAnterior: %d %d\n\n", P->altura, P->largura, Aux->info->altura, Aux->info->largura, Aux_Passado->info->altura, Aux_Passado->info->largura);
    
    Aux_Passado->next = Aux->next;
    free(Aux->info);
    free(Aux);
}

void MostrarLista(ListHead *L){
    if(!L) return;
    NO *P = L->inicio;
    while(P != NULL){
        MostrarPapel(P->info);
        P = P->next;
    }
}