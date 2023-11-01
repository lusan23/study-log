/*
    Functions designed to create a SET squence of binary by using its key. 
*/
#include<stdio.h>
#include<stdlib.h>
#include"../tree.h"



void bst_subtree_insert_sequence(tree_node** given_node, int new_value)
{
    /*
        This function can insert elements and create an actual binary search tree sequence
  

        Parameters:
            given_node: the subtree's root where the search starts.
            new_value: the data that will inserted in the binary tree in sequence
    */
    if (!(*given_node)->left && !(*given_node)->right)
    {
        
    }
     
    printf("insert into subtree with new value %d\n", new_value);
}