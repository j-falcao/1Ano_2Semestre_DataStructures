#include "Menu.h"

/* int menuPrincipal(Tree* T){
    int opcao;
    do{
        int i = 1;
        printc("**************************************************\n");
        printc("***************   [blue]Menu Funcionario[/blue]  *************\n");
        printc("**************************************************\n");
        printc("**        [blue]%d [/blue]-> Inserir elemento hashing         **\n", i++);
        printc("**        [blue]%d [/blue]-> Remover elemento hashing         **\n", i++);
        printc("**        [blue]%d [/blue]-> Mostrar hashing                  **\n", i++);
        printc("**        [blue]%d [/blue]-> Pesquisar elemento hashing       **\n", i++);
        printc("**************************************************\n");
        do{
            printf("Qual a opcao que pretende? ");
            scanf("%d", &opcao);
        }while(opcao < 1 || opcao > 4);

        i = 1;
        if (opcao == i++){
            Elemento *novoElemento = criarElemento();
            lerElemento(novoElemento);
            inserirElementoHashing(HashVetor, novoElemento);
        }
        if (opcao == i++){
            Elemento *novoElemento = criarElemento();
            lerElementoManualNomeIdade(novoElemento);
            libertarElemento(removerElementoHashing(HashVetor, pesquisarElementoHashing(HashVetor, novoElemento)));
        }
        if (opcao == i++){
            mostrarElementosHashing(HashVetor);
        }
        if (opcao == i++){
            Elemento *novoElemento = criarElemento();
            lerElementoManualNomeIdade(novoElemento);
            mostrarElemento(pesquisarElementoHashing(HashVetor, novoElemento));
        }
    } while (opcao != 0);
    return 0;
} */