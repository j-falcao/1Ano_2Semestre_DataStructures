#include "TipoDados.h"

Person* generateRandomPerson(){
    Person* newPerson = (Person*) malloc(sizeof(Person));
    sprintf(newPerson->name, "Person%d", IdPessoaConsecutivo);
    newPerson->age = Aleatorio(0, 100);
    newPerson->weight = Aleatorio(250, 12000) / 100.0;
    newPerson->height = Aleatorio(0, 1) + (Aleatorio(0, 99) / 100.0);
    return newPerson;
}