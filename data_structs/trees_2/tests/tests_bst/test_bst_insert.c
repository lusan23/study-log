#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../../tree.h"
#include"test.h"

void test_bst_insert(void)
{
    binary_tree* t;
    malloc_binary_tree(&t, 50);

    bst_subtree_insert(&t->root, 30);

    bst_subtree_insert(&t->root, 80);
    
}