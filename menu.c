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
                        case 3: findMin(root);
                            break;
                        case 4: findMax(root);
                            break;
                    }
                if((choice >= 1) && (choice <= 7))
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
