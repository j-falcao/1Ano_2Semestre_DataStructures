#include "TipoDadosPapel.h"
#include "Lista.h"


int main(){
    printf("Estudo de listas ligadas!\n");

    ListHead *L = CriarLista();
    Papel *P = CriarPapel(20, 13);
    addElem(L, P);
    for (int i = 0; i < 5; i++){
        P = CriarPapel(20, i);
        addElem(L, P);
    }
    MostrarLista(L);
    RemELem(L, P);
    MostrarLista(L);
    DestruirLista(L);
    return 0;
}