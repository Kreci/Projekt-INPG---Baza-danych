#ifndef CREATOR_H
#define CREATOR_H
#include "data.h"
node *createNode(data* input); //alokuje pamiêæ na ga³ê¿ drzewa i uzupe³nia j¹ danymi
void addNodes(node** root); //kompletna funkca tworz¹ca drzewo, (alokacja pamiêci, wczytanie danych z klawiatury i do³¹czenie ich do drzewa)
#endif
