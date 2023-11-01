#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include"../tree.h"
#include"test.h"

void test_first(void)
{
    binary_tree* t;
    malloc_binary_tree(&t, 5);

    assert(subtree_first(&t->root) == t->root);

    t->root->left = create_tree_node(&t->root, 4);

    assert(subtree_first(&t->root) == t->root->left);
    
    t->root->right = create_tree_node(&t->root, 6);


    assert(subtree_first(&t->root) == t->root->left);

    assert(subtree_first(&t->root->right) == t->root->right);
    

}