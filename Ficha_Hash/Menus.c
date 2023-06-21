#include "Menus.h"

int menuPrincipal(Hashing* HashVetor){
    int opcao;
    do{
        int i = 0;
        printc("**************************************************\n");
        printc("****************   [blue]Menu Funcionário[/blue]  *************\n");
        printc("**************************************************\n");
        printc("**        [blue]%d [/blue]-> Inserir elemento hashing         **\n", i++);
        printc("**        [blue]%d [/blue]-> Remover elemento hashing         **\n", i++);
        printc("**        [blue]%d [/blue]-> Mostrar hashing                  **\n", i++);
        printc("**        [blue]%d [/blue]-> Pesquisar elemento hashing       **\n", i++);
        printc("**************************************************\n");
        do{
            printf("Qual a opção que pretende? ");
            scanf("%d", &opcao);
        }while(opcao < 0 && opcao > 3);

        i = 1;
        if (opcao == i++){
            Elemento *novoElemento = criarElemento();
            ler_elemento(novoElemento);
            inserirElementoHashing(HashVetor, novoElemento);
        }
        if (opcao == i++){
            Elemento *novoElemento = criarElemento();
            ler_elemento_manual(novoElemento);
            removerElementoHashing(HashVetor, pesquisarElementoHashing(HashVetor, novoElemento));
        }
        if (opcao == i++){
            mostrarElementosHashing(HashVetor);
        }
        if (opcao == i++){
            Elemento *novoElemento = criarElemento();
            ler_elemento_manual(novoElemento);
            mostrarElemento(pesquisarElementoHashing(HashVetor, novoElemento));
        }
    } while (opcao != 0);
    return 0;
}