#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "inserter.h"
#include "creator.h"

int main( void ) 
{
    node *root = NULL;
    addNodes(&root);
    fDisplay(root);
    return 0;
}