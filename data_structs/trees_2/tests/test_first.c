#include<stdio.h>
#include<stdlib.h>
#include"test.h"
#include"../tree.h"
#include<assert.h>
void test_first(void)
{
    binary_tree* t;
    malloc_binary_tree(&t, 5);

    assert(subtree_first(&t->root)->value == 5);

    t->root->left = (tree_node*)calloc(1, sizeof(tree_node));

    t->root->left->value = 4;
    t->root->left->parent = t->root;
    t->size++;

    assert(subtree_first(&t->root)->value == 4);
    
    t->root->right = (tree_node*)calloc(1, sizeof(tree_node));

    t->root->right->value = 6;
    t->root->right->parent = t->root;
    t->size++;

    assert(subtree_first(&t->root)->value == 4);
    

}