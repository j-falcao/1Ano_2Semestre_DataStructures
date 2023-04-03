#ifndef TIPODADOSPAPEL_H_INCLUDED
#define TIPODADOSPAPEL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO   1
#define INSUCESSO 0

typedef struct{
    int altura, largura;
}Papel;

Papel *CriarPapel(int altura, int largura);
void DestruirPapel(Papel *P);
void MostrarPapel(Papel *P);

#endif //TIPO_DadoPapel_H_INCLUDED