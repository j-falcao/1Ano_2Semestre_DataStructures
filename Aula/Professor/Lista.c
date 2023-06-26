
#include "Lista.h"

Lista *CriarLista()
{
    Lista *K = (Lista *)malloc(sizeof(Lista));
    K->Inicio = NULL;
    K->NEL = 0;
    return K;
}
void DestruirLista(Lista *L)
{
    if (!L) return;
    NO *P = L->Inicio;
    NO *Ajud;
    while (P)
    {
        Ajud = P->Prox;
        free(P->Info);
        free(P);
        P = Ajud;
    }
    //free(L);
}

void Add(Lista *L, Carro *X)
{
    if (!L || !X) return;
    NO *Caixinha = (NO *)malloc(sizeof(NO));
    Caixinha->Info = X;
    Caixinha->Prox = L->Inicio;
    L->Inicio = Caixinha;
    L->NEL++;
}
void ShowLista(Lista *L)
{
    if (!L) return;
    NO *P = L->Inicio;
    while (P != NULL)
    {
        Carro *X = P->Info;
        MostrarCarro(X);
        P = P->Prox;
    }
}

int ComprimentoLista(Lista *L)
{
    if (!L) return -1;
    return L->NEL;
}
int Remover(Lista *L, char *mat)
{
    return INSUCESSO;
}
