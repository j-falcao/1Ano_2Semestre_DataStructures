#include "TipoDados.h"
#include "Tree.h"
#include "Menu.h"

int IdPessoaConsecutivo = 0;

int main(){
    srand(time(NULL));
    Tree* T = createTree();
    menuPrincipal(T);
    printc("\n\t[yellow]A sair do programa?[/yellow]\n");
    return 0;
}