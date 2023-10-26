#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../../tree.h"
#include"test.h"

void test_find(void)
{
    binary_tree* t;
    //NOT BST FUNCTIONS.
    malloc_binary_tree(&t, 50);
    subtree_insert_after(&t->root, 70);
    subtree_insert_before(&t->root, 25);
    subtree_insert_after(&t->root->left, 40);
    subtree_insert_after(&t->root->right, 100);
    subtree_insert_before(&t->root->right, 60);
    subtree_insert_before(&t->root->left, 10);
    // BINARY SEARCH TREE
    /*
                 50                 
               /  \
             25     70
            /  \    /  \
          /     \  60  \
         10      40     100
                    
                   
    */

   //test cases
   tree_node* tree = subtree_find(&t->root, 50);
   tree_node* node_key_one = subtree_find(&t->root, 10);
   tree_node* node_key_hundred = subtree_find(&t->root, 100);
   tree_node* none = subtree_find(&t->root, 12800);

   
}