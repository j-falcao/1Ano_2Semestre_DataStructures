#include "TiposDados.h"

extern int Aleatorio(int min, int max);

int main(){
    srand(time(NULL));
    int nReg, AnoInicio, AnoFinal, nRemover;
    char numeroRemover[MAX_CC];

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
}