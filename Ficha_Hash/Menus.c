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
        scanfs("%d", &opcao, "Qual a opção que pretende? ", "Apenas pode inserir números inteiros!\n");

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
        if (opcao == i++){
            adicionarFuncionario();
        }
        if (opcao == i++){
            editarFuncionarios();
        }
        if (opcao == i++){
            removerFuncionario();
        }
        /* if (opcao == i++){
            trocarFuncionario();
        }
        if (opcao == i++){
            alterarSalario();
        } */
    } while (opcao != 0);
}