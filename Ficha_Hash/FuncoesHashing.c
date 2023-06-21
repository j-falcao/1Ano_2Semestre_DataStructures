#include "Hashing.h"

Hashing* criarVectorHashing(){
    return (Hashing*) malloc(sizeof(Hashing));
}

void inicializarVectorHashing(Hashing *H){
    for(int i = 0; i < 10; i++){
        H->hash[i]->faixaEtaria = i;
        H->hash[i]->listaPessoas = criarLista();
    }
}

int posicaoHashingElemento(Elemento *E){
    
}

int validarPosicaoHashing(int pos){

}

void inserirElementoHashing(Hashing *H, Elemento *eleInserir){

}

Elemento* removerElementoHashing(Hashing *H, Elemento *eleRemover){

}

Elemento* pesquisarElementoHashing(Hashing *H, Elemento *elePesquisa){

}

void mostrarElementosHashing(Hashing *H){

}
   