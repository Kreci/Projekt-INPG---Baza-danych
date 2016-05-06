void findRecord(node *root)
    {
        data input;

        if(root == NULL)
            {
                printf("Drzewo jest puste!\n");
                return;
            }
        printf("Podaj nazwe zwyczajowa\n");
        scanf("%s", input.stdName);

        while(root != NULL)
            {
                if(compare(root->entry, input) == -1)
                    root = root->left;
                else if(compare(root->entry, input) == 1)
                    root = root->right;
                else
                    {
                        display(root->entry);
                    }
            }
        printf("Nie znaleziono szukanego gatunku\n");
        return;
    }
