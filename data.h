#ifndef DATA_H
#define DATA_H
#define LENGTH 40

typedef struct note // data structure
{
    char stdName[LENGTH];
    char latinName[LENGTH];
    char rodzina[LENGTH];
    char rodzaj[LENGTH];
}data;

typedef struct junction //node structure
{
    data entry;
    struct junction* left;
    struct junction* right;
}node;

int compare(data, data); // compares entries zwraca 1 jeżęli pierwsza jest większa, -1 jeśli druga, 0 jeśli są równe. Porównuje po stdName
void display(data); 	 // displays entry
void fDisplay(node*);    // displays whole tree

#endif
