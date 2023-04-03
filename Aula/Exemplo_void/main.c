#include <stdio.h>
#include <stdlib.h>

#include "Tiposdados.h"
#include "ListaGenerica.h"



int main()
{
    printf("Programacao Mais Generica: Lista Generica!\n");
    ListaGenerica *LP = CriarLG();
    PESSOA *P = CriarPESSOA(1,"ze");
    AddLG(LP, P);
    ShowLG(LP, ShowPESSOA);

    ListaGenerica *LC = CriarLG();
    CAIXA *C = CriarCAIXA(1234, 1);
    AddLG(LC, C);
    C = CriarCAIXA(121, 0);
    AddLG(LC, C);
    ShowLG(LC, ShowCaixa);

    CAIXA *K = CriarCAIXA(34, 1);
    int ret = PertenceLG(LC, K, FCompCAIXAS);
    printf("Ret = %d\n", ret);

    ret = PertenceLG(LC, C, FCompCAIXAS);
    printf("Ret = %d\n", ret);

    DestruirLG(LC, DestruirCAIXA);
    DestruirLG(LP, DestruirPESSOA);

    return 0;
}
