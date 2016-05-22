#include <stdio.h>
#include <stdlib.h>
#include "data.h"
//*******************************************************************************************************************************
int compare(data entry1, data entry2)       //Compares entries(surnames), returns 1 if first one is bigger, -1 if second one, 0 if equal
{
    int i;
    int code1, code2;
    for(i=0; entry1.stdName[i] != '\0' || entry2.stdName[i] != '\0'; i++)
    {
        code1=entry1.stdName[i];
        code2=entry2.stdName[i];
        if(code1 > 96)                        //In case of capital letters
            code1 -= 32;
        if(code2 > 96)
            code2 -= 32;
        if(code1 > code2)
            return 1;
        if(code2 > code1)
            return -1;
    }
    if(entry1.stdName[i] != '\0')
        return 1;
    if(entry2.stdName[i] != '\0')
        return -1;
    return 0;
}
//*******************************************************************************************************************************
void display(data entry)                //Displays name, surname and tel of entry, NOT node
{
    printf("Nazwa gatunkowa: ");
    puts(entry.stdName);
    printf("Nazwa lacinska: ");
    puts(entry.latinName);
    printf("Rodzina: ");
    puts(entry.rodzina);
    printf("Rodzaj: ");
    puts(entry.rodzaj);
    return;
}
//*******************************************************************************************************************************
void fDisplay(node *root)               //Displays whole tree in-order (alphabetically)
{
    if(root != NULL)
        {
            fDisplay(root->left);
            display(root->entry);
            printf("\n");
            fDisplay(root->right);
        }
    return;
}
