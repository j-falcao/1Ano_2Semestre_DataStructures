#include "TipoDados.h"

extern int Aleatorio(int min, int max);

REGISTO_UTILIZADORES *LerFicheiro(int *nReg, char* nomeFicheiro){

    FILE *f = fopen(nomeFicheiro, "rb");
    if (f == NULL){
        printf("Impossivel abrir ficheiro");
        exit(1);
    }

    *nReg = 0;
    REGISTO_UTILIZADORES *R = (REGISTO_UTILIZADORES*) malloc(sizeof(REGISTO_UTILIZADORES));

    for(int i = 0;; i++){
        if(feof(f) == 0)
            R = realloc(R, (i+1)*sizeof(REGISTO_UTILIZADORES));
        else{
            *nReg = i-1;
            return R;
        }
            

        size_t len;
        fread(&len, sizeof(size_t), 1, f);
        R[i].nome = (char*) malloc(sizeof(char) * len);
        fread(R[i].nome, len, 1, f);

        fread(&len , sizeof(size_t), 1, f);
        R[i].utilizador = (char*) malloc(sizeof(char) * len);
        fread(R[i].utilizador, len, 1, f);

        fread(&len , sizeof(size_t), 1, f);
        R[i].password = (char*) malloc(sizeof(char) * len);
        fread(R[i].password, len, 1, f);

        fread(&len , sizeof(size_t), 1, f);
        R[i].email = (char*) malloc(sizeof(char) * len);
        fread(R[i].email , len, 1, f);

        fread(&len , sizeof(size_t), 1, f);
        R[i].pagina_web_pessoal = (char*) malloc(sizeof(char) * len);
        fread(R[i].pagina_web_pessoal, len, 1, f);

        fread(&R[i].joia , sizeof(float), 1, f);
        fread(&R[i].data_registo , sizeof(DATA), 1, f);
        fread(&R[i].telemovel , sizeof(int), 1, f);
        fread(&R[i].numero_acessos , sizeof(int), 1, f);
        fread(&R[i].data_ultimo_acesso , sizeof(DATA), 1, f);
        fread(&R[i].id , sizeof(int), 1, f);
    }
    fclose(f);
}

