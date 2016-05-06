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
//Do uaktualnienia i poprawy, zajme się tym
int inorder(struct kontakt *head)       //Umożliwia chodzenie po drzewie galez po galezi
{
    if(head==NULL)return;
    char menu[3];
    printf("%s \n%s\n%s\n%s\n\n", head->nazwisko, head->imie, head->nr1, head->nr2);
    if(head->lewy!=NULL)printf("w lewo: %s %s\n", head->lewy->nazwisko, head->lewy->imie);
    else printf("lewy pusty\n");
    if(head->prawy!=NULL)printf("w prwo: %s %s\n", head->prawy->nazwisko, head->prawy->imie);
    else printf("prawy pusty\n");
    printf("\nMENU:\n1-w lewo\n2-w prawo\n3-do gory");
    scanf("%3s", menu);
    if(menu[0]=='1')			if(inorder(head->lewy)) inorder(head);	else return 0;
    else if(menu[0]=='2')	if(inorder(head->prawy))inorder(head);	else return 0;
    else if(menu[0]=='3')return 1;
    else return 0;
    return 0;
}
