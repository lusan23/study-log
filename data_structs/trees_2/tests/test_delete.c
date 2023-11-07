#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"../tree.h"
#include"test.h"

void test_delete(void)
{
    binary_tree* t;
    malloc_binary_tree(&t, 3);
    subtree_insert_after(&t->root, 100);
    subtree_insert_before(&t->root, 600);
    subtree_insert_after(&t->root->left, 326);
    subtree_insert_after(&t->root->right, 521);
    subtree_insert_before(&t->root->right, 666);

    //THIS IS NOT A BINARY SEARCH TREE!!! Here the values still doesn't matter.
    /*
                3          root.size =   root.right.size + 1;         
               /  \
             666    100    root.right.size = root.right.left.size + root.right.right.size + 1 
               \    /  \
                \  666   \    0
                 326      521 0

      root.size == 4          | 2
      root.right.sze = 3      | 1
         
                   
    */

    //Delete leaf case.
    subtree_delete(&t->root);
    subtree_delete(&t->root);
    subtree_delete(&t->root);
    subtree_delete(&t->root);
    subtree_delete(&t->root);
    subtree_delete(&t->root);
    printf("finally done!!!");
    
    free_tree(&t);
}
