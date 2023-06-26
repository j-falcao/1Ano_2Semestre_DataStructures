#include "Conta_Bancaria.h"

Conta *CriarConta(int balanco, char *tipo){
    Conta *C = (Conta*) malloc(sizeof(Conta));
    C->balanco = balanco;
    strcpy(C->tipo, tipo);   
    printf("Criar COnta: %s\n", C->tipo);
    return C;
 
}

void DestrirConta(Conta* C){
    free(C);
}

void MostrarConta(Conta* C){
    printf("Saldo: %d\nTipo De cartao: %s\n\n", C->balanco, C->tipo);
}