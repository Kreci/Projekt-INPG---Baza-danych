#ifndef DATA_H
#define DATA_H
#define LENGTH 20
#define DSCRPTN_L 200

typedef struct note // data structure
{
    char stdName[LENGTH];
    char latinName[LENGTH];
    char rodzina[LENGTH];
    char rodzaj[LENGTH];
    char opis[DSCRPTN_L];
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
void findRecord(node*);     //wyszukuje element o zadanej nazwie gatunkowej
void insertNode(node**);    //wstawia wezel w odpowiednie miejsce w drzewie
int nodeNumber(node *);     //zwraca ilosc elementow w drzewie
node* createNode(data*);     //zwraca nowy element wypełniony danymi

#endif
