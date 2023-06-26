#include "Lista.h"                                                          // Alínea 1, 2 e 3 estão no ficheiro "Lista.h"

Lista* criarLista(){                                                        // Alínea 4   
    Lista* L = (Lista*) malloc(sizeof(Lista));
    L->head = NULL;
    L->Tail  = NULL;
    strcpy(L->Lingua, "PT");
    L->n_el = 0;
    return L;
}

Elemento* criarElemento(){                                                  // Alínea 5
    Elemento* no = (Elemento*) malloc(sizeof(Elemento));
    no->info = (Palavra*) malloc(sizeof(Palavra));
    no->next = NULL;
    no->prev = NULL;
    return no;
}

int validarElemento(Elemento* E){                                           // Alínea 6
    char tmp_palavra[50], s[50];
    strcpy(tmp_palavra, E->info->palavra); 
    strcpy(s, E->info->definicao);

    for(int i = 0; i < strlen(tmp_palavra); i++){
        if(tmp_palavra[i] < 'A' || tmp_palavra[i] > 'Z' && tmp_palavra[i] < 'a' || s[i] > 'z')
            return 0;
    }
    
    for(int i = 0; i < strlen(s); i++){
        if(s[i] < 'A' || s[i] > 'Z' && s[i] < 'a' || s[i] > 'z')
            return 0;
    }
    return 1;
}

void LerElemento(Elemento* E){                                              // ALínea 7
    Palavra* InfP;
    do{
        InfP = LerPalavra();
        E->info = InfP;
    } while(validarElemento(E) == 0);
}

void inserir_elemento_inicio(Lista* L, Elemento* E){                        // Alínea 8
    if(!L||!E) return;

    if(L->head == NULL)
        L->Tail = E;
    
    E->next = L->head;
    L->head = E;
    L->n_el++;
}

void inserir_elemento_fim(Lista* L, Elemento* E){                           // Alínea 9
    if(!L||!E) return;

    if(L->head == NULL){
        E->next = L->head;
        L->head = E;
    }
    else{
        L->Tail->next = E;
        E->prev = L->Tail;
    }
    L->Tail = E;
    L->n_el++;
}

int comparar_elementos(Elemento* A, Elemento* B){                           // Alínea 10
    if(strcmp(A->info->palavra, B->info->palavra) == 0 && strcmp(A->info->definicao, B->info->definicao) == 0)
        return 1;
    else if(strcmp(A->info->palavra, B->info->palavra) == 0 && strcmp(A->info->definicao, B->info->definicao) < 0)
        return 2;
    else if(strcmp(A->info->palavra, B->info->palavra) == 0 && strcmp(A->info->definicao, B->info->definicao) > 0)
        return 3;
    else if(strcmp(A->info->palavra, B->info->palavra) < 0 && strcmp(A->info->definicao, B->info->definicao) < 0)
        return 4;
    else if(strcmp(A->info->palavra, B->info->palavra) < 0 && strcmp(A->info->definicao, B->info->definicao) > 0)
        return 5;
    else if(strcmp(A->info->palavra, B->info->palavra) < 0 && strcmp(A->info->definicao, B->info->definicao) == 0)
        return 6;
    else if(strcmp(A->info->palavra, B->info->palavra) > 0 && strcmp(A->info->definicao, B->info->definicao) < 0)
        return 7;
    else if(strcmp(A->info->palavra, B->info->palavra) > 0 && strcmp(A->info->definicao, B->info->definicao) > 0)
        return 8;
    else
        return 9;
}

int elementos_iguais(Elemento* A, Elemento* B){                             // Alínea 11
    if(strcmp(A->info->palavra, B->info->palavra) == 0)
        return 1;
    return 0;
}

void inserir_elemento_ordenado(Lista* L, Elemento*E){                       // Alínea 12
    if(!L||!E) return;

    Elemento* Prev = NULL, *Curr;
    Prev = NULL;
    Curr = L->head;
    int escolha;

    if(L->head == NULL){
        inserir_elemento_inicio(L, E);
    }

    printf("Quer inserir o elemento de forma ascendente ou descendente? (0 --> asc | 1 --> desc)");
    scanf("%d", &escolha);
    if(escolha){
        while(Curr != NULL && strcmp(Curr->info->palavra, E->info->palavra) > 0){
            Prev = Curr;
            Curr = Curr->next;
        }
    }
    else{
        while(Curr!= NULL && strcmp(Curr->info->palavra, E->info->palavra) < 0){
            Prev = Curr;
            Curr = Curr->next;
        }
    }

    if(!Prev && Curr){
        E->next = Curr; 
        L->head = E;
        Curr->prev = E;
    }
    else if(Prev && !Curr){
        Prev->next = E;
        E->prev = Prev;
        L->Tail = E;
    }
    else if (Prev && Curr){
        E->next = Curr;
        Curr->prev = E;
        Prev->next = E;
        E->prev = Prev;
    }
    else{
        L->head = E;
        L->Tail = E;
    }
        

    L->n_el++;
}

