// Wstepnie dziala
#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "tree.h"
#include "menu.h"
#include "baza.h"
//% F - Rodzina(Familly)
//% G - Rodzaj(Genus)
//% S - stdName
//% L - latinName

int zawiera(char *linia, char *klucz) // sprawdza czy linia zawiera slowo kluczowe np rodzina, rodzaj itp.
{                                     //zwraca 0 jesli nie znaleziono lub indeks tablicy charow wksazjuacy na koniec wyszukanego klucza
  int i=0, j=0;
  while(linia[i]!='\0')
  {
    if(linia[i]==klucz[j])
    {
      j++;
      if(klucz[j]=='\0') return i+1;
    }
    else j=0;
    i++;
  }
  return 0;
}


int kopiujdane(char *linia, char *kopiujdo, int indekslinii) //kupiuje dane od konca linii, lub wystapienia znaki '-'. Zwraca 0 jesli skopiowano do konca lini lub indeks tablizy charow po pauzie
{
  int i=0;
  while((linia[indekslinii]!='\0')&&(linia[indekslinii]!=37))
  {
    kopiujdo[i]=linia[indekslinii];
    if(linia[indekslinii]=='%') {kopiujdo[i]=0;return 0;}

    indekslinii++;
    i++;
    if(linia[indekslinii]=='\n')
    {
        kopiujdo[i]=0;
        return 0;
    }
  }
  kopiujdo[i]=0;
  return 0;
}

//otwieranie pliki i obsluga bazy (wtepne)

void wczytajBaze(node ** root,  char* nazwapliku)
{
    FILE *plik;
    if((plik=fopen(nazwapliku, "r"))==NULL)
    {
        printf("blad otwarcia plku");
        return;
    }

    char linia[100];
    char bufor=' ';
    int indekslinii=0;
    data dane, x;
    dane.opis[0]='\0';
    int i;
    int literka;





    while(fgets(linia, 100, plik)!=NULL)
    {
        printf(".");

        if(indekslinii = zawiera(linia, "%L"))
        {
            kopiujdane(linia, dane.latinName, indekslinii);
            if(indekslinii = zawiera(linia, "%S"))kopiujdane(linia, dane.stdName, indekslinii);
            else kopiujdane(dane.latinName,dane.stdName,0);
            x=dane;
            insertNode(root, &x);
        }
        else if(indekslinii = zawiera(linia, "%F")) kopiujdane(linia, dane.rodzina, indekslinii);
        else if(indekslinii = zawiera(linia, "%G"))kopiujdane(linia, dane.rodzaj, indekslinii);

    }
    fclose(plik);
}


void zapiszDane(data dane,  char* nazwapliku)
{
    FILE *plik;
    if(plik=fopen(nazwapliku, "a")!=NULL)
    {
        printf("blad otwarcia plku");
        return;
    }

    fprintf(plik, "\tRodzina %s\n", dane.rodzina);
    fprintf(plik, "\t\Rodaj %s\n", dane.rodzaj);
    fprintf(plik, "\t\t\tGatunek %s - %s\n", dane.latinName, dane.stdName);
    fclose(plik);
}




