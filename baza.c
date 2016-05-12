// Do testow
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
      if(klucz[j]=='\0') return ++i;
    }
    else j=0;
  }
  return 0;
}


int kopiujdane(char *linia, char *kopiujdo, int indekslinii) //kupiuje dane od konca linii, lub wystapienia znaki '-'. Zwraca 0 jesli skopiowano do konca lini lub indeks tablizy charow po pauzie
{
  int i=0
  while(linia[indekslinii]!='\0')
  {
    kopiujdo[i]=linia[indekslinii];
    indekslinii++;
    i++;
    if(linia[indekslinii]!='-') return ++indekslinii;
  }
  return 0;
}

//otwieranie pliki i obsluga bazy (wtepne)

void wczytajBaze(node ** root,  char* nazwapliku)
{
    FILE *plik;
    if(plik=fopen(nazwapliku, "r")!=NULL)
    {
        printf("blad otwarcia plku");
        return;
    }

    char linia[100];
    int indekslinii;
    data dane;

    while(fscanf(plik, linia)!=EOF)
    {
        if(indekslinii = zawiera(linia, "rodzina") kopiujdane(linia, dane.rodzina, indekslinii);
        if(indekslinii = zawiera(linia, "rodzaj")  kopiujdane(linia, dane.rodzaj, indekslinii);
        if(indekslinii = zawiera(linia, "\t\t\t\t")
        {
            if(indekslinii = kopiujdane(linia, dane.latinName, indekslinii)) //warunek sprawdzajacy czy istnieje nazwa zwyczajowa
            {
                kopiujdane(linia, data.stdName, indekslinii);
            }
            else kopiujdane("brak nazwy",data.stdName, 0); //jesli nie istnieje nazwa zwyczajowa, tutaj nie wiem jak bedzie z tworzeniem drzewa jesli nazwa zwyczajowa bedzie taka sama tzn "brak nazwy"

            insertNode(root, &dane);
        }
    }
    fclose(plik);
}





