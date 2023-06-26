#include "TiposDados.h"

extern int Aleatorio(int min, int max);

void CarregarDados(int n, Musica *L){
    for(int i = 0; i < n; i++){
        sprintf(L[i].titulo , "Musica-%d", i+1);
        L[i].ano = Aleatorio(2000, 2020);
        L[i].single = Aleatorio(0, 1); // 0 --> Nao Single / 1 --> Single
        L[i].NDownloads = Aleatorio(0, 20);
        L[i].interprete = Aleatorio(1,3);
    }
    
}

void MostrarMusicas(int n, Musica *L){
    for(int i = 0; i < n; i++){
        printf("Titulo: %s", L[i].titulo);
        printf("\n");
        printf("Ano: %d", L[i].ano);
        printf("\n");
        printf("Single: %d", L[i].single);
        printf("\n");
        printf("Numero de downloads: %d", L[i].NDownloads);
        printf("\n");
        printf("Interprete: %d", L[i].interprete);
        printf("\n");
        printf("\n");
    }
}

void MostrarMusicasDownload(int n, Musica *L, int NumD){
    for (int i = 0; i < n; i++)
    {
        if(L[i].NDownloads >= NumD){
        printf("Titulo: %s", L[i].titulo);
        printf("\n");
        printf("Ano: %d", L[i].ano);
        printf("\n");
        printf("Single: %d", L[i].single);
        printf("\n");
        printf("Numero de downloads: %d", L[i].NDownloads);
        printf("\n");
        printf("Interprete: %d", L[i].interprete);
        printf("\n");
        printf("\n");
        }
    }
}

int NumMusicaInterprete(int n, Musica *L, int interprete){
    int count_inter = 0;
    for(int i = 0; i < n; i++){
        if(L[i].interprete == interprete)
        count_inter++;
    }
    return count_inter;
}

float GuardarMusica(int n, Musica *L, char single, int ano){
    int count_musicas = 0, count_Down = 0, aux; 
    if(single == 's')
    aux = 1;
    else if(single == 'n')
    aux = 0;
    else if(single == 'a')
    aux = 2;
    else
    return -1;

    FILE *f = fopen("Ficha0\\Musicas_ex2.bin", "wb");
    for(int i = 0; i < n; i++){
        if((L[i].single == aux && L[i].ano >= ano) || (aux == 2 && L[i].ano >= ano)){
            printf("Titutlo: %s", L[i].titulo);
            fwrite(&L[i].ano, sizeof(int), 1, f);
            fwrite(&L[i].single, sizeof(int), 1, f);
            fwrite(&L[i].NDownloads, sizeof(int), 1, f);
            fwrite(&L[i].interprete, sizeof(int), 1, f);
            size_t LenTitulo = strlen(L[i].titulo) + 1;
            fwrite(&LenTitulo, sizeof(size_t), 1, f);
            fwrite(L[i].titulo, LenTitulo, 1, f);
            count_Down += L[i].NDownloads;
            count_musicas++;
        }
    }
    fclose(f);
    float media = count_Down/(float)count_musicas;
    return media;
}



/* int main(){
    int NMusicas, ano;
    char single;
    float MediaDown;

    srand(time(NULL));

    printf("Quantas musicas quer criar? ");
    scanf("%d", &NMusicas);
    Musica musicas[NMusicas];

    CarregarDados(NMusicas, musicas);
    MostrarMusicas(NMusicas, musicas);

    printf("Quer Guardar musicas singles, nao-singles, ou ambas (s --> single, n --> nao-single, a --> ambas): ");
    scanf(" %c", &single);
    printf("Quer Guardar musicas apartir de que ano? ");
    scanf("%d", &ano);
    MediaDown = GuardarMusica(NMusicas, musicas, single, ano);
    printf("Media de downloads das musicas guardadas: %f", MediaDown);
} */