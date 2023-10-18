
/*
    Set of functions that affect the whole tree.

    to make the binary tree possible it's needed to make the traversal order == incresing key so function to insert before or after depending on the key value is necessary.

    if new_key >= given key.
        insert after
    else 
        insert before
*/

#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include"trees.h"

void insert(binary_tree** tree, int new_value)
{   
    printf("------------starting global insert operations...-----------\n");
    if (alloc_succeed((*tree)->root))
    {
        tree_node* root = (*tree)->root;
        tree_node* last_node = subtree_last(root);

        printf("isert global func: last_node:%d\n", last_node->value);
        if (new_value >= last_node->value)
        {   
            printf("after was choosen...\n");
            subtree_insert_after(&(*tree), &last_node, new_value);
        }
        else
        {
            printf("before was choosen...\n");
            subtree_insert_before(&(*tree), &last_node, new_value);
        }
    } 
    else
    {
        printf("Empty tree!!! You may use ´malloc_binary_tree´.\n");
    }
    printf("------------end-----------\n");

}