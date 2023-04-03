#include "TipoDados.h"

Palavra* LerPalavra(){
    Palavra* InfP = (Palavra*) malloc(sizeof(Palavra));
    printf("Insira a palavra: ");
    scanf("%s", InfP->palavra);
    printf("Insira a definicao: ");
    scanf("%s", InfP->definicao);
    return InfP;
}

void DestruirPalavra(Palavra* P){
    free(P);
}

void mostrarPalavra(Palavra* P){
    printf("Palavra: %s\nDefinicao: %s\n\n", P->palavra, P->definicao);
}