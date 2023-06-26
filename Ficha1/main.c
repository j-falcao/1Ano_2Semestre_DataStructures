#include "TipoDados.h"
#include "TipoDados_Extensao.h"

extern int Aleatorio(int min, int max);

int main(){ 
    srand(time(NULL));
    char nomeficheiro[20] = "Ficha1/Ficheiro.dat", nometemp[50];
    int nReg, ano;
    REGISTO_UTILIZADORES *R = (REGISTO_UTILIZADORES*) malloc(sizeof(REGISTO_UTILIZADORES));
    int opcao;    

    head **V = (head**) malloc(sizeof(head*)*20);
    int tamanhoVetorHead = 20;

    /* char **Str = (char**) malloc(sizeof(char*)); //Para printar / testar funcao separarespacos
    int t = 14; */



    do{
        /* fputs("\x1b[H\x1b[2J\x1b[3J", stdout); */
        printf("**********************************\n");
        printf("*********** Menu Files ***********\n");
        printf("**********************************\n");
        printf("**     0 -> Gerar dados         **\n");
        printf("**     1 -> Importar dados      **\n");
        printf("**     2 -> Ordenar dados       **\n");
        printf("**     3 -> Listar dados        **\n");
        printf("**     4 -> Pesquisar pessoa    **\n");
        printf("**  5 -> Cont ult. acesso ano   **\n");
        printf("**     6 -> Performance         **\n");
        printf("**     7 -> Pessoa + acessos    **\n");
        printf("**     8 -> Total joias         **\n");
        printf("**    9 -> Mes com + acessos    **\n");
        printf("**     =====EX_EXTENSAO=====    **\n");
        printf("**    10 -> Gravar XML          **\n");
        printf("**    11 -> List. User Contain  **\n");
        printf("**  12 -> Exportar Performance  **\n");
        printf("**     13 -> Nome mais comum    **\n");
        printf("**     14 -> Sair               **\n");
        printf("**********************************\n");
        printf("\nOpcao: ");
        printf("\n");
        scanf("%d", &opcao);
    switch (opcao){
      case 0:
            printf("Quantos utilizadores pretende criar?wdwfef ");
            scanf("%d", &nReg);
            R = GerarFicheiro_So_Para_Testes(nReg, nomeficheiro);
        opcao = 0;
        break;

      case 1:
            R = LerFicheiro(&nReg, nomeficheiro);
        opcao = 0;
        break;

      case 2:
            Menu_Ordenar(R, nReg);
        opcao = 0;
        break;

        case 3:
              ListarUtilizadores(R, nReg);
        opcao = 0;
        break;

      case 4:
            Menu_Pesquisar(R, nReg);
        opcao = 0;
        break;

      case 5:
            printf("Insira o ano a contar: ");
            scanf("%d", &ano);
            ContarPessoasAcessoAno(R, nReg, ano);
        opcao = 0;
        break;

      case 6:
            Performance(R, nReg);
        opcao = 0;
        break;

      case 7:
            PessoaMais_Acessos(R, nReg);
        opcao = 0;
        break;

      case 8:
            TotalJoias(R, nReg);
        opcao = 0;
        break;

        case 9:
            printf("\nMes com mais acessos: %d\n", MesMaisRegistos_MinhaForma(R, nReg));
        opcao = 0;
        break;

        case 10:
            if(GravarXML)
              printf("Ficheiro guardado com sucesso!\n");
            else
              printf("Ocorreu um erro ao guardar em XML...\n");
        opcao = 0;
        break;

        case 11:    
            printf("insira o nome que procura: ");
            scanf("%s", nometemp);
            ListarUsersContain(R, nReg, nometemp);
        opcao = 0;
        break;

        case 12:
              performance_csv(R, nReg, V, tamanhoVetorHead);
              printf("ola");
        opcao = 0;
        break;

        case 13:   
              initList(V, tamanhoVetorHead);
              printf("Nome mais comum: %s\n\n", NomeMaisComum(R, nReg, V, tamanhoVetorHead));
              destruirlista_vetor(V, tamanhoVetorHead);
              opcao = 0;
        break;

        case 14:
            Menu_Sair(R, nReg, nomeficheiro);
        break;

      default:
        printf("Opcao invalida!\n");
        opcao = 0;
        break;
    }
    }while (opcao == 0);
}

  


