#include <time.h>
#include <stdlib.h>

int Aleatorio(int min, int max){
    int resultado = min + rand() % (max-min + 1);
    return resultado;
}

void scanfs(const char* formato, void *DataScanf, char *MensagemRepitida, char *AvisoError){
    int invalid = 0;
    do{
        printc("\n%s", MensagemRepitida);
        bufferclear();
        invalid = scanf(formato, DataScanf);
        invalid != 1 ? printf("%s\n", AvisoError),  bufferclear() : (void)NULL;
    }while(invalid != 1);
}