/*
    Darin Brezeale
    CSE 1320, hw #11
    Mon Apr 14 21:27:26 CDT 2014

    construct binary tree of words
*/

#include <stdio.h>
#include <stdlib.h>
#include "hw11-lib.h"

int main(void)
{
    struct node *root;
    root = readData();

    printf("\nRESULTS\n");
    printTree(root);
    freeMem(root);

    return 0;
}

