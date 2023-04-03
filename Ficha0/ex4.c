#include "TiposDados.h"

extern int Aleatorio(int min, int max);

Data DataValidaAleatoria(Data data, int min, int max){

    data.ano = Aleatorio(min, max);
    data.mes = Aleatorio(0, 12);

    if(data.mes % 2 != 0 && data.mes < 8 || data.mes >= 8 && data.mes % 2 == 0)
        data.dia = Aleatorio(0, 31);
    else if(data.mes % 2 == 0 && data.mes <= 8 && data.mes != 2 || data.mes > 8 && data.mes % 2 != 0)
        data.dia = Aleatorio(0, 30);
    else if(data.mes == 2 && data.ano % 4 == 0)
        data.dia = Aleatorio(0, 29);
    else if(data.mes == 2 && data.ano % 4 != 0)
        data.dia = Aleatorio(0, 28);
    
    return data;
}

void CriarIndiv(Pessoa *P, int n){
    for(int i = 0; i < n; i++){
        sprintf(P[i].CC, "Numero-%d", i+1);
        if(Aleatorio(0, 1) == 1)
            P[i].genero = 'M';
        else
            P[i].genero = 'F';

    P[i].altura = Aleatorio(100, 200)/100.0;
    P[i].massa = Aleatorio(0, 250000)/100.0;
    P[i].nascimento = DataValidaAleatoria(P->nascimento, 2000, 2020); 
    }
}

void MostrarIndiv(Pessoa *P, int n){
    for (int i = 0; i < n; i++){
        printf("Cartao de cidadao: %s\n", P[i].CC);
        printf("Genero: %c\n", P[i].genero);
        printf("Altura: %.2f m\n", P[i].altura);
        printf("Massa: %.2f Kg\n", P[i].massa);
        printf("Data de nascimento: %d/%d/%d\n", P[i].nascimento.dia, P[i].nascimento.mes, P[i].nascimento.ano);
        printf("-----------------------------\n");
    }
}

int indSaudaveis(Pessoa *P, int n){
    int count = 0;
    for (int i = 0; i < n; i++){

        float IMC = P[i].massa/(P[i].altura*P[i].altura);

        if(IMC >= 18.5 && IMC <= 24.9)
            count++;
    }
    return count;
}

float MediaMassa(Pessoa *P, int n, int min, int max){
    float soma = 0.0;
    int count = 0;
    for (int i = 0; i < n; i++){
        if(P[i].nascimento.ano >= min && P[i].nascimento.ano <= max){
            soma += P[i].massa;
            count++;
        }
    }
    return soma/count;
}

int RemoverIndiv(Pessoa *P, int n, char CC[MAX_CC]){
    for (int i = 0; i < n; i++){
        if(strcmp(P[i].CC, CC) == 0){
            for (int j = i; j < n; j++)
                P[j] = P[j+1];
            n--;
            P = realloc(P, sizeof(Pessoa) * n); 
            break; 
        } 
    }
    return n;
}

/* int main(){
    srand(time(NULL));
    int nReg, AnoInicio, AnoFinal;

    printf("Quantos individuos quer criar? ");
    scanf("%d", &nReg);

    Pessoa *listIndiv = (Pessoa*) malloc(sizeof(Pessoa) * nReg);

    CriarIndiv(listIndiv, nReg);
    MostrarIndiv(listIndiv, nReg);
    printf("Quantidade de individuos saudaveis: %d\n\n", indSaudaveis(listIndiv, nReg));

    printf("Teste de medias de massa corporal\n");
    printf("Insira o ano de inicio de teste: ");
    scanf("%d", &AnoInicio);
    printf("\nInsira o ano de final de teste: ");
    scanf("%d", &AnoFinal);

    printf("\nMedia de massa corporal entre %d e %d (inclusive): %.3f Kg\n", AnoInicio, AnoFinal, MediaMassa(listIndiv, nReg, AnoInicio, AnoFinal));
    
    printf("Insira o numero de CC da pessoa que quer remover: ");
    scanf("%d", &nRemover);
    sprintf(numeroRemover, "Numero-%d", nRemover);

    nReg = RemoverIndiv(listIndiv, nReg, numeroRemover);
    MostrarIndiv(listIndiv, nReg);

    free(listIndiv);
} */