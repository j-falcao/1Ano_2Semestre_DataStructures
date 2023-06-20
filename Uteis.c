#include <time.h>
#include <stdlib.h>

int Aleatorio(int min, int max){
    int resultado = min + rand() % (max-min + 1);
    return resultado;
}
