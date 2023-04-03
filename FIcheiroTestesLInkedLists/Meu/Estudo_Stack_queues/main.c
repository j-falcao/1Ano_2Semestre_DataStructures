#include "Conta_Bancaria.h"
#include "Lista.h"

extern int Aleatorio(int min, int max);

int main(){
    srand(time(NULL));
    
    char **tipos = (char**) malloc(sizeof(char*) * 3);
    for (int i = 0; i < 3; i++)
        tipos[i] = (char*) malloc(sizeof(char) *20);
    strcpy(tipos[0], "Visa");
    strcpy(tipos[1], "MasterCard");
    strcpy(tipos[2], "American_Express");


   /*  //Stack
    Lista *L = CriarLista();
    for(int i = 0; i < 5; i++){
        Conta* C = CriarConta(Aleatorio(0, 1000000), tipos[Aleatorio(0,2)]);
        addElem(L, C);
    }
    MostrarLista(L);
    DestruirLista(L);


    //Queue
    Lista *Li = CriarLista();
    for (int i = 0; i < 5; i++){
        Conta* Co = CriarConta(Aleatorio(0, 1000000), tipos[Aleatorio(0,2)]);
        addElem_Queue(Li, Co);
    }
    for (int i = 0; i < 3; i++)
        remElem(Li);
    

    MostrarLista(Li);
    DestruirLista(Li); */
    

    //Ordered
    Lista *Lis = CriarLista();
    for (int i = 0; i < 5; i++){
        Conta* Con = CriarConta(Aleatorio(0, 1000000), tipos[Aleatorio(0,2)]);
        addElem_Order(Lis, Con, 0);
    }
    
    MostrarLista(Lis);
    DestruirLista(Lis);

    return 0;
}