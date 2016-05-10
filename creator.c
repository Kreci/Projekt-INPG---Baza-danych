#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "inserter.h"
node* createNode(data* input)                               //Funkcja wypełnia nowy element danymi
  {
    node* new_node = (node*) malloc(sizeof(node));
    
    if(new_node == NULL)
      {
        printf("Blad alokacji pamieci\n");
        return NULL;
      }
    
    new_node->entry = *input;
    new_node->left = NULL;
    new_node->right = NULL;
    
    return new_node;
  }

void addNodes(node** root)                            //Funkcja tworzy i elementów i umieszcza je w drzewie
  {
    int i, j;
    data input;
    
    printf("Ile elementow chcesz dodac?\n");
    scanf("%d", &i);
    if(i <= 0)
      {
        printf("Zla liczba\n");
        return;
      }
    for(j=0; j<i; j++)
      {
        printf("Podaj nazwe gatunkowa\n");
        scanf("%s", input.stdName);
        printf("Podaj nazwe lacinska\n");
        scanf("%s", input.latinName);
        printf("Podaj rodzine\n");
        scanf("%s", input.rodzina);
        printf("Podaj rodzaj\n");
        scanf("%s", input.rodzaj);
        printf("Wprowadz opis gatunku\n");
        scanf("%s, input.opis);
        insertNode(root, &input);
      }
    return;
  }
