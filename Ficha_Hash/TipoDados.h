#ifndef TIPODADOS_H_INCLUDED
#define TIPODADOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    char nome[20];
    int idade;
    float peso_quilos, altura_metros;
}Pessoa;

Pessoa* gerarPessoaAleatoria();

extern int IdConsecutivo;
extern int Aleatorio(int min, int max);
#endif