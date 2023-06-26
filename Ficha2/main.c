#include "TipoDados.h"
#include "Lista.h"
#include "Menus.h"

Lista* Fila_Libertar;
int tamanhoMaximo_Fila_Libertar = 30;

int main(){                                                     // Alínea 31
  char nomeficheiro[20] = "Ficha2/Ficheiro.txt";

  Lista* L = criarLista();  
  Fila_Libertar = criarLista();

  menu_principal(L, nomeficheiro);
}

  


