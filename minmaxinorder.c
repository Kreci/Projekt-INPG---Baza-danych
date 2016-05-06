void findMin(node*)
    {
        if(node == NULL)
            {
                printf("Drzewo jest puste!\n");
                return;
            }
        if(node->left != NULL)
            return findMin(node->left);
        else
            printf("Pierwszy rekord to %s\n", node->entry.stdName);
        return;
    }

void findMax(node*)
    {
        if(node == NULL)
            {
                printf("Drzewo jest puste!\n");
                return;
            }
        if(node->right != NULL)
            return findMax(node->right);
        else
            printf("Ostatni rekord to %s\n", node->entry.stdName);
        return;
    }
