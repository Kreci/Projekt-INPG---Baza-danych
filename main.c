#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "tree.h"
#include "menu.h"
#include "baza.h"

int main(void)
{
    node *root = NULL;
    menu(root);
    freeMem(root);
    return 0;
}
