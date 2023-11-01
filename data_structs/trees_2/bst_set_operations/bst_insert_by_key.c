/*
    Functions designed to create a SET squence of binary by using its key. 
*/
#include<stdio.h>
#include<stdlib.h>
#include"../tree.h"



void bst_subtree_insert(tree_node** given_node, int new_value)
{
    /*
        This function can insert elements and create an actual binary search tree
        (what it does is take the tree concept to represent a set. )
        following these rules:
        1. every

        Parameters:
            given_node: the subtree's root where the search starts.
            new_value: the data that will inserted in the binary tree.
                if there's already data with the same value it will be overwriten.
    */
    tree_node * found_node = subtree_find_key(&(*given_node), new_value, true);
    if (found_node->value > new_value)
    {
        found_node->left = create_tree_node(&found_node, new_value);
        update_size(&found_node->left, false);
        
    }else if (found_node->value < new_value)
    {
        found_node->right = create_tree_node(&found_node, new_value);
        update_size(&found_node->right, false);
    } else
    {
        found_node->value = new_value;
    }
    
     
    printf("insert into subtree with new value %d\n", new_value);
}