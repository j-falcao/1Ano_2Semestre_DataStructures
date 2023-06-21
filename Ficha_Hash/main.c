#include "TipoDados.h"
#include "Listas.h"
#include "Hashing.h"
#include "Menus.h"

int IdPessoaConsecutivo = 0, tamanhoVetorHash = 10;

int main(){
    srand(time(NULL));
    Hashing* HashVetor = criarVectorHashing();
    inicializarVectorHashing(HashVetor);
    printf("teste");
    menuPrincipal(HashVetor);
    return 0;
}