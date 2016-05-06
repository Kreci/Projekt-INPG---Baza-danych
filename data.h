#ifndef DATA_H
#define DATA_H
#define LENGHT 20
typedef struct note // data structure
{
    char stdName[LENGHT];
    char latinName[LENGHT];
}data;
typedef struct junction //node structure
{
    data entry;
    struct junction* left;
    struct junction* right;
}node;
int compare(data, data); // compares entries
void display(data); // displays entry
void fDisplay(node*);   //displays whole tree
#endif
