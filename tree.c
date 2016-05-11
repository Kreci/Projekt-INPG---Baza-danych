#include <stdio.h>
#include <stdlib.h>
#include "data.h"
//*******************************************************************************************************************************
int browse_tree(node *head)       //Umożliwia chodzenie po drzewie galez po galezi
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
}
//*******************************************************************************************************************************
void findMin(node* root)
    {
        if(root == NULL)
            {
                printf("Drzewo jest puste!\n");
                return;
            }
        if(root->left != NULL)
            return findMin(root->left);
        else
            printf("Pierwszy rekord to %s\n", root->entry.stdName);
        return;
    }
//*******************************************************************************************************************************
void findMax(node* root)
    {
        if(root == NULL)
            {
                printf("Drzewo jest puste!\n");
                return;
            }
        if(root->right != NULL)
            return findMax(root->right);
        else
            printf("Ostatni rekord to %s\n", root->entry.stdName);
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
    void findRecord(node *root)
    {
        data input;

        if(root == NULL)
            {
                printf("Drzewo jest puste!\n");
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
                    }
            }
        printf("Nie znaleziono szukanego gatunku\n");
        return;
    }
