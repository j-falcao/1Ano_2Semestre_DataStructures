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
    int dia, mes, ano;
}DATA;

typedef struct
{
char *nome, *utilizador, *password, *email, *pagina_web_pessoal;
float joia;
DATA data_registo;
int telemovel, numero_acessos, id;
DATA data_ultimo_acesso;
}REGISTO_UTILIZADORES;


//Funções da parte 1
REGISTO_UTILIZADORES *LerFicheiro(int *nReg, char* nomeFicheiro);
void GuardarFicheiro(REGISTO_UTILIZADORES *R, int nReg, char *nomeficheiro);

REGISTO_UTILIZADORES *BubbleSort_data_registo(REGISTO_UTILIZADORES *R, int nReg, int order);
REGISTO_UTILIZADORES *OrdenarDataRegisto_BubbleSort(REGISTO_UTILIZADORES *R, int nReg);

REGISTO_UTILIZADORES *SelectionSort_data_ultimo_acesso(REGISTO_UTILIZADORES *R, int nReg, int order);
REGISTO_UTILIZADORES *OrdenarDataRegisto_SelectionSort_data_ultimo_acesso(REGISTO_UTILIZADORES *R, int nReg);

void swap(REGISTO_UTILIZADORES *R, int left, int right);
int partition(REGISTO_UTILIZADORES *R, int left, int right, int pivot, int asc_desc);
void QuickSort_ID(REGISTO_UTILIZADORES *R, int left, int right, int asc_desc);
void OrdenarID_QuickSort(REGISTO_UTILIZADORES *R, int nReg);


void LibertarMemoria(REGISTO_UTILIZADORES *R);


//Funções da parte 2
int ContarPessoasAcessoAno(REGISTO_UTILIZADORES *R, int nReg, int ano);

int LinearSearch_Nome(REGISTO_UTILIZADORES *R, int nReg, char *nomeTemp);
void PesquisarPessoaNome_LinearSearch(REGISTO_UTILIZADORES *R, int nReg);

void PesquisarPessoaId_BinarySearch(REGISTO_UTILIZADORES *R, int nReg);
int BinarySearch_Id(REGISTO_UTILIZADORES *R, int Id_search, int l, int r);

int PessoaMais_Acessos(REGISTO_UTILIZADORES *R, int nReg);

float TotalJoias(REGISTO_UTILIZADORES *R, int nReg);

int MesMaisRegistos_MinhaForma(REGISTO_UTILIZADORES *R, int nReg);
int MesMaisRegistos_FormaPedro(REGISTO_UTILIZADORES *R, int nReg);


//Funções extras
DATA DataValidaAleatoria(DATA data, int min, int max);
REGISTO_UTILIZADORES *GerarFicheiro_So_Para_Testes(int nReg, char *nomeficheiro);
int DataAntes_Depois(DATA d1, DATA d2);


void Menu_Sair(REGISTO_UTILIZADORES *R, int nReg, char *nomeficheiro);
void Menu_Ordenar(REGISTO_UTILIZADORES *R, int nReg);
void Menu_Pesquisar(REGISTO_UTILIZADORES *R, int nReg);

void ListarUtilizadores(REGISTO_UTILIZADORES *R, int nReg);

void Performance(REGISTO_UTILIZADORES *R, int nReg);

void Listar_PessoaIndividual(REGISTO_UTILIZADORES *R, int index);


#endif