#include "Menus.h"

void Menu_Sair(Lista* L, char *nomeficheiro){
    char guardar;
    printf("Deseja guardar as alteracoes feitas (s/n)?");
    scanf(" %c", &guardar);
    if(guardar == 'n' || guardar == 'N')
        printf("Programa Encerrado");
    else{
        printf("A guardar alteracoes...");
        exportar_ficheiro(L, nomeficheiro);
        printf("Programa Encerrado");
    }

        
    Limpar_Fila_Libertar();
    destruirLista(L);
}

void menu_exportar_importar(Lista* L, char* nomeficheiro){
    int opcao;
    do{
        /* fputs("\x1b[H\x1b[2J\x1b[3J", stdout); */
        printf("************************************************\n");
        printf("***************** Menu Mostrar *****************\n");
        printf("************************************************\n");
        printf("**           1 -> Exportar para txt           **\n");
        printf("**           2 -> Importar                    **\n");
        printf("**        0 -> Voltar ao menu principal       **\n");
        printf("************************************************\n");
        printf("\nOpcao: ");
        printf("\n");
        scanf("%d", &opcao);
    switch (opcao){
      case 1:
        exportar_ficheiro(L, nomeficheiro);
        opcao = 0;
        break;

      case 2:
        importar_ficheiro(L, nomeficheiro);
        opcao = 0;
        break;

      case 0: 
        opcao = 1;
        break;
    }
    }while (opcao == 0);   
}

void menu_mostrar(Lista* L){
    int opcao;
    do{
        /* fputs("\x1b[H\x1b[2J\x1b[3J", stdout); */
        printf("************************************************\n");
        printf("***************** Menu Mostrar *****************\n");
        printf("************************************************\n");
        printf("**           1 -> Mostrar Ordem Atual         **\n");
        printf("**           2 -> Motrar Ordem Inversa        **\n");
        printf("**        0 -> Voltar ao menu principal       **\n");
        printf("************************************************\n");
        printf("\nOpcao: ");
        printf("\n");
        scanf("%d", &opcao);
    switch (opcao){
      case 1:
        mostrar_lista(L);
        opcao = 0;
        break;

      case 2:
        mostrar_inversa_v2(L);
        opcao = 0;
        break;

      case 0: 
        opcao = 1;
        break;
    }
    }while (opcao == 0);   
}

void menu_inserir(Lista* L, Elemento* Aux){
    int opcao;
    do{
        /* fputs("\x1b[H\x1b[2J\x1b[3J", stdout); */
        printf("************************************************\n");
        printf("**************** Menu Principal ****************\n");
        printf("************************************************\n");
        printf("**           1 -> Inserir no inicio           **\n");
        printf("**           2 -> Inserir no fim              **\n");
        printf("**           3 -> Inserir ordenado            **\n");
        printf("**        0 -> Voltar ao menu principal       **\n");
        printf("***********************************************\n");
        printf("\nOpcao: ");
        printf("\n");
        scanf("%d", &opcao);
    switch (opcao){
      case 1:
        inserir_elemento_inicio(L, Aux);
        break;

      case 2:
        inserir_elemento_fim(L, Aux);
        break;

      case 3:
        inserir_elemento_ordenado(L, Aux);
        break;


      case 0: 
        opcao = 1;
        break;
    }
    }while (opcao == 0);   
}

void menu_retirar(Lista* L, Elemento* Aux){
    int opcao;
    do{
        /* fputs("\x1b[H\x1b[2J\x1b[3J", stdout); */
        printf("************************************************\n");
        printf("**************** Menu Principal ****************\n");
        printf("************************************************\n");
        printf("**           1 -> Retirar do inicio           **\n");
        printf("**           2 -> Retirar do fim              **\n");
        printf("**       3 -> Retirar elemento a escolha      **\n");
        printf("**       0 -> Voltar ao menu principal        **\n");
        printf("************************************************\n");
        printf("\nOpcao: ");
        printf("\n");
        scanf("%d", &opcao);
    switch (opcao){
      case 1:
        remover_primeiro(L);
        opcao = 0;
        break;

      case 2:
        remover_ultimo(L);
        opcao = 0;
        break;

        case 3:
        Aux = criarElemento();
        LerElemento(Aux);
        if(!remover_elemento(L, Aux))
            printf("O elemento nao foi encontrado");
        else
            printf("Elemento retirado com sucesso");
        opcao = 0;
        break;

      case 0: 
        opcao = 1;
        break;
    }
    }while (opcao == 0);   
}


void menu_principal(Lista* L, char* nomeficheiro){
    Elemento* Aux = criarElemento();

    int opcao;
    do{
        /* fputs("\x1b[H\x1b[2J\x1b[3J", stdout); */
        printf("**********************************************\n");
        printf("**************** Menu Principal **************\n");
        printf("**********************************************\n");
        printf("**     1 -> Inserir elementos               **\n");
        printf("**     2 -> Retirar elementos               **\n");
        printf("**     3 -> Ordenar elementos               **\n");
        printf("**     4 -> Mostrar os elementos            **\n");
        printf("**     5 -> Mostrar o numero de elementos   **\n");
        printf("**     6 -> Pesquisar elemento              **\n");
        printf("**     7 -> Verificar se existem repetidos  **\n");
        printf("**     8 -> Exportar/Importar               **\n");
        printf("**     0 -> Sair                            **\n");
        printf("**********************************************\n");
        printf("\nOpcao: ");
        printf("\n");
        scanf("%d", &opcao);
    switch (opcao){
      case 1:
        Aux = criarElemento();
        LerElemento(Aux);
        menu_inserir(L, Aux);
        opcao = 0;
        break;

      case 2:
        menu_retirar(L, Aux);
        opcao = 0;
        break;

      case 3:
        ordenar_lista_v2(L);
        opcao = 0;
        break;

      case 4:
        menu_mostrar(L);
        opcao = 0;
        break;

      case 5:
        printf("Numero de elementos: %d\n", L->n_el);
        opcao = 0;
        break;

      case 6:
        Aux = criarElemento();
        LerElemento(Aux);
        Aux = pesquisar_recursivo(L, Aux);
        if(!Aux)
            printf("\nO elemento nao foi encontrado\n\n");
        else
            mostrar_elemento(Aux);
        opcao = 0;
        break;

      case 7:
        if(elementos_repetidos(L))
          printf("Sim, existem elementos repetidos!\n");
        else
          printf("Nao existem elementos repetidos!\n");
        opcao = 0;
        break;

      case 8:
        menu_exportar_importar(L, nomeficheiro);
        opcao = 0;
        break;
      
      case 0:
        Menu_Sair(L, nomeficheiro);
        opcao = 1;
        break;

      default:
        printf("Opcao invalida!\n");
        opcao = 0;
        break;
    }
    }while (opcao == 0);

}