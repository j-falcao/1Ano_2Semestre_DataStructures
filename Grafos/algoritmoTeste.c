#include <stdlib.h>

typedef struct no {
    int vertice;
    struct no **next; 
}Grafo;

typedef struct{
    int nVertices;
    Grafo *head;
}Lista;

int main(){
    //init struct
    Lista *lista = (Lista*) malloc(sizeof *lista);
    lista->nVertices = 7;
    lista->head = (Grafo*) malloc(sizeof *lista->head);

    for (size_t i = 0; i < count; i++)
    {
        /* code */
    }
    

    int anteriores[lista->nVertices], custos[lista->nVertices];
    for(int i = 0; i < lista->nVertices; i++){
        anteriores[i] = -1;
        custos[i] = 1000000;
    }
    custos[0] = 0;
    
    lista->head->vertice = 7;





}