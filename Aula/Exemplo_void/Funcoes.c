
#include "Tiposdados.h"

CAIXA *CriarCAIXA(int _id, int af)
{
    CAIXA *X = (CAIXA *)malloc(sizeof(CAIXA));
    X->ID_CAIXA = _id;
    X->ABERTOFECHADA = af;
    return X;

}
void ShowCaixa(void *X)
{
    CAIXA *Y = (CAIXA *)X;
    printf("[%s]\n", __FUNCTION__);
    printf("ID: %d, AF: %d\n", Y->ID_CAIXA, Y->ABERTOFECHADA);
}

int FCompCAIXAS(void *X, void *Y)
{
    CAIXA *cx = (CAIXA *)X;
    CAIXA *cy = (CAIXA *)Y;
    if (cx->ID_CAIXA == cy->ID_CAIXA) return 1;
    return 0;
}
void DestruirCAIXA(void *X)
{
    CAIXA *Y = (CAIXA *)X;
    free(Y);
}

PESSOA *CriarPESSOA(int _id, char *_nome)
{
    PESSOA *X = (PESSOA *)malloc(sizeof(PESSOA));
    X->COD = _id;
    strcpy(X->NOME, _nome);
    return X;

}
void ShowPESSOA(void *X)
{
    PESSOA *P = (PESSOA *)X;
    printf("[%s]\n", __FUNCTION__);
    printf("COD: %d, NOME: [%s]\n", P->COD, P->NOME);

}
int FCompPESSOA(void *X, void *Y)
{
    PESSOA *px = (PESSOA *)X;
    PESSOA *py = (PESSOA *)Y;
    if (px->COD == py->COD) return 1;
    return 0;

//    if (stricmp(px->NOME, py->NOME) == 0) return 1;
//    return 0;
}

void DestruirPESSOA(void *X)
{
    PESSOA *P = (PESSOA *)X;
    //free(P->NOME);
    free(P);
}
