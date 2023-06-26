#include "TipoDados.h"

extern int Aleatorio(int min, int max);

DATA DataValidaAleatoria(DATA data, int min, int max){

    data.ano = Aleatorio(min, max);
    data.mes = Aleatorio(1, 12);

    if(data.mes % 2 != 0 && data.mes < 8 || data.mes >= 8 && data.mes % 2 == 0)
        data.dia = Aleatorio(1, 31);
    else if(data.mes % 2 == 0 && data.mes <= 8 && data.mes != 2 || data.mes > 8 && data.mes % 2 != 0)
        data.dia = Aleatorio(1, 30);
    else if(data.mes == 2 && data.ano % 4 == 0)
        data.dia = Aleatorio(1, 29);
    else if(data.mes == 2 && data.ano % 4 != 0)
        data.dia = Aleatorio(1, 28);
    
    return data;
}

int DataAntes_Depois(DATA d1, DATA d2){
    if(d2.ano > d1.ano || 
        (d2.ano == d1.ano && 
        d2.mes > d1.mes) || 
        (d2.ano == d1.ano && 
        d2.mes == d1.mes && 
        d2.dia >=  d1.dia))
        return 1;
    else
        return 0;
}

REGISTO_UTILIZADORES *GerarFicheiro_So_Para_Testes(int nReg, char *nomeficheiro){

    int flag;

    printf("ola");
    char nome[][20] = {"Miguel", "Sophia", "Davi", "Alice", "Arthur", "Julia", "Pedro", "Isabella", "Gabriel", "Manuela","Bernardo",    "Laura", "Lucas", "Luiza", "Matheus", "Valentina", "Rafael", "Giovanna", "Heitor", "Maria Eduarda","Enzo", "Helena", "Guilherme",  "Beatriz", "Nicolas", "Maria Luiza", "Lorenzo", "Lara", "Gustavo", "Mariana","Felipe", "Nicole", "Samuel", "Rafaela", "João Pedro",  "Heloísa", "Daniel", "Isadora", "Vitor", "Lívia","Leonardo", "Maria Clara", "Henrique", "Ana Clara", "Theo", "Lorena", "Murilo",     "Gabriela", "Eduardo", "Yasmin","Pedro Henrique", "Isabelly", "Pietro", "Sarah", "Cauã", "Ana Julia", "Isaac", "Letícia", "Caio", "Ana  Luiza","Vinicius", "Melissa", "Benjamin", "Marina", "João", "Clara", "Lucca", "Cecília", "João Miguel", "Esther","Bryan", "Emanuelly",   "Joaquim", "Rebeca", "João Vitor", "Ana Beatriz", "Thiago", "Lavínia", "Antônio", "Vitória","Davi Lucas", "Bianca", "Francisco",  "Catarina", "Enzo Gabriel", "Larissa", "Bruno", "Maria Fernanda", "Emanuel", "Fernanda","João Gabriel", "Amanda", "Ian", "Alícia",   "Davi Luiz", "Carolina", "Rodrigo", "Agatha", "Otávio", "Gabrielly"};
    
    REGISTO_UTILIZADORES *R = (REGISTO_UTILIZADORES*) malloc(sizeof(REGISTO_UTILIZADORES) * nReg);

    FILE *f = fopen("teste.txt", "w");

    for(int i = 0; i < nReg; i++){
        int ale = Aleatorio(0, 49);
        int ale1 = Aleatorio(0, 49);
        


        R[i].nome = (char*) malloc(sizeof(char) * 50);
        sprintf(R[i].nome, "%s %s", nome[ale], nome[ale1]);
/*         R[i].nome = realloc(R[i].nome, sizeof(char) * (strlen(R[i].nome) + 1)); */
        fprintf(f, "%s;", R[i].nome);

        R[i].utilizador = (char*) malloc(sizeof(char) * 30);
        sprintf(R[i].utilizador, "Utilizador-%d", i+1);
        R[i].utilizador = realloc(R[i].utilizador, sizeof(char) * (strlen(R[i].utilizador) + 1));

        R[i].password = (char*) malloc(sizeof(char) * 30);
        sprintf(R[i].password, "Password-%d", i+1);
        R[i].password = realloc(R[i].password, sizeof(char) * (strlen(R[i].password) + 1));

        R[i].email = (char*) malloc(sizeof(char) * 30);
        sprintf(R[i].email, "email-%d@gmail.com", i+1);
        R[i].email = realloc(R[i].email, sizeof(char) * (strlen(R[i].email) + 1));

        R[i].pagina_web_pessoal = (char*) malloc(sizeof(char) * 30);
        sprintf(R[i].pagina_web_pessoal, "pagina_web_pessoal-%d.pt", i+1);
        R[i].pagina_web_pessoal = realloc(R[i].pagina_web_pessoal, sizeof(char) * (strlen(R[i].pagina_web_pessoal) + 1));
        
        R[i].joia = Aleatorio(0, 5)/100.0;

        R[i].data_registo = DataValidaAleatoria(R[i].data_registo, 1990, 2022);

        R[i].telemovel = Aleatorio(90000000, 999999999);

        R[i].numero_acessos = Aleatorio(1, 5000);

        R[i].id = i+1;

        do{
            flag = 0;
            R[i].data_ultimo_acesso = DataValidaAleatoria(R[i].data_ultimo_acesso, 1990, 2022);
            if(DataAntes_Depois(R[i].data_registo, R[i].data_ultimo_acesso) == 1)
                flag = 1;
        }while(flag == 0);
    }
    GuardarFicheiro(R, nReg, nomeficheiro);
    fclose(f);


    return R;
}



