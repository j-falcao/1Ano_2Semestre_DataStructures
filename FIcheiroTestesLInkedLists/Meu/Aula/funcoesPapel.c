#include "TipoDadosPapel.h"

Papel *CriarPapel(int altura, int largura){
    Papel *P = (Papel*) malloc(sizeof(Papel));
    P->altura = altura;
    P->largura = largura;
    return P;
}
void DestruirPapel(Papel *P){
    if(P) free(P);
}
void MostrarPapel(Papel *P){
    printf("Altura: %d\nLargura: %d\n\n", P->altura, P->largura);
}