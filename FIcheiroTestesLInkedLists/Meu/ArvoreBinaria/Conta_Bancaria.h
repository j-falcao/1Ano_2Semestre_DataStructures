#ifndef CONTA_BANCARIA_H_INCLUDED
#define CONTA_BANCARIA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int balanco;
    char tipo[20];
}Conta;

Conta *CriarConta(int balanco, char* tipo);
void DestrirConta(Conta* C);
void MostrarConta(Conta* C);


#endif