#ifndef LISTAGENERICA_H_INCLUDED
#define LISTAGENERICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef struct NOG
{
    void *Info;
    struct NOG *Prox;
}NOG;

typedef struct
{
    int NEL;
    NOG *Inicio;
}ListaGenerica;



ListaGenerica *CriarLG();
void DestruirLG(ListaGenerica *lg, void (*fdest)(void *));
void ShowLG(ListaGenerica *lg, void (*f)(void *));
void AddLG(ListaGenerica *lg, void *X);
int PertenceLG(ListaGenerica *lg, void *X, int (*fcomp)(void *, void *));

#endif // LISTAGENERICA_H_INCLUDED
