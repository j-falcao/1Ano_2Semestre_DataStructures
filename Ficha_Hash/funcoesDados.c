#include "TipoDados.h"

Pessoa* gerarPessoaAleatoria(){
    Pessoa *novaPessoa = (Pessoa*) malloc(sizeof(Pessoa));
    sprintf(novaPessoa->nome, "Pessoa%d", IdPessoaConsecutivo);
    novaPessoa->idade = Aleatorio(0, 100);
    novaPessoa->altura_metros = 1 + (Aleatorio(0, 100) / 100.0);
    novaPessoa->peso_quilos = (Aleatorio(200, 12000) / 100.0);
    IdPessoaConsecutivo++;
    return novaPessoa;
}

Pessoa* gerarPessoaManual(){
    Pessoa *novaPessoa = (Pessoa*) malloc(sizeof(Pessoa));
    printc("\n\n\t[yellow]AVISO![/yellow] E melhor mostrar o hashing em primeiro lugar!\n");
    printf("\nInsira o nome da pessoa que quer remover: ");
    scanf(" %s", novaPessoa->nome);
    printf("\nInsira a idade da pessoa que quer remover: ");
    scanf(" %d", &novaPessoa->idade);
    printf("\nInsira a altura da pessoa que quer remover: ");
    scanf(" %f", &novaPessoa->altura_metros);
    printf("\nInsira o peso da pessoa que quer remover: ");
    scanf(" %f", &novaPessoa->peso_quilos);
    return novaPessoa;
}

Pessoa* gerarPessoaManualNomeIdade(){
    Pessoa *novaPessoa = (Pessoa*) malloc(sizeof(Pessoa));
    printc("\n\n\t[yellow]AVISO![/yellow] E melhor mostrar o hashing em primeiro lugar!\n");
    printf("\nInsira o nome da pessoa que quer remover: ");
    scanf(" %s", novaPessoa->nome);
    printf("\nInsira a idade da pessoa que quer remover: ");
    scanf(" %d", &novaPessoa->idade);
    return novaPessoa;  
}