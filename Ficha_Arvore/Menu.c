#include "Menu.h"

int menuPrincipal(Tree* T){
    int opcao;
    do{
        int i = 1;
        printc("************************************************************************************\n");
        printc("*********************************   [blue]Menu Funcionario[/blue]  ******************************\n");
        printc("************************************************************************************\n");
        printc("**                [blue]%d [/blue]-> Inserir NO arvore                                          **\n", i++);
        printc("**                [blue]%d [/blue]-> Pesquisar NO da arvore (por uma idade)                     **\n", i++);
        printc("**                [blue]%d [/blue]-> Mostrar arvore inOrder                                     **\n", i++);
        printc("**                [blue]%d [/blue]-> Mostrar arvore PreOrder                                    **\n", i++);
        printc("**                [blue]%d [/blue]-> Mostrar arvore PostOrder                                   **\n", i++);
        printc("**                [blue]%d [/blue]-> Remover no arvore (por uma idade)                          **\n", i++);
        printc("**                [blue]%d [/blue]-> Mostrar o numero total de nos da arvore                    **\n", i++);
        printc("**                [blue]%d [/blue]-> Mostrar o numero de nos na arvore minAge                   **\n", i++);
        printc("**                [blue]%d [/blue]-> Mostrar o numero de nos na arvore MaxWeight                **\n", i++);
        printc("**                [blue]%d [/blue]-> Mostrar a altura da arvore                                **\n", i++);
        printc("**                [blue]0  [/blue]-> Sair                                                      **\n ", 0);
        printc("***********************************************************************************\n");
        do{
            printf("Qual a opcao que pretende? ");
            scanf("%d", &opcao);
        }while(opcao < 0 || opcao > 10);

        i = 0;
        if(opcao == i++){
            CleanTree(T);
            printc("\n\t[green]Arvore limpa![/green]\n");
            i = 0;
        }
        if (opcao == i++){
            Node *newNode = createNode();
            WriteToNode(newNode);
            insertNode_version1(T, newNode);
        }
        if (opcao == i++){
            int age;
            printf("\nDigite a idade que deseja pesquisar:\n");
            scanf("%d", &age);
            printNode(searchByAge(T, age));
        }
        if (opcao == i++){
            printInOrder(T->root);
        }
        if (opcao == i++){
            printPreOrder(T->root);
        }
        if (opcao == i++){
            printPostOrder(T->root);
        }
        if (opcao == i++){
            int age;
            printf("\nDigite a idade que deseja apagar:\n");
            scanf("%d", &age);
            Node* RemovingNode = searchByAge(T, age);
            removeNodeByAge(T, RemovingNode);
            printc("\n[green]No removido com sucesso![/green]\n");
        }
        if (opcao == i++){
            printc("\n\tA arvore tem um total de [green]%d[/green] NOS\n", countNodes(T));
        }
        if (opcao == i++){
            int age;
            printf("\nDigite a idade maxima que vai limitar a contagem:\n");
            scanf("%d", &age);
            printNode(searchByAge(T, age));
            printc("\n\tA arvore tem um total de [green]%d[/green] NOS com mais de [green]%d[/green] anos\n", countNodeAgeGreaterThan(T, age), age);
        }
        if (opcao == i++){
            float weight;
            printf("\nDigite a idade maxima que vai limitar a contagem:\n");
            scanf("%f", &weight);
            printNode(searchByAge(T, weight));
            printc("\n\tA arvore tem um total de [green]%d[/green] NOS com mais de [green]%.2f[/green] anos\n", countNodeWeightLessThan(T, weight), weight);
        }
        if (opcao == i++){
            printc("\n\tA arvore tem altura [green]%d[/green]\n", HeightTree(T));
        }
    } while (opcao != 0);
    return 0;
}