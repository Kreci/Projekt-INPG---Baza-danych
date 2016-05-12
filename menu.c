#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "data.h"

void menu(node* root)
    {
        int choice;
        do
            {
                #ifdef  WIN32
                system("cls");
                #else
                system("clear");
                #endif // WIN32

                printf(" Witaj w bazie danych!\n"
                        "**********************************************\n"
                        " Wybierz funkcje\n"
                        "----------------------------------------------\n"
                        " [0] Koniec programu\n"
                        " [1] Dodaj wezly\n"
                        " [2] Wypisz zawartosc bazy\n"
                        " [3] Wypisz pierwszy (alfabetycznie) rekord\n"
                        " [4] Wypisz ostatni (alfabetycznie) rekord\n"
                        /*
                        " [5] Wypisz spis gatunków\n" \
                        " [6] Wypisz spis rodzai\n"    } Jedna ze specyfikacja czego
                        " [7] Wypisz spis rodzin\n"   /
                        " [8] Wyszukaj gatunek\n"   \
                        " [9] Wyszukaj rodzaj\n"     } Jedna ze specyfikacja czego
                        " [10] Wyszukaj rodzine\n"  /
                        */
                        "----------------------------------------------\n"
                        " Twoj wybor: ");
                scanf("%d", &choice);

                #ifdef  WIN32
                system("cls");
                #else
                system("clear");
                #endif // WIN32

                switch(choice)
                    {
                        case 1: addNodes(&root);
                            break;
                        case 2: fDisplay(root);
                            break;
                        case 3: findMin(root);
                            break;
                        case 4: findMax(root);
                            break;
                        /*
                        case 5:
                            break;
                        case 6:
                            break;
                        case 7:
                            break;
                        case 8:
                            break;
                        case 9:
                            break;
                        case 5:
                            break;
                        default: 
                            break;
                        */
                    }
                if((choice >= 1) && (choice <= 7)) // w petli while dwókrotnie czyszczenie ekranu, raczej nie potrzebne
                    {
                        #ifdef WIN32
                        system("pause");
                        #else
                        getchar();
                        getchar();
                        #endif
                    }
                }
        while(choice);
        printf("Do widzenia!\n");
    }
