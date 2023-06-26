#include "TipoDados.h"
#include "Listas.h"

int main(){
    info *I;
    head *L = criarLista();

    for (int i = 0; i < 5; i++)
    {
        I = criarInfo(i, "joao");
        addElemento(L, I);
    }
    mostrarLista(L);
    
    I = criarInfo(2, "joao");
    eliminarElemento(L, I);

    mostrarLista(L);

    removeFinal(L);
    mostrarLista(L);

    destruirLista(L);

}