Elemento* pesquisar_iterativo(Lista* L, Elemento* E){                       // Alínea 13
    if(!L||!E) return NULL;

    Elemento* Aux = (Elemento*) malloc(sizeof(Elemento));

    while(Aux){
        if(elementos_iguais(Aux, E))
            return E;
        Aux = Aux->next;
    }
    free(Aux);
    return NULL;
}

Elemento* pesquisar_recursivo_algoritmo(Elemento* Lista, Elemento* E){      // Alínea 14 a)
    if(!Lista)
        return NULL;
    else if(elementos_iguais(Lista, E))
        return E;
    else
        return pesquisar_recursivo_algoritmo(Lista->next, E);

}

Elemento* pesquisar_recursivo(Lista* L, Elemento* E){                       // Alínea 14 b)
    if(!L||!E) return NULL;

    return pesquisar_recursivo_algoritmo(L->head, E);
}

int elementos_repetidos(Lista* L){                                          // Alínea 15
    if(!L) return 0;

    Elemento* Aux = (Elemento*) malloc(sizeof(Elemento));
    Elemento* Aux2 = (Elemento*) malloc(sizeof(Elemento));

    Aux = L->head;

    while(Aux){
        Aux2 = Aux->next;
        while(Aux2){
            if(elementos_iguais(Aux, Aux2)){
                free(Aux);
                free(Aux2);
                return 1;
            }
                
        }
    }
    free(Aux);
    free(Aux2);
    return 0;
}

void libertar_elemento(Elemento* E){                                        // Alínea 16
    DestruirPalavra(E->info);
    free(E);
}

Elemento* remover_elemento(Lista* L, Elemento* E){                          // Alínea 17
    if(!L||!E) return NULL;

    Elemento* Aux = (Elemento*) malloc(sizeof(Elemento));
    Aux = L->head;

    while(Aux){
        if(elementos_iguais(Aux, E) && Aux == L->head){
            L->head = Aux->next;
            Aux->next->prev = NULL;
            L->n_el--;
            Add_Fila_Libertar(Aux);
            return Aux;
        }
        else if(elementos_iguais(Aux, E) && Aux == L->Tail){
            L->Tail = Aux->prev;
            Aux->prev->next = NULL;
            L->n_el--;
            Add_Fila_Libertar(Aux);
            return Aux;
        }
        else if(elementos_iguais(Aux, E)){
            Aux->prev->next = Aux->next;
            Aux->next->prev = Aux->prev;
            L->n_el--;
            Add_Fila_Libertar(Aux);
            return Aux;
        }
        Aux = Aux->next;
    }
    return NULL;
}

Elemento* remover_primeiro(Lista* L){                                       // Alínea 18
    if(!L||!L->head) return NULL;

    Elemento* Aux = (Elemento*) malloc(sizeof(Elemento));
    Aux = L->head;

    Aux->next->prev = NULL;
    L->head = Aux->next;
    L->n_el--;
    Add_Fila_Libertar(Aux);
    return Aux;
}

Elemento* remover_ultimo(Lista* L){                                         // Alínea 19
    if(!L||!L->head) return NULL;

    Elemento* Aux = (Elemento*) malloc(sizeof(Elemento));
    Aux = L->Tail;

    L->Tail = Aux->prev;
    L->Tail->next = NULL;
    L->n_el--;
    Add_Fila_Libertar(Aux);
    return Aux;
}

void mostrar_elemento(Elemento* E){                                         // Alínea 20
    mostrarPalavra(E->info);
}

void mostrar_lista(Lista* L){                                               // Alínea 21
    if(!L) return;

    Elemento* Aux = (Elemento*) malloc(sizeof(Elemento));
    Aux = L->head;

    while(Aux){
        mostrar_elemento(Aux);
        Aux = Aux->next;
    }
    free(Aux);
}

void mostrar_inversa_v1_algoritmo(Elemento* lista){                         // Alínea 22 a)
    if(lista->next)
        mostrar_inversa_v1_algoritmo(lista->next);
    mostrar_elemento(lista);  
}

void mostrar_inversa_v1(Lista* L){                                          // Alínea 22 b)
    if(!L) return;

    mostrar_inversa_v1_algoritmo(L->head);
}

void mostrar_inversa_v2(Lista* L){                                          // Alínea 23
    if(!L) return;

    Elemento* Aux = (Elemento*) malloc(sizeof(Elemento));

    Aux = L->Tail;

    while(Aux){
        mostrar_elemento(Aux);
        Aux = Aux->prev;
    }
    free(Aux);
}

