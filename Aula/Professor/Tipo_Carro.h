#ifndef TIPO_CARRO_H_INCLUDED
#define TIPO_CARRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO   1
#define INSUCESSO 0

typedef struct Carro
{
    char MATRICULA[9];
    char MARCA[20];
}Carro;

Carro *CriarCarro(char *mat, char *marc);
void DestruirCarro(Carro *X);
void MostrarCarro(Carro *X);

#endif // TIPO_CARRO_H_INCLUDED
