#ifndef CREATOR_H
#define CREATOR_H
#include "data.h"
node *createNode(data* input); //alokuje pami�� na ga�� drzewa i uzupe�nia j� danymi
void addNodes(node** root); //kompletna funkca tworz�ca drzewo, (alokacja pami�ci, wczytanie danych z klawiatury i do��czenie ich do drzewa)
#endif
