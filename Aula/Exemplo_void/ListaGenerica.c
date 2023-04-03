
#include "ListaGenerica.h"
ListaGenerica *CriarLG()
{
    printf("Uma dia .... <%s>\n", __FUNCTION__);
    ListaGenerica *L = (ListaGenerica *)malloc(sizeof(ListaGenerica));
    L->Inicio = NULL;
    L->NEL = 0;
    return L;
}
void DestruirLG(ListaGenerica *lg, void (*fdest)(void *))
{
    printf("Uma dia .... <%s>\n", __FUNCTION__);
    if (!lg) return;
    NOG *P = lg->Inicio;
    NOG *Rafael;
    while(P)
    {
        Rafael = P->Prox;
        fdest(P->Info);
        free(P);
        P = Rafael;
    }
    free(lg);
}
void ShowLG(ListaGenerica *lg, void (*f)(void *))
{
    printf("Uma dia .... <%s>\n", __FUNCTION__);
    if (!lg) return;
    NOG *P = lg->Inicio;
    while(P)
    {
        f(P->Info);
        P = P->Prox;
    }
}
void AddLG(ListaGenerica *lg, void *X)
{
    printf("Uma dia .... <%s>\n", __FUNCTION__);
    if (!lg || !X) return;
    NOG *P = (NOG *)malloc(sizeof(NOG));
    P->Prox = lg->Inicio;
    P->Info = X;
    lg->Inicio = P;
    lg->NEL++;
}
int PertenceLG(ListaGenerica *lg, void *X, int (*fcomp)(void *, void *))
{
    printf("Uma dia .... <%s>\n", __FUNCTION__);
    if (!lg || !X) return 0;
    NOG *P = lg->Inicio;
    while(P)
    {
        if (fcomp(P->Info, X) == 1) return 1;
        P = P->Prox;
    }
    return 0;
}
