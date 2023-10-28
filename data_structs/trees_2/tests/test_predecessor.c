#include<stdio.h>
#include<stdlib.h>
#include"test.h"
#include"../tree.h"
#include<assert.h>

void test_predecessor(void)
{

    binary_tree* t;
    malloc_binary_tree(&t, 5);

    t->root->left = create_tree_node(&t->root, 4);
    t->size++;

    t->root->right = create_tree_node(&t->root, 7);
    t->size++;
    
    assert(predecessor(&t->root->left) == NULL);
    assert(predecessor(&t->root) == t->root->left);
    assert(predecessor(&t->root->right) == t->root);
    

}