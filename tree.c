#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "tree.h"
#include "baza.h"
//*******************************************************************************************************************************
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
  //*******************************************************************************************************************************
  void insertNode(node **root, data* input)                                        //Funkcja wstawia wezel w odpowiednie miejsce drzewa
    {
        node *new_node = createNode(input);
        node *temp = NULL;

        if(*root == NULL)
            {
                *root = new_node;
                return;
            }

        temp = *root;
        while(temp != NULL)
            {
                if(compare(new_node->entry, temp->entry) == -1)
                    {
                        if(temp->left != NULL)
                            temp = temp->left;
                        else
                            break;
                    }
                else if(compare(new_node->entry, temp->entry) == 1)
                    {
                        if(temp->right != NULL)
                            temp = temp->right;
                        else
                            break;
                    }
                else
                    {
                        printf("Ten rekord juz istnieje, nie dodaje\n");
                        return;
                    }
            }
        if(compare(new_node->entry, temp->entry) == -1)
            temp->left = new_node;
        else if(compare(new_node->entry, temp->entry) == 1)
            temp->right = new_node;
        return;
    }
//*******************************************************************************************************************************
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
    
    #ifdef WIN32
    system("cls");
    #else
    system("clear");
    #endif // WIN32
    
    for(j=0; j<i; j++)
      {
        fflush(stdin);
        printf("Podaj nazwe gatunkowa\n");
        gets(input.stdName);
        printf("Podaj nazwe lacinska\n");
        gets(input.latinName);
        printf("Podaj rodzine\n");
        gets(input.rodzina);
        printf("Podaj rodzaj\n");
        gets(input.rodzaj);
        printf("Wprowadz opis gatunku\n");
        gets(input.opis);
        
        #ifdef WIN32
        system("cls");
        #else
        system("clear");
        #endif // WIN32
        
        insertNode(root, &input);
      }
    return;
  }
//*******************************************************************************************************************************
/*int browse_tree(node *head)       //Umożliwia chodzenie po drzewie galez po galezi
{
    if(head==NULL)return;
    char menu[3];
    printf("%s \n%s\n\n", head->data.stdName, head->data.latinName);
    if(head->lewy!=NULL)printf("w lewej gałęzi: %s %s\n", head->left->data.stdName, head->left->data.latinName);
    else printf("lewy pusty\n");
    if(head->prawy!=NULL)printf("w prawej gałęzi: %s %s\n", head->right->data.stdName, head->right->data.latinName);
    else printf("prawy pusty\n");
    printf("\nMENU:\n1-idz w lewo\n2-idz w prawo\n3-cofnij (do gory)");
    scanf("%3s", menu);
    if(menu[0]=='1')			if(browse_tree(head->left)) browse_tree(head);	else return 0;
    else if(menu[0]=='2')	if(browse_tree(head->right))inorder(head);	else return 0;
    else if(menu[0]=='3')return 1;
    else return 0;
    return 0;
}*/
//*******************************************************************************************************************************
void findMin(node* root)	              //displays first (alphabetically) entry
    {
        if(root == NULL)
            {
                printf("Baza jest pusta!\n");
                return;
            }
        if(root->left != NULL)
            return findMin(root->left);
        else
            display(root->entry);
        return;
    }
//*******************************************************************************************************************************
void findMax(node* root) 	              //displays last (alpabetically) entry
    {
        if(root == NULL)
            {
                printf("Baza jest pusta!\n");
                return;
            }
        if(root->right != NULL)
            return findMax(root->right);
        else
            display(root->entry);
        return;
    }
//*******************************************************************************************************************************
int nodeNumber(node *root)                                               //Zwraca liczbe wezlow w drzewie
    {
        int counter=0;
        if(root != NULL)
            {
                counter++;
                counter = counter + nodeNumber(root->left) + nodeNumber(root->right);
            }
        return counter;
    }
//*******************************************************************************************************************************
void findRecord(node *root)             //wyszukuje element o zadanej nazwie gatunkowej
    {
        data input;

        if(root == NULL)
            {
                printf("Baza jest pusta!\n");
                return;
            }
        printf("Podaj nazwe zwyczajowa\n");
        scanf("%s", input.stdName);

        while(root != NULL)
            {
                if(compare(root->entry, input) == -1)
                    root = root->left;
                else if(compare(root->entry, input) == 1)
                    root = root->right;
                else
                    {
                        display(root->entry);
                        return;
                    }
            }
        printf("Nie znaleziono szukanego gatunku\n");
        return;
    }

void deleteNode(node** root)
  {
    if(*root == NULL)
        {
          printf("Baza jest pusta!\n");
          return;
        }
  }
