#include<stdio.h>
#include<stdlib.h>
#include"../tree.h"
#include"test.h"

void test_insert(void)
{
    binary_tree* t;
    malloc_binary_tree(&t, 50);

    subtree_insert_after(&t->root,70);
    subtree_insert_before(&t->root, 30);

     subtree_insert_after(&t->root->left, 12);

    subtree_insert_after(&t->root->right,21);
    subtree_insert_before(&t->root->right, 234);



    free_tree(&t);
}
