// Do skonczenia

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
int kopiujdane(char *linia, char *kopiujdo, int indekslinii)
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


char* nazwapliku
FILE *plik;
plik=fopen(nazwapliku, "r+")
    
    char linia[100];
    char actualrodzina[LENGTH];
    char actualrodzaj[LENGTH];
    int indekslinii;
    
    data dane;
    while(fscanf(plik, linia)!=EOF)
    {
      if(indekslinii = zawiera(linia, "rodzina") kopiujdane(linia, actualrodzina, indekslinii);
      if(indekslinii = zawiera(linia, "rodzaj")  kopiujdane(linia, actualrodzaj, indekslinii);
      if(indekslinii = zawiera(linia, "\t\t\t\t")  
      if(indekslinii = kopiujdane(linia, dane.latinname, indekslinii))
      
      
    
    }
    
    
