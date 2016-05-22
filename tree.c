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
                    root = root->right;
                else if(compare(root->entry, input) == 1)
                    root = root->left;
                else
                    {
                        display(root->entry);
                        return;
                    }
            }
        printf("Nie znaleziono szukanego gatunku\n");
        return;
    }
void mDestroy(node *root)                 //Usuwa wezel i wstawia inny, odpowiedni, w jego miejsce
{   
    data sEntry;                                    //Jesli najwiekszy w swoim poddrzewie - lewe dziecko
    node *ptr;                                      //W przeciwnym wypadku najmniejszy element prawego poddrzewa
    node *hlp;
    node *hlp2;
    ptr = root;
    printf("Podaj nazwe zwyczajowa\n");
    scanf("%s", sEntry.stdName);
    int comp = compare(sEntry, root->entry);
    if(comp != 0)                                   //Wyszukiwanie elementu do usuniecia
    {
            while(((comp!=1||ptr->right!=NULL)&&(comp!=-1||ptr->left!=NULL))&&(comp!=1||compare(sEntry, ptr->right->entry)!=0)&&(comp!=-1||compare(sEntry, ptr->left->entry)!=0))
            {
                if(comp == 1)
                    ptr = ptr->right;
                else if(comp == -1)
                    ptr = ptr->left;
                comp = compare(sEntry, ptr->entry);
            }
            if((comp == 1 && ptr->right == NULL) || (comp == -1 && ptr->left == NULL))
            {
                printf("Entry not found\n");
                return;
            }
            else
            {
                if(comp == 1)
                {
                    hlp = ptr->right;
                    if(hlp->left == NULL && hlp->right == NULL)               //Jesli usuwamy lisc
                    {
                        free(ptr->right);
                        ptr->right = NULL;
                        return;
                    }
                    else if(hlp->right == NULL)                             //Jesli najwiekszy w swoim poddrzewie
                    {
                        hlp = hlp->left;
                        free(ptr->right);
                        ptr->right = hlp;
                        return;
                    }
                    else                                                    //Poszukiwanie minimum z prawego poddrzewa
                    {
                        if((hlp->right->left == NULL && hlp->right->right == NULL)) //Aborcja dziecka
                        {
                            hlp->right->left = hlp->left;
                            free(ptr->right);
                            ptr->right = hlp->right;
                            return;
                        }
                        else                                                    //Szukanie w glab drzewa
                        {
                            hlp = hlp->right;
                            while(hlp->left->left != NULL)
                            {
                                hlp = hlp->left;
                            }
                           hlp2 = hlp->left;
                           hlp->left = hlp2->right;
                           hlp2->left = ptr->right->left;
                           hlp2->right = ptr->right->right;
                           free(ptr->right);
                           ptr->right = hlp2;
                           return;
                        }

                    }
                }
                else if(comp == -1)
                {
                    hlp = ptr->left;
                    if(hlp->left == NULL && hlp->right == NULL)               //Jesli usuwamy lisc
                    {
                        free(ptr->left);
                        ptr->left = NULL;
                        return;
                    }
                    else if(hlp->right == NULL)                             //Jesli najwiekszy w swoim poddrzewie (brak dziecka z prawego loza)
                    {
                        hlp = hlp->left;
                        free(ptr->left);
                        ptr->left = hlp;
                        return;
                    }
                    else                                                    //Poszukiwanie najmniejszego dziecka z prawego poddrzewa
                    {
                        if((hlp->right->left == NULL && hlp->right->right == NULL))
                        {
                            hlp->right->left = hlp->left;
                            free(ptr->left);
                            ptr->left = hlp->right;
                            return;
                        }
                        else
                        {
                            hlp = hlp->right;
                            while(hlp->left->left != NULL)
                            {
                                hlp = hlp->left;
                            }
                           hlp2 = hlp->left;
                           hlp->left = hlp2->right;
                           hlp2->left = ptr->left->left;
                           hlp2->right = ptr->left->right;
                           free(ptr->left);
                           ptr->left = hlp2;
                           return;
                        }

                    }
                }
            }
    }
    else                                                //Jezeli usuwamy korzen
    {
        /*if(root->right == NULL && root->left == NULL)         //PROBLEM
        {
            free(root);
            root = NULL;
            return;
        }*/                       //Siekiera, motyka, brutalna sila, PO PROBLEMIE :)
        else if(root->right == NULL)
        {
            root->entry = root->left->entry;
            ptr = root->left->left;
            root->right = root->left->right;
            free(root->left);
            root->left = ptr;
            return;
        }
        else if(root->left == NULL)
        {
            root->entry = root->right->entry;
            ptr = root->right->right;
            root->left = root->right->left;
            free(root->right);
            root->right = ptr;
            return;
        }
        else
        {
            if((ptr->right->left == NULL && ptr->right->right == NULL))
            {
                root->entry = root->right->entry;
                free(root->right);
                root->right = NULL;
                return;
            }
            else
            {
                ptr = ptr->right;
                while(ptr->left->left != NULL)
                {
                    ptr = ptr->left;
                }
                root->entry = ptr->left->entry;
                hlp = ptr->left->right;
                free(ptr->left);
                ptr->left = hlp;
                return;
            }
        }
    }
}
void freeMem(node *root)
{
  if(root != NULL)
  {
    freeMem(root->left);
    root->left = NULL;
    freeMem(root->right);
    root->right = NULL;
    free(root);
    root=NULL;
  }
  return;
}
