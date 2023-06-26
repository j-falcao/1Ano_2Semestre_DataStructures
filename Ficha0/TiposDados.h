#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#include <math.h>
#define MAX_CC 20

typedef struct{
    char titulo[30];
    int ano, single, NDownloads, interprete;
}Musica;

void CarregarDados(int n, Musica *L);
void MostrarMusicas(int n, Musica *L);
void MostrarMusicasDownload(int n, Musica *L, int NumD);
int NumMusicaInterprete(int n, Musica *L, int interprete);
float GuardarMusica(int n, Musica *L, char single, int ano);


typedef struct{
    char nome[30];
    int avaliacao;
}UC;


typedef struct{
    char nome[30];
    int numMec;
    UC UCs[5];
    float media;
}Aluno;

void CarregarDadosAlunos(Aluno *A, int n);
void MostrarAlunos(Aluno *A, int n);
int qtosPassam(Aluno *A, int n);
float mediaUCsInfLim(Aluno *A, int n, int lim);
void GuardarDadosAlunos(Aluno *A, int n, int val, char *nomeFich);


typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char CC[MAX_CC], genero;
    float altura, massa;
    Data nascimento;
}Pessoa;

Data DataValidaAleatoria(Data data, int min, int max);
void CriarIndiv(Pessoa *P, int n);
void MostrarIndiv(Pessoa *P, int n);
int indSaudaveis(Pessoa *P, int n);
float MediaMassa(Pessoa *P, int n, int min, int max);
int RemoverIndiv(Pessoa *P, int n, char CC[MAX_CC]);