void GuardarFicheiro(REGISTO_UTILIZADORES *R, int nReg, char *nomeficheiro){
    FILE *f = fopen(nomeficheiro, "wb");

    if(f == NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    for(int i = 0; i < nReg; i++){

        size_t len = strlen(R[i].utilizador) + 1;
        fwrite(&len, sizeof(size_t), 1, f);
        fwrite(R[i].nome, len, 1, f);

        len = strlen(R[i].utilizador) + 1;
        fwrite(&len , sizeof(size_t), 1, f);
        fwrite(R[i].utilizador, len, 1, f);

        len = strlen(R[i].password) + 1;
        fwrite(&len , sizeof(size_t), 1, f);
        fwrite(R[i].password, len, 1, f);

        len = strlen(R[i].email) + 1;
        fwrite(&len , sizeof(size_t), 1, f);
        fwrite(R[i].email , len, 1, f);

        len = strlen(R[i].pagina_web_pessoal) + 1;
        fwrite(&len , sizeof(size_t), 1, f);
        fwrite(R[i].pagina_web_pessoal, len, 1, f);

        fwrite(&R[i].joia , sizeof(float), 1, f);
        fwrite(&R[i].data_registo , sizeof(DATA), 1, f);
        fwrite(&R[i].telemovel , sizeof(int), 1, f);
        fwrite(&R[i].numero_acessos , sizeof(int), 1, f);
        fwrite(&R[i].data_ultimo_acesso , sizeof(DATA), 1, f);
        fwrite(&R[i].id, sizeof(int), 1, f);
    }
    fclose(f);
}

REGISTO_UTILIZADORES *BubbleSort_data_registo(REGISTO_UTILIZADORES *R, int nReg, int order){

    REGISTO_UTILIZADORES temp;

    for (int i = 0; i < nReg-1; i++){
        for (int j = 0; j < nReg-i-1; j++){
            if(order == 0){
                if(DataAntes_Depois(R[j+1].data_registo, R[j].data_registo)){
                    temp = R[j];
                    R[j] = R[j+1];
                    R[j+1] = temp;
                }      
            }
            else{
                if(DataAntes_Depois(R[j].data_registo, R[j+1].data_registo)){
                    temp = R[j];
                    R[j] = R[j+1];
                    R[j+1] = temp;
                }
            }
        }
    }
    return R;
}

REGISTO_UTILIZADORES *OrdenarDataRegisto_BubbleSort(REGISTO_UTILIZADORES *R, int nReg){
    char ascendente_descendente;
    int asc_desc;
    printf("Quer ordenar de forma ascendente ou descendente (a / d)? ");
    scanf(" %c", &ascendente_descendente);
    if(ascendente_descendente == 'a' || ascendente_descendente == 'A')
        asc_desc = 0;
    else 
        asc_desc = 1;
    
    return BubbleSort_data_registo(R, nReg, asc_desc);
}

REGISTO_UTILIZADORES *SelectionSort_data_ultimo_acesso(REGISTO_UTILIZADORES *R, int nReg, int order){
    
    REGISTO_UTILIZADORES temp;
    DATA Data;
    int min, i, j;

    for (i = 0; i < nReg-1; i++){
        min = i, Data = R[i].data_ultimo_acesso;
        for (j = i+1; j < nReg; j++){
            if(order == 0){
                if(DataAntes_Depois(R[j].data_ultimo_acesso, Data)){
                    min = j;  
                    Data = R[j].data_ultimo_acesso;
                } 
            }
            else{
                if(DataAntes_Depois(Data, R[j].data_ultimo_acesso)){
                    min = j;
                    Data = R[j].data_ultimo_acesso;
                }
            }
        }
        temp = R[i];
        R[i] = R[min];
        R[min] = temp;
    }
    return R;
}

REGISTO_UTILIZADORES *OrdenarDataRegisto_SelectionSort_data_ultimo_acesso(REGISTO_UTILIZADORES *R, int nReg){
    char ascendente_descendente;
    int asc_desc;
    printf("Quer ordenar de forma ascendente ou descendente (a / d)? ");
    scanf(" %c", &ascendente_descendente);
    if(ascendente_descendente == 'a' || ascendente_descendente == 'A')
        asc_desc = 0;
    else 
        asc_desc = 1;

    return SelectionSort_data_ultimo_acesso(R, nReg, asc_desc);
}

//&&&&&&&&&&&&&&&&&&&&&&&&&____QUICK_SORT__&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&//

void swap(REGISTO_UTILIZADORES *R, int left, int right){
    REGISTO_UTILIZADORES temp = R[left];
    R[left] = R[right];
    R[right] = temp;
}

int partition(REGISTO_UTILIZADORES *R, int left, int right, int pivot, int asc_desc){
    if(asc_desc == 0){
        while(left <= right){
            while(R[left].id < pivot)
                left++;
            while(R[right].id > pivot)
                right--;
            if(left <= right){
                swap(R, left, right);
                left++;
                right--;
            }
        }
    }
    else{
       while(left <= right){
            while(R[left].id > pivot)
                left++;
            while(R[right].id < pivot)
                right--;
            if(left <= right){
                swap(R, left, right);
                left++;
                right--;
            }
        } 
    }
}

void QuickSort_ID(REGISTO_UTILIZADORES *R, int left, int right, int asc_desc){
    if(left >= right)
    return;

    int pivot = R[(left+right)/2].id;
    int index = partition(R, left, right, pivot, asc_desc);

    QuickSort_ID(R, left, index-1, asc_desc);
    QuickSort_ID(R, index, right, asc_desc);
}

void OrdenarID_QuickSort(REGISTO_UTILIZADORES *R, int nReg){
    char ascendente_descendente;
    int asc_desc;
    printf("Quer ordenar de forma ascendente ou descendente (a / d)? ");
    scanf(" %c", &ascendente_descendente);
    if(ascendente_descendente == 'a' || ascendente_descendente == 'A')
        asc_desc = 0;
    else 
        asc_desc = 1;

    QuickSort_ID(R, 0, nReg-1, asc_desc);
}

void LibertarMemoria(REGISTO_UTILIZADORES *R){
    free(R);
}




