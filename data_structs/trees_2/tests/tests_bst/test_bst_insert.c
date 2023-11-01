#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../../tree.h"
#include"test_bst.h"
#include<stdlib.h>

void test_bst_insert(void)
{
    printf(".............test bst insert by key .............\n");
    binary_tree* t;
    malloc_binary_tree(&t, 50);

    bst_subtree_insert(&t->root, 30);

    bst_subtree_insert(&t->root, 80);

    // RANDOM TEST
    printf("Starting random insert test...\n");
    for (int i = 0; i < 5; i++)
    {
        int j = rand() % 100;
        bst_subtree_insert(&t->root, j);
     
    }
    
    
    free_tree(&t);
    
}