//|////|////|////|////|////|////|////|////|////|////|////|fUNÇÕES PARA OS MENUS|////|////|////|////|////|////|////|////|////|////|////|////|////|//



void Menu_Sair(REGISTO_UTILIZADORES *R, int nReg, char *nomeficheiro){
    char guardar;
    printf("Deseja guardar as alteracoes feitas (s/n)?");
    scanf(" %c", &guardar);
    if(guardar == 'n' || guardar == 'N')
        printf("Programa Encerrado");
    else{
        printf("A guardar alteracoes...");
        GuardarFicheiro(R, nReg, nomeficheiro);
        printf("Programa Encerrado");
    }
        
    LibertarMemoria(R);
}


void Menu_Ordenar(REGISTO_UTILIZADORES *R, int nReg){
    char escolha;
    printf("Ordenar por data de regitsto, data de ultimo acesso ou ID? (0 --> Registo(Bubble) | 1--> Ultimo acesso(Selection) | 2 --> ID(QuickSort))" );
    scanf("%d", &escolha);

    if(escolha == 0)
        OrdenarDataRegisto_BubbleSort(R, nReg);
    else if(escolha == 1)
        OrdenarDataRegisto_SelectionSort_data_ultimo_acesso(R, nReg);
    else
        OrdenarID_QuickSort(R, nReg);
}

void Menu_Pesquisar(REGISTO_UTILIZADORES *R, int nReg){
    char escolha;
    printf("Deseja pesquisar o que pelo nome (linear search) ou pelo id (binary search)? (0 --> linear | 1--> binary)" );
    scanf("%d", &escolha);

    if(escolha == 0)
        PesquisarPessoaNome_LinearSearch(R, nReg);
    else 
        OrdenarDataRegisto_SelectionSort_data_ultimo_acesso(R, nReg);
}

