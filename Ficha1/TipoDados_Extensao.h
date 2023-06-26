#ifndef TIPODADOS_EXTENSAO_H_INCLUDED
#define TIPODADOS_EXTENSAO_H_INCLUDED

#include "TipoDados.h"


typedef struct{
    char nome[50];
    int n;
}info;

typedef struct no{
    info *info;
    struct no *next;
}NO;

typedef struct{
    NO *inicio;
}head;


//Funções Extensão
int GravarXML(REGISTO_UTILIZADORES *R, int N, char *ficheiro);

void ToLetrasGrandes(REGISTO_UTILIZADORES *R, int N);

char **SepararEspacos(char *s, int *tamanho);

int ListarUsersContain(REGISTO_UTILIZADORES *R, int N, char *subnome);

void initList(head **V, int N);
int converte(char *s);
info* criarInfo(char *nome);
NO* criarNo(head **V, int index, char *nome);
void procura_adicao(head **V, int index, char* nome, char* max, int* maxint);
char* NomeMaisComum(REGISTO_UTILIZADORES *R, int N, head **V, int tamanhoVetorHead);
void destruirlista_vetor(head **V, int N);

void performance_csv(REGISTO_UTILIZADORES *R, int N, head **V, int tamanhoVetorHead);

#endif