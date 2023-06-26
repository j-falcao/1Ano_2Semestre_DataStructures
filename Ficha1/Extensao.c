#include "TipoDados_Extensao.h"

typedef struct{
    char nome[50];
    int count;
}NomeComum;


int GravarXML(REGISTO_UTILIZADORES *R, int N, char *ficheiro){

}

void ToLetrasGrandes(REGISTO_UTILIZADORES *R, int N){
    for(int i = 0; i < N; i++)
        strupr(R[i].nome);
}

char **SepararEspacos(char *s, int *tamanho){

    int flag = 0, flagAux = 0;

    char Num_Indiv_String[100];
  
    char** vetorStrings = (char**) malloc(sizeof(char*) * 10);
    *tamanho = 0;

    for(int i = 0; i < strlen(s); i++){

        if(s[i] == ' '){
          flagAux = 0;

          if(flag == 1 && flagAux == 0){
            Num_Indiv_String[strlen(Num_Indiv_String)] = '\0';
            vetorStrings[(*tamanho)-1] = malloc(1 + sizeof(char) * strlen(Num_Indiv_String));
            strcpy(vetorStrings[(*tamanho)-1], Num_Indiv_String);
          }
          flag = 0; 
        }

        else{
          flagAux = 1;

          if(flag == 0 && flagAux == 1){
            (*tamanho)++;
            strcpy(Num_Indiv_String, "");
          }
          flag = 1;

          char temp[2] = {s[i], '\0'};
          strcat(Num_Indiv_String, temp);

          if(i == strlen(s)-1){
            Num_Indiv_String[strlen(Num_Indiv_String)] = '\0';
            vetorStrings[(*tamanho)-1] = malloc(1 + sizeof(char) * strlen(Num_Indiv_String));
            strcpy(vetorStrings[(*tamanho)-1], Num_Indiv_String);
          }
        }
    }
    return vetorStrings;
}



int ListarUsersContain(REGISTO_UTILIZADORES *R, int N, char *subnome){
    int tamanho;
    char **VetorStr = (char**) malloc(sizeof(char*));
    for (int i = 0; i < N; i++){
        VetorStr = SepararEspacos(R[i].nome, &tamanho);
        for (int j = 0; j < tamanho; j++){
            if(strcasecmp(VetorStr[j], subnome) == 0){
                Listar_PessoaIndividual(R, i);
            }
        }  
    }   
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initList(head **V, int N){;
    for (int i = 0; i < N; i++){
        V[i] = (head*) malloc(sizeof(head));
        V[i]->inicio = NULL;
    }
}

int converte(char *s){
    int sum = 0; 
    for (int i = 0; s[i] != '\0'; i++){
        sum += s[i];
    }
    return sum % 20;
}

info* criarInfo(char *nome){
    info *I = (info*) malloc(sizeof(info));
    strcpy(I->nome, nome);
    I->n = 1;
    return I;
}

NO* criarNo(head **V, int index, char *nome){
    NO *Node = (NO*) malloc(sizeof(NO));
    Node->info = criarInfo(nome);
    Node->next = NULL;
    return Node;
}


void procura_adicao(head **V, int index, char* nome, char* max, int* maxint){

    NO *Aux = (NO*) malloc(sizeof(NO));
    NO* Caixinha = (NO*) malloc(sizeof(NO));
    int flag = 1;

    if(V[index]->inicio == NULL){
        V[index]->inicio = criarNo(V, index, nome);
        Aux = NULL;
        flag = 0;
    }

    if(flag == 1)
        Aux = V[index]->inicio;
    

    while(Aux){
        if(strcasecmp(Aux->info->nome, nome) == 0){
            Aux->info->n++;
            if(Aux->info->n > (*maxint)){
                *maxint = Aux->info->n;
                strcpy(max, nome);
            }
        return;
        }
        if(Aux->next == NULL){
            Caixinha = criarNo(V, index, nome);
            Aux->next = Caixinha;
            return;
        }
        Aux = Aux->next;    
    }
    free(Aux);
    free(Caixinha);
}

char* NomeMaisComum(REGISTO_UTILIZADORES *R, int N, head **V, int tamanhoVetorHead){
    
    char* max = (char*) malloc(sizeof(char)*25);
    int maxint = 0;
    char **VetorStr = (char**) malloc(sizeof(char*));
    int tamanhoPalavra;

    for (int i = 0; i < N; i++){
        VetorStr = SepararEspacos(R[i].nome, &tamanhoPalavra);
        for (int j = 0; j < tamanhoPalavra; j++){
            procura_adicao(V, converte(VetorStr[j]), VetorStr[j], max, &maxint);
        }
    }

    for (int i = 0; i < tamanhoPalavra; i++)
        free(VetorStr[i]);
    free(VetorStr);

    return max;
}   


void destruirlista_vetor(head **V, int N){

    NO *Aux = (NO*) malloc(sizeof(NO));
    NO *Aux2 = (NO*) malloc(sizeof(NO));

    for (int i = 0; i < N; i++){
        Aux = V[i]->inicio;

        while(Aux){
            Aux2 = Aux->next;

            free(Aux->info);
            free(Aux);

            Aux = Aux2;
        }
    }
    free(Aux);
    free(Aux2);
    for (int i = 0; i < N; i++)
        free(V[i]);
    free(V);
}

void performance_csv(REGISTO_UTILIZADORES *R, int N, head **V, int tamanhoVetorHead){

    clock_t start, finish;

    start = clock();
    //gravarXML
    finish = clock();

    initList(V, tamanhoVetorHead);
    start = clock();
    NomeMaisComum(R, N, V, tamanhoVetorHead);
    finish = clock();
    destruirlista_vetor(V, tamanhoVetorHead);
    double tempo3 = (double)(finish-start)/CLK_TCK;

    start = clock();
    ListarUsersContain(R, N, "Joao");
    finish = clock();
    double tempo2 = (double)(finish-start)/CLK_TCK;

    start = clock();
    ToLetrasGrandes(R, N);
    finish = clock();
    double tempo1 = (double)(finish-start)/CLK_TCK;

    //Gravar em csv
    FILE *f = fopen("Performance.csv", "w");

    if(!f){
        printf("Erro ao abrir ficheiro csv");
        return;
    }
    
    fprintf(f, "ToLetrasGrandes; %f ms", tempo1);
    fprintf(f, "ListarUsersContain; %f ms", tempo2);
    fprintf(f, "NomeMaisComum; %f ms", tempo2);
    
    fclose(f);
}