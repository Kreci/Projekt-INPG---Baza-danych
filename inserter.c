#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "creator.h"
void insertNode(node **root, data* input)                                        //Funkcja wstawia wezel w odpowiednie miejsce drzewa
    {
        node *new_node = createNode(input);
        if(new_node==NULL)
        {
            printf("\nblad alokacji pamieci\n");
            return;
        }
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
                        printf("Ten rekord juz istnieje\n");
                        return;
                    }
            }
        if(compare(new_node->entry, temp->entry) == -1)
            temp->left = new_node;
        else if(compare(new_node->entry, temp->entry) == 1)
            temp->right = new_node;
        return;
    }
