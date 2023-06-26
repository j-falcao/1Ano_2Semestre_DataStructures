#ifndef Menus_H_INCLUDED
#define Menus_H_INCLUDED

#include "Lista.h"

void menu_principal(Lista* L, char* nomeficheiro);
void menu_inserir(Lista* L, Elemento* Aux);
void menu_retirar(Lista* L, Elemento* Aux);
void menu_mostrar(Lista* L);
void menu_exportar_importar(Lista* L, char* nomeficheiro);
void Menu_Sair(Lista*L, char *nomeficheiro);

#endif