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