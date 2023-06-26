#include "TipoDados.h"
#include "Tree.h"
#include "Menu.h"

int IdPessoaConsecutivo = 0;

int main(){
    srand(time(NULL));
    Tree* T = createTree();
    menuPrincipal(T);
    return 0;
}