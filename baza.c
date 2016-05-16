// Wstepnie dziala
#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "tree.h"
#include "menu.h"
#include "baza.h"


int zawiera(char *linia, char *klucz) // sprawdza czy linia zawiera slowo kluczowe np rodzina, rodzaj itp.
{                                     //zwraca 0 jesli nie znaleziono lub indeks tablicy charow wksazjuacy na koniec wyszukanego klucza
  int i=0, j=0;
  while(linia[i]!='\0')
  {
    if(linia[i]==klucz[j])
    {
      j++;
      i++;
      if(klucz[j]=='\0') return ++i;
    }
    else {j=0; i++;}
  }
  return 0;
}


int kopiujdane(char *linia, char *kopiujdo, int indekslinii) //kupiuje dane od konca linii, lub wystapienia znaki '-'. Zwraca 0 jesli skopiowano do konca lini lub indeks tablizy charow po pauzie
{
  int i=0;
  while(linia[indekslinii]!='\0')
  {
    kopiujdo[i]=linia[indekslinii];
    indekslinii++;
    i++;
    if(linia[indekslinii]=='-') return ++indekslinii;
    if(linia[indekslinii]=='\n') return 0;
  }
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
    int indekslinii;
    data dane;

    while(fgets(linia, 100, plik)!=NULL)
    {
        printf(".");
        if(indekslinii = zawiera(linia, "Rodzina")) kopiujdane(linia, dane.rodzina, indekslinii);
        if(indekslinii = zawiera(linia, "Rodzaj"))kopiujdane(linia, dane.rodzaj, indekslinii);
        if(indekslinii = zawiera(linia, "\t\t\t\t"))
        {
            if(indekslinii = kopiujdane(linia, dane.latinName, indekslinii)) //warunek sprawdzajacy czy istnieje nazwa zwyczajowa
            {
                kopiujdane(linia, dane.stdName, indekslinii);
            }
            else kopiujdane(dane.latinName, dane.stdName, 0); //jesli nie istnieje nazwa zwyczajowa, przyjmujemy za nią nazwe lacinska

            insertNode(root, &dane);
        }
        else if(indekslinii = zawiera(linia, "\t\t\tGatunek"))
        {
            if(indekslinii = kopiujdane(linia, dane.latinName, indekslinii)) //warunek sprawdzajacy czy istnieje nazwa zwyczajowa
            {
                kopiujdane(linia, dane.stdName, indekslinii);
            }
            else kopiujdane(dane.latinName, dane.stdName, 0); //jesli nie istnieje nazwa zwyczajowa, przyjmujemy za nią nazwe lacinska

            insertNode(root, &dane);
        }
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




