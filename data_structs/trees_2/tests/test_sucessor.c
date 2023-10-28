#include<stdio.h>
#include<stdlib.h>
#include"test.h"
#include"../tree.h"
#include<assert.h>


void test_sucessor(void)
{
    binary_tree* t;
    malloc_binary_tree(&t, 5);

    t->root->left = create_tree_node(&t->root, 4);
    t->size++;

    t->root->right = create_tree_node(&t->root, 6);
    t->size++;

    assert(sucessor(&t->root->left) == t->root);
    assert(sucessor(&t->root) == t->root->right);
    assert(sucessor(&t->root->right) == NULL);

}