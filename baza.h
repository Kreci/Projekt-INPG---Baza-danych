#ifndef OBSLUGA_PLIKU
#define OBSLUGA_PLIKU

int zawiera(char *linia, char *klucz);                         // sprawdza czy linia zawiera slowo kluczowe np rodzina, rodzaj itp.
                                                              //zwraca 0 jesli nie znaleziono lub indeks tablicy charow wksazjuacy na koniec wyszukanego klucza

int kopiujdane(char *linia, char *kopiujdo, int indekslinii);  //kupiuje dane od konca linii, lub wystapienia znaki '-'. 
                                                              //Zwraca 0 jesli skopiowano do konca lini lub indeks tablizy charow po pauzie

void wczytajBaze(node ** root,  char* nazwapliku);             //otwiera plik z baza oraz wczytuje z niego dane do drzewa


#endif // OBSLUGA_PLIKU
