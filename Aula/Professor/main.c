#include <stdio.h>
#include <stdlib.h>

#include "Tipo_Carro.h"
#include "Lista.h"

int main()
{
    printf("Inicio das Listas!\n");

    Lista *LC = CriarLista();
    Carro *X = CriarCarro("56-67-AB", "Opel");
    Add(LC, X);
    for (int i = 0; i < 5; i++)
    {
        char mat[10];
        sprintf(mat, "%d%d-34-BG", i, i+1);
        X = CriarCarro(mat, "Citroen");
        Add(LC, X);
    }
    ShowLista(LC);
    DestruirLista(LC);
    return 0;
}
