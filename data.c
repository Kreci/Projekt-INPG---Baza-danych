#include <stdio.h>
#include <stdlib.h>
#include "data.h"
//*******************************************************************************************************************************
int compare(data entry1, data entry2)       //Compares entries(surnames), returns 1 if first one is bigger, -1 if second one, 0 if equal
{
    int i;
    int code1, code2;
    for(i=0; entry1.stdName[i]!='\0'||entry2.stdName[i]!='\0'; i++)
    {
        code1=entry1.stdName[i];
        code2=entry2.stdName[i];
        if(code1>96)                        //In case of capital letters
            code1-=32;
        if(code2>96)
            code2-=32;
        if(code1>code2)
            return 1;
        if(code2>code1)
            return -1;
    }
    if(entry1.stdName[i]!='\0')
        return 1;
    if(entry2.stdName[i]!='\0')
        return -1;
    return 0;
}
//*******************************************************************************************************************************
void display(data entry)                //Displays name, surname and tel of entry, NOT node
{
    printf("%s\b\b", entry.stdName);
    puts(entry.latinName);
    return;
}
//*******************************************************************************************************************************
void fDisplay(node *root)               //Displays whole tree in-order (alphabetically)
{
    if(root->left!=NULL)
        fDisplay(root->left);
    display(root->entry);
    printf("\n\n");
    if(root->right!=NULL)
        fDisplay(root->right);
    return;
}
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
