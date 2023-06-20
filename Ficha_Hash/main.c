#include "TipoDados.h"
#include "Listas.h"
#include "Hashing.h"
#include "Menus.h"

int IdConsecutivo = 0;

int main(){
    srand(time(NULL));
    
    //TESTES
    Pessoa* nova = gerarPessoaAleatoria();
    printf("NOME: %s\tIDADE: %d\tALTURA: %.2f\tPESO: %.2f", nova->nome, nova->idade, nova->altura_metros, nova->peso_quilos);

    /* menuPrincipal(); */
    return 0;
}