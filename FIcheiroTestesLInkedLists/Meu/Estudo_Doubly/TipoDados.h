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
    int idade;
    char nome[20];
}info;

info* criarInfo(int idade, char* nome);
void removerInfo(info* I);
void mostraInfo(info* I);

#endif