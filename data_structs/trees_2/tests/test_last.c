#include<stdio.h>
#include<stdlib.h>
#include"test.h"
#include"../tree.h"
#include<assert.h>

void test_last(void)
{
    binary_tree* t;
    malloc_binary_tree(&t, 5);

    assert(subtree_last(&t->root) == t->root);

    t->root->left = create_tree_node(&t->root, 4);
    t->size++;

    tree_node* last_node = subtree_last(&t->root);
    assert(last_node == t->root);
    
    t->root->right = create_tree_node(&t->root, 6);
    t->size++;

    assert(subtree_last(&t->root) == t->root->right);

    assert(subtree_last(&t->root->right) == t->root->right);
    

}