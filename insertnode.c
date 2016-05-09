void insertNode(node **root, data* input)                                        //Funkcja wstawia wezel w odpowiednie miejsce drzewa
    {
        node *new_node = createNode();                       //Potrzebna funkcja createNode() alokujaca pamiec nowego elementu
        node *temp = NULL;                                   //i wypelniajaca go odpowiednimi danymi (obsluga pliku)

        if(*root == NULL)
            {
                *root = new_node;
                return;
            }

        temp = *root;
        while(temp != NULL)
            {
                if(compare(new_node->entry, temp->entry) == -1)
                    {
                        if(temp->left != NULL)
                            temp = temp->left;
                        else
                            break;
                    }
                else if(compare(new_node->entry, temp->entry) == 1)
                    {
                        if(temp->right != NULL)
                            temp = temp->right;
                        else
                            break;
                    }
                else
                    {
                        printf("Ten rekord juz istnieje\n");
                        return;
                    }
            }
        if(compare(new_node->entry, temp->entry) == -1)
            temp->left = new_node;
        else if(compare(new_node->entry, temp->entry) == 1)
            temp->right = new_node;
        return;
    }
