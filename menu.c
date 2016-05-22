#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "data.h"
#include "baza.h"

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

                printf(" Witaj w bazie danych dot. nietoperzy!\n"
                        "**********************************************\n"
                        " Wybierz funkcje\n"
                        "----------------------------------------------\n"
                        " [0] Koniec programu\n"
                        " [1] Dodaj nowe gatunki\n"
                        " [2] Wypisz zawartosc bazy danych\n"
                        " [3] Wypisz pierwszy (alfabetycznie) gatunek\n"
                        " [4] Wypisz ostatni (alfabetycznie) gatunek\n"
                        " [5] Wyszukaj gatunki\n"
                        " [6] Usun wpis\n"                        
                        " [7] Wczytaj baze z pliku\n"
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
                        case 0: break;
                        case 1: addNodes(&root);
                            break;
                        case 2: fDisplay(root);
                            break;
                        case 3: findMin(root);
                            break;
                        case 4: findMax(root);
                            break;
                        case 5: znajdz(root);
                            break;
                        case 6: 
                                if(root==NULL)
                                {
                                    printf("Nie ma drzewa do usuniecia\n");
                                    break;
                                }
                                else if(root->left==NULL&&root->right==NULL)
                                {
                                    printf("Nie mozna usunac jedynego elementu bazy\n");
                                    break;
                                }
                                else
                                mDestroy(root);               
                            break;
                         case 7: wczytajBaze(& root,  "Baza.txt");
                            break;
                        default:  puts ("Niepoprawna wartosc, sprobuj ponownie");
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