void ListarUtilizadores(REGISTO_UTILIZADORES *R, int nReg){
    for(int i = 0; i < nReg; i++){
        printf("\n\nNome: %s\n", R[i].nome);
        printf("Utilizador: %s\n", R[i].utilizador);
        printf("Password: %s\n", R[i].password);
        printf("Email: %s\n", R[i].email);
        printf("Pagina web pessoal: %s\n", R[i].pagina_web_pessoal);
        printf("Telemovel: %d\n", R[i].telemovel);
        printf("Id: %d\n", R[i].id);
        printf("Joia: %.3f\n", R[i].joia);
        printf("Numero de acessos: %d\n", R[i].numero_acessos);
        printf("Data de registo: %d/%d/%d\n", R[i].data_registo.dia, R[i].data_registo.mes, R[i].data_registo.ano);
        printf("Data de ultimo acesso: %d/%d/%d\n", R[i].data_ultimo_acesso.dia, R[i].data_ultimo_acesso.mes, R[i].data_ultimo_acesso.ano);
        printf("\n");
        if(i != nReg-1)
        printf("-------------------------------------------------\n\n");
    }
    
}

void Performance(REGISTO_UTILIZADORES *R, int nReg){

    int escolha;
    printf("Quer comparar performance em pesquisa ou ordenacao? (0 --> Ordenacao | 1 --> Pesquisa | 2 --> MesMais) ");
    scanf("%d", &escolha);

    clock_t inicio, fim;

    if(escolha == 0){
        BubbleSort_data_registo(R, nReg, 1); // 1 serve para indicar que e descendente
        inicio = clock();
        BubbleSort_data_registo(R, nReg, 0);
        fim = clock();
        printf("Ordenar em Bubble sort demorou: %f segundos\n", (double)(fim-inicio)/CLK_TCK);
        SelectionSort_data_ultimo_acesso(R, nReg, 1);
        inicio = clock();
        SelectionSort_data_ultimo_acesso(R, nReg, 0);
        fim = clock();
        printf("Ordenar em Seleciton sort demorou: %f segundos\n\n", (double)(fim-inicio)/CLK_TCK);
    }

    if(escolha == 1){
        BubbleSort_data_registo(R, nReg, 0);
        inicio = clock();
        LinearSearch_Nome(R, nReg, "Nome-57");
        fim = clock();
        printf("Pesquisar em linear search demorou: %f segundos\n", (double)(fim-inicio)/CLK_TCK);
        inicio = clock();
        BinarySearch_Id(R, 57, 0, nReg);
        fim = clock();
        printf("Ordenar em Bubble sort demorou: %f segundos\n\n", (double)(fim-inicio)/CLK_TCK);
    }

    if (escolha == 2)
    {
        inicio = clock();
        MesMaisRegistos_MinhaForma(R, nReg);
        fim = clock();
        printf("Minha forma demorou: %f segundos\n", (double)(fim-inicio)/CLK_TCK);

        inicio = clock();
        MesMaisRegistos_FormaPedro(R, nReg);
        fim = clock();
        printf("A forma do Pedro demorou: %f segundos\n", (double)(fim-inicio)/CLK_TCK);
    }
    
}

void Listar_PessoaIndividual(REGISTO_UTILIZADORES *R, int index){
    printf("\n\nNome: %s\n", R[index].nome);
    printf("Utilizador: %s\n", R[index].utilizador);
    printf("Password: %s\n", R[index].password);
    printf("Email: %s\n", R[index].email);
    printf("Pagina web pessoal: %s\n", R[index].pagina_web_pessoal);
    printf("Telemovel: %d\n", R[index].telemovel);
    printf("Id: %d\n", R[index].id);
    printf("Joia: %f\n", R[index].joia);
    printf("Numero de acessos: %d\n", R[index].numero_acessos);
    printf("Data de registo: %d/%d/%d\n", R[index].data_registo.dia, R[index].data_registo.mes, R[index].data_registo.ano);
    printf("Data de ultimo acesso: %d/%d/%d\n", R[index].data_ultimo_acesso.dia, R[index].data_ultimo_acesso.mes, R[index].data_ultimo_acesso.ano);
    printf("\n");
}

