#include "Hashing.h"

Hashing* criarVectorHashing(){
    return (Hashing*) malloc(sizeof(Hashing));
}

void inicializarVectorHashing(Hashing *H){
    if(!H){
        printf("\n\tError! Given Hashing is NULL\n");
        return;
    }
    for(int i = 0; i < 10; i++){
        H->hash[i].faixaEtaria = i;
        H->hash[i].listaPessoas = criarLista();
    }
}

int posicaoHashingElemento(Elemento *E){
    return E->pessoa->idade / 10;
}

int validarPosicaoHashing(int pos){
    if(pos >= 0 && pos <= 9)
        return 1;
    return 0;
}

void inserirElementoHashing(Hashing *H, Elemento *eleInserir){
    if(!H){
        printf("\n\tError! Given Hashing is NULL\n");
        return;
    }
    if(!eleInserir){
        printf("\n\tError! Given element is NULL\n");
        return;
    }
    int posHash = posicaoHashingElemento(eleInserir);

    if(validarPosicaoHashing(posHash))
        inserirElementoOrdenadoIdade(H->hash[posHash].listaPessoas, eleInserir);
}

Elemento* removerElementoHashing(Hashing *H, Elemento *eleRemover){
    if(!H){
        printf("\n\tError! Given Hashing is NULL\n");
        return NULL;
    }
    if(!eleRemover){
        printf("\n\tError! Given element is NULLyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\n");
        return NULL;
    }
    int posHash = posicaoHashingElemento(eleRemover);

    if(validarPosicaoHashing(posHash))
        return removerElemento(H->hash[posHash].listaPessoas, eleRemover);
    return NULL;
}

Elemento* pesquisarElementoHashing(Hashing *H, Elemento *elePesquisa){
    if(!H){
        printf("\n\tError! Given Hashing is NULL\n");
        return NULL;
    }
    if(!elePesquisa){
        printf("\n\tError! Given element is NULLxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        return NULL;
    }
    int posHash = posicaoHashingElemento(elePesquisa);
    if(validarPosicaoHashing(posHash))
        return pesquisarElementoAutoComplete(H->hash[posHash].listaPessoas, elePesquisa);
    return NULL;
}

void mostrarElementosHashing(Hashing *H){
    if(!H){
        printf("\n\tError! Given Hashing is NULL\n");
        return;
    }

    for(int i = 0; i < 10; i++){
        if(H->hash[i].listaPessoas->head)
            printf("\nFaixa etaria: %d - %d", i*10, (i+1)*10);
        mostrarOrdenado(H->hash[i].listaPessoas);
    }
        
}
   