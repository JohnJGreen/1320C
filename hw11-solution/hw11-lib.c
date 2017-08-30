#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw11-lib.h"

struct node* readData( void )
{
    char buffer[1000];
    char *token, *del = " \n";
    struct node* root = NULL;

    while( fgets(buffer, sizeof(buffer), stdin) != NULL )
    {
        token = strtok(buffer, del);
        while(token != NULL)
        {
            /*printf("%s\n", token);*/
            if(root == NULL)
            {
                printf("add: %s\n", token);
                root = addNode(token);
            }
            else
                insert(root, token);

            token = strtok(NULL, del);
        }
    }

    return root;
}


struct node* addNode(char *word)
{
    struct node *temp = malloc(sizeof(struct node));

    temp->word = malloc( strlen(word) + 1 );
    strcpy(temp->word, word);
    temp->count = 1;
    temp->left = NULL;
    temp->right = NULL;


    return temp;
}


void insert(struct node *root, char* word)
{
    if( strcmp(word, root->word) == 0 )
    {
        printf("updating count: %s\n", word);
        root->count += 1;
    }
    else if( strcmp(word, root->word) < 0 )
    {
        if(root->left == NULL)
        {
            printf("left add: %s\n", word);
            root->left = addNode(word);
        }
        else
        {
            printf("going left\n");
            insert(root->left, word);
        }
    }
    else
    {
        if(root->right == NULL)
        {
            printf("right add: %s\n", word);
            root->right = addNode(word);
        }
        else
        {
            printf("going right\n");
            insert(root->right, word);
        }
    }
}


void printTree(struct node* root)
{
    if(root == NULL)
        return;

    printTree(root->left);
    printf("%s, %d\n", root->word, root->count);
    printTree(root->right);
}


void freeMem(struct node* root)
{
    if(root == NULL)
        return;

    freeMem(root->left);
    freeMem(root->right);
    free(root->word);
    free(root);
}
