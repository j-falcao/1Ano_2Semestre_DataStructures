#ifndef TIPODADOS_H_INCLUDED
#define TIPODADOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    char palavra[50];
    char definicao[1000];
}Palavra;

Palavra* LerPalavra();
void DestruirPalavra(Palavra* P);
void mostrarPalavra(Palavra* P);

#endif