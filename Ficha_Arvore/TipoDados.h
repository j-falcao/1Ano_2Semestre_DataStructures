#ifndef TIPODADOS_H_INCLUDED
#define TIPODADOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Printcolor
#ifndef CJAG_COLORPRINT
#define CJAG_COLORPRINT
#define ERROR_TAG "[r][ERROR][/r] "
void printc(const char *fmt, ...);
void spinner_start(unsigned int type, const char *fmt, ...);
void spinner_update(const char *fmt, ...);
void spinner_done(const char *fmt, ...);
void progress_start(int max, char *fmt);
void progress_update();
#endif


typedef struct{
    char name[20];
    int age;
    float weight, height;
}Person;

Person* generateRandomPerson();

extern int Aleatorio(int min, int max);
extern int IdPessoaConsecutivo;
#endif