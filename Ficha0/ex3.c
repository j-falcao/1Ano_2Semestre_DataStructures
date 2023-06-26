#include "TiposDados.h"

extern int Aleatorio(int min, int max);

void CarregarDadosAlunos(Aluno *A, int n){
    for (int i = 0; i < n; i++){
        sprintf(A[i].nome, "Aluno-%d", i+1);
        A[i].numMec = Aleatorio(18000, 28000);
        A[i].media = 0.0;
        for (int j = 0; j < 5; j++)
        {
            sprintf(A[i].UCs[j].nome,"UC-%d", j+1);
            A[i].UCs[j].avaliacao = Aleatorio(0, 20);
            A[i].media += A[i].UCs[j].avaliacao;
        }
        A[i].media /= 5;
    }
}

void MostrarAlunos(Aluno *A, int n){
    for (int i = 0; i < n; i++){
        printf("Nome: %s\n", A[i].nome);
        printf("Numero Mecanografico: %d\n", A[i].numMec);
        printf("UCs:\n");
        for (int j = 0; j < 5; j++){
            printf("\t%s: %d\n", A[i].UCs[j].nome, A[i].UCs[j].avaliacao);
        }
        printf("Media: %.2f\n", A[i].media);
        printf("--------------------------\n");
    }
}

int qtosPassam(Aluno *A, int n){
    int countPassam = 0;
    for (int i = 0; i < n; i++){
        if(A[i].media >= 10)
        countPassam++;
    }
    return countPassam;
}

float mediaUCsInfLim(Aluno *A, int n, int lim){
    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 5; j++){
            if(A[i].UCs[j].avaliacao < lim)
            count++;
        }
    }
    return (float)count/n;
}


void GuardarDadosAlunos(Aluno *A, int n, int val, char *nomeFich){
    int flag = 0;
    FILE* f = fopen(nomeFich, "w");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 5; j++){
            if(A[i].UCs[j].avaliacao >= val){
                if(flag == 0){
                    size_t LenNome = strlen(A[i].nome) + 1;
                    fprintf(f, "%d\n", LenNome);
                    fprintf(f, "Nome: %s\n", A[i].nome);
                    fprintf(f, "Numero Mecanografico: %d\n", A[i].numMec);
                    flag++;
                }
                size_t LenNome = strlen(A[i].UCs[j].nome) + 1;
                fprintf(f, "%d\n", LenNome);
                fprintf(f, "Nome UC: %s\n", A[i].UCs[j].nome);
                fprintf(f, "Nota: %d\n", A[i].UCs[j].avaliacao);
            }
            
        }
        if(flag != 0)
            fprintf(f, "--------------------\n");
        flag = 0;
        
    }
    
}

/* int main(){
    srand(time(NULL));

    int nReg;
    printf("Quantos alunos pretende criar? ");
    scanf("%d", &nReg);
    Aluno ListAlun[nReg];

    CarregarDadosAlunos(ListAlun, nReg);
    MostrarAlunos(ListAlun, nReg);

    int QtosPassam = qtosPassam(ListAlun, nReg); 
    printf("Passaram %d alunos.\n", QtosPassam);

    int lim = Aleatorio(0, 20);
    float MediaUCsInf = mediaUCsInfLim(ListAlun, nReg, lim);
    printf("Media de UCs com notas inferiores a %d: %.2f\n", lim, MediaUCsInf);

    char nomeFich[26] = "Ficha0/BonsAlunos_ex3.txt";
    int val = Aleatorio(15, 20);
    GuardarDadosAlunos(ListAlun, nReg, val, nomeFich);
} */