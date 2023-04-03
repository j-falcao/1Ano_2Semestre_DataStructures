
#include "Tipo_Carro.h"

Carro *CriarCarro(char *mat, char *marc)
{
    Carro *X = (Carro *)malloc(sizeof(Carro));
    strcpy(X->MATRICULA, mat);
    strcpy(X->MARCA, marc);
    return X;
}
void DestruirCarro(Carro *X)
{
    if (X) free(X);
}
void MostrarCarro(Carro *X)
{
    printf("MAT:[%s] MARCA: [%s]\n", X->MATRICULA, X->MARCA);
}
