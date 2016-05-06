void findMin(node* root)
    {
        if(root == NULL)
            {
                printf("Drzewo jest puste!\n");
                return;
            }
        if(root->left != NULL)
            return findMin(root->left);
        else
            printf("Pierwszy rekord to %s\n", root->entry.stdName);
        return;
    }

void findMax(node* root)
    {
        if(root == NULL)
            {
                printf("Drzewo jest puste!\n");
                return;
            }
        if(root->right != NULL)
            return findMax(root->right);
        else
            printf("Ostatni rekord to %s\n", root->entry.stdName);
        return;
    }
