#ifndef BRZOZA
#define BRZOZA
#include "data.h"

void insertNode(node **, data*);    //umiejscawia galaz w drzewie
node *createNode(data* input);      //alokuje pamiec na gałaz drzewa i uzupelnia ja danymi
void addNodes(node** root);         //kompletna funkcja tworzaca drzewo, (alokacja pamieci, wczytanie danych z klawiatury i dolaczenie ich do drzewa)
void findMin(node*);	              //displays first (alphabetically) entry
void findMax(node*); 	              //displays last (alpabetically) entry
int nodeNumber(node*);              //Podaje liczbe wpisow
void mDestroy(node *);        //Usuwa wskazany element bez usuwania przypadkowych elementow
void freeMem(node*);                //Zwalnia pamiec
#endif
