#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern int Aleatorio(int min, int max);

int* CriarMatriz(int m, int n){
    int tam = m*n;
    int *dados = (int*) malloc(sizeof(int) * tam);
    for(int i = 0; i < tam; i++){
        dados[i] = Aleatorio(0,5);
    }
    return dados;
}

void DestruirMatriz(int *Mat){
    free(Mat);
}


void MostrarMatriz(int *Mat, int m, int n){
    int pos = 0;
    for(int i = 0; i < m; i++){
        for(int  j = 0; j < n; j++)
            printf("%d", Mat[pos++]);
    printf("\n");
    }
}

int Matriz_esparsa(int *Matriz, int M, int N, float percentagem){
    int count = 0;
    for(int i = 0; i < M*N; i++){
            if(Matriz[i] == 0)
            count++;
        }
    if((count/(float)(M*N)) > percentagem)
        return 1;
    else
        return 0;
}

/* int main()
{
srand(time(NULL));
int *mat = CriarMatriz(5, 5);
MostrarMatriz(mat, 5, 5);
printf("\n");
printf("%d", Matriz_esparsa(mat, 5, 5, 0.1));
DestruirMatriz(mat);
} */
