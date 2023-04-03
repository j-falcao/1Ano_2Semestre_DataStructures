#include "TipoDados.h"

extern int Aleatorio(int min, int max);

int ContarPessoasAcessoAno(REGISTO_UTILIZADORES *R, int nReg, int ano){
    int count = 0;
    for (int i = 0; i < nReg; i++){
        if(R[i].data_ultimo_acesso.ano == ano)
            count++;
    }
    return count;
}


int LinearSearch_Nome(REGISTO_UTILIZADORES *R, int nReg, char *nomeTemp){
    for (int i = 0; i < nReg; i++){
        if(strcmp(R[i].nome, nomeTemp) == 0)
            return i;
    }
    return -1;
    
}


void PesquisarPessoaNome_LinearSearch(REGISTO_UTILIZADORES *R, int nReg){
    int flag;
    do{

    for (int i = 0; i < nReg; i++)
        printf("%s\n", R[i].nome);

    char nomeTemp[50]; 
    int repetir;
    printf("Insira o nome da pessoa que procura: ");
    scanf("%s", nomeTemp);

    int i = LinearSearch_Nome(R, nReg, nomeTemp);

    if(i == -1){
        printf("Nome nao encontrado...\nQuer tentar novamente? (1 --> sim |0 --> nao)");
        scanf("%d", &repetir);
        if(repetir == 0)
            flag = 1;
    }
    else
        printf("\n\nNome: %s\n", R[i].nome);
        printf("Utilizador: %s\n", R[i].utilizador);
        printf("Password: %s\n", R[i].password);
        printf("Email: %s\n", R[i].email);
        printf("Pagina web pessoal: %s\n", R[i].pagina_web_pessoal);
        printf("Telemovel: %d\n", R[i].telemovel);
        printf("Id: %d\n", R[i].id);
        printf("Joia: %f\n", R[i].joia);
        printf("Numero de acessos: %d\n", R[i].numero_acessos);
        printf("Data de registo: %d/%d/%d\n", R[i].data_registo.dia, R[i].data_registo.mes, R[i].data_registo.ano);
        printf("Data de ultimo acesso: %d/%d/%d\n", R[i].data_ultimo_acesso.dia, R[i].data_ultimo_acesso.mes, R[i].data_ultimo_acesso.ano);
        printf("\n");

    }while(flag == 0);
}


int BinarySearch_Id(REGISTO_UTILIZADORES *R, int Id_search, int l, int r){

    int mid = l + (r - l) / 2;

    if(l > r)
        return -1;

    if(R[mid].id == Id_search)
        return mid;
    else if(R[mid].id < Id_search)
        return BinarySearch_Id(R, Id_search, mid+1, r);
    else
        return BinarySearch_Id(R, Id_search, l, mid-1);
}


void PesquisarPessoaId_BinarySearch(REGISTO_UTILIZADORES *R, int nReg){
    // falta ordenar (ShellSort)
    int flag;
    do{

    for (int i = 0; i < nReg; i++)
        printf("Id: %d\n", R[i].id);

    int Id_search, repetir;
    printf("Insira o Id da pessoa que procura: ");
    scanf("%d", &Id_search);

    int index = BinarySearch_Id(R, Id_search, 0, nReg);

    if(index == -1){
        printf("Nome nao encontrado...\nQuer tentar novamente? (1 --> sim |0 --> nao)");
        scanf("%d", &repetir);
        if(repetir == 0)
            flag = 1;
    }
    else
        Listar_PessoaIndividual(R, index);

    }while(flag == 0);
}

int PessoaMais_Acessos(REGISTO_UTILIZADORES *R, int nReg){
    int max = 0;
    for (int i = 0; i < nReg; i++){
        if(R[i].numero_acessos > R[max].numero_acessos)
            max = i;
    }
    printf("\nPessoa com mais acessos:\n");
    Listar_PessoaIndividual(R, max);
    return max;
}


float TotalJoias(REGISTO_UTILIZADORES *R, int nReg){
    float total = 0.0;
    for (int i = 0; i < nReg; i++)
        total += R[i].joia;
    return total;
}

int MesMaisRegistos_MinhaForma(REGISTO_UTILIZADORES *R, int nReg){
    int *Meses = (int*) malloc(sizeof(int)*12);
    for (int i = 0; i < 12; i++)
        Meses[i] = 0;
    
    for (int i = 0; i < nReg; i++)
        Meses[R[i].data_registo.mes-1]++;

    int max = Meses[0];
    for (int i = 1; i < 12; i++){
        if(Meses[i] > max)
        max = Meses[i];
    }
    free(Meses);
    return max+1;
}

int MesMaisRegistos_FormaPedro(REGISTO_UTILIZADORES *R, int nReg){

int mes = 0, count = 0, max = 0, pos = 0;
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < nReg; j++){
            if(R[j].data_registo.mes == i+1){
                count++;
            }
        }
        if(count > max){
            max = count;
            pos = i;
        }
        count = 0;
    }
    return pos+1;
}