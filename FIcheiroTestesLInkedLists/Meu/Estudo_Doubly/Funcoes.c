#include "TipoDados.h"

info* criarInfo(int idade, char* nome){
    info* I = (info*) malloc(sizeof(info));
    I->idade = idade;
    strcpy(I->nome, nome);
    return I;
}
void removerInfo(info* I){
    free(I);
}
void mostraInfo(info* I){
    printf("Nome: %s\nIdade: %d\n\n", I->nome, I->idade);
}