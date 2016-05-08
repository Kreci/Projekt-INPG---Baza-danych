#ifndef DATA_H
#define DATA_H
#define LENGTH 20

typedef struct note // data structure
{
    char stdName[LENGTH];
    char latinName[LENGTH];
}data;

typedef struct junction //node structure
{
    data entry;
    struct junction* left;
    struct junction* right;
}node;

int compare(data, data); // compares entries
void display(data); 	 // displays entry
void fDisplay(node*);    // displays whole tree
void findMin(node*);	 // displays first (alphabetically) entry
void findMax(node*); 	 // displays last (alpabetically) entry
int browse_tree(node *head)       //Umożliwia chodzenie po drzewie galez po galezi

#endif
