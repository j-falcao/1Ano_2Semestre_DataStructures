int menuPrincipal(){
    int opcao;
    do{
        int i = 0;
        printc("**************************************************\n");
        printc("****************   [blue]Menu Funcionário[/blue]  *************\n");
        printc("**************************************************\n");
        printc("**        [blue]%d [/blue]-> Voltar                           **\n", i++);
        printc("**        [blue]%d [/blue]-> Ver Todos Funcionários           **\n", i++);
        printc("**        [blue]%d [/blue]-> Ver Funcionários Inativos        **\n", i++);
        printc("**        [blue]%d [/blue]-> Ver Funcionários em Caixa        **\n", i++);
        printc("**        [blue]%d [/blue]-> Pesquisar Funcionários           **\n", i++);
        printc("**        [blue]%d [/blue]-> Adicionar Funcionário            **\n", i++);
        printc("**        [blue]%d [/blue]-> Editar Funcionário               **\n", i++);
        printc("**        [blue]%d [/blue]-> Remover Funcionário              **\n", i++);
        /* printc("**        [blue]%d [/blue]-> Trocar Funcionário da Caixa      **\n", i++);*/
        printc("**************************************************\n");
        scanfs("%d", &opcao, "Qual a opção que pretende? ", "Apenas pode inserir números inteiros!\n");

        i = 1;
        if (opcao == i++){
            verFuncionarios();
        }
        if (opcao == i++){
            verFuncionariosInativos();
        }
        if (opcao == i++){
            verFuncionariosCaixa();
        }
        if (opcao == i++){
            menuPesquisarFuncionarios();
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