void destruirLista(Lista* L){                                               // Alínea 24
    if(!L) return;

    Elemento* Aux = (Elemento*) malloc(sizeof(Elemento));
    Elemento* Temp = (Elemento*) malloc(sizeof(Elemento));

    Aux = L->head;

    while(Aux){
        Temp = Aux->next;
        free(Aux->info);
        free(Aux);
        Aux = Temp;
    }
    free(Aux);
    free(Temp);
    free(L);
}

void exportar_ficheiro(Lista* L, char* nomeficheiro){                       // Alínea 25
    if(!L) return;

    FILE* fp = fopen(nomeficheiro, "w");

    if (!fp){
        printf("Impossivel abrir ficheiro!\n");
        return;
    }

    Elemento* Aux = (Elemento*) malloc(sizeof(Elemento));
    Aux = L->head;

    while(Aux){
        fprintf(fp, "%s: %s", Aux->info->palavra, Aux->info->definicao);
        Aux = Aux->next;
    }
    
    free(Aux);
}

void importar_ficheiro(Lista* L, char* nomeficheiro){                       // Alínea 26
    if(!L) return;

    FILE* fp = fopen(nomeficheiro, "r");

    if (!fp){
        printf("Impossivel abrir ficheiro!\n");
        return;
    }  

    Elemento* Aux = (Elemento*) malloc(sizeof(Elemento));

    while(Aux){
        fscanf(fp, "%s: %s", Aux->info->palavra, Aux->info->definicao);
        Aux = Aux->next;
    }
    
    free(Aux);
}
  
// Alíneas 27, 28 e 29 estão no ficheiro "menus.c"

void swap_elementos(Elemento* A, Elemento* B){                              // Alínea 30 a)
    if(!A||!B) return;

    Palavra* Temp = A->info;
    A->info = B->info;
    B->info = Temp;
}

void ordernar_lista_v1(Lista* L){                                           // Alínea 30 b)
    if(!L) return;

    Elemento* Aux = (Elemento*) malloc(sizeof(Elemento)), *Aux2 = (Elemento*) malloc(sizeof(Elemento));
    int escolha;

    printf("Quer ordenar a lista de forma ascendente ou descendente? (0 --> asc | 1 --> desc)");
    scanf("%d", &escolha);

    for (Aux = L->head; Aux->next != NULL; Aux = Aux->next){
        for (Aux2 = Aux; Aux2->next != NULL; Aux2 = Aux2->next){
            if(escolha){
                if(comparar_elementos(Aux2, Aux2->next) == 4 || comparar_elementos(Aux2, Aux2->next) == 5 || comparar_elementos(Aux2, Aux2->next) == 6)
                    swap_elementos(Aux2, Aux2->next);
            }
            else{
                if(comparar_elementos(Aux2, Aux2->next) == 7 || comparar_elementos(Aux2, Aux2->next) == 8 || comparar_elementos(Aux2, Aux2->next) == 9)
                    swap_elementos(Aux2, Aux2->next);
            }
        }
    }
    free(Aux);
    free(Aux2);    
}

void ordenar_lista_v2(Lista* L){                                            // Alínea 30 c)
    if(!L) return;

    Elemento* Aux, *Aux2, *Max_Min;
    int escolha;

    printf("Quer ordenar a lista de forma ascendente ou descendente? (0 --> asc | 1 --> desc)");
    scanf("%d", &escolha);

    for (Aux = L->head; Aux->next != NULL; Aux = Aux->next){
        Max_Min = Aux;
        for (Aux2 = Aux->next; Aux2 != NULL; Aux2 = Aux2->next){
            if(escolha){
                if(strcmp(Max_Min->info->palavra, Aux2->info->palavra) < 0){
                    Max_Min = Aux2;
                }
            }
            else{
                if(strcmp(Max_Min->info->palavra, Aux2->info->palavra) > 0){
                    Max_Min = Aux2;
                }
            }
        }
        if(Max_Min != Aux)
            swap_elementos(Aux, Max_Min);
    }

}

// _=============================> Extras <==================================_

extern Lista* Fila_Libertar;
extern int tamanhoMaximo_Fila_Libertar;

void Add_Fila_Libertar(Elemento* E){
    if(!E) return;

    inserir_elemento_fim(Fila_Libertar, E);
    if(Fila_Libertar->n_el > tamanhoMaximo_Fila_Libertar)
        remover_primeiro(Fila_Libertar);
}

void Limpar_Fila_Libertar(){           //Chamar no final do programa
    if(!Fila_Libertar) return;

    Elemento* Temp = (Elemento*) malloc(sizeof(Elemento));
    Elemento* Aux = (Elemento*) malloc(sizeof(Elemento));

    Aux = Fila_Libertar->head;

    while(Aux){
        Temp = Aux->next;
        libertar_elemento(Aux);
        free(Aux);
        Aux = Temp;
    }

    free(Aux);
    free(Temp);
    free(Fila_Libertar);
}