#include<stdio.h>
#include<stdlib.h>
#include"../tree.h"

void add_size(tree_node** given_node)
{
    /*

        given_node is meant to be a recent created node. 
        this function updates the size of every ancestor node of the given node.

    */
    tree_node* current_node = (*given_node)->parent;

    tree_node* prev_node = (*given_node);                                                            
    while (current_node->parent != NULL)
    {
        //if the given node parents has two childs...    
        current_node = current_node->parent;
        current_node->size += prev_node->size + 1;
        prev_node = current_node;
        
        
    }
}