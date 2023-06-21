#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int Aleatorio(int min, int max){
    int resultado = min + rand() % (max-min + 1);
    return resultado;
}