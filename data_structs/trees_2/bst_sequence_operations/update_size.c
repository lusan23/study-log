#include<stdio.h>
#include<stdlib.h>
#include"../tree.h"
#include<stdbool.h>
void update_size(tree_node** given_node, bool del_mode)
{
    /*

    given_node is meant to be a recent created node. 
    this function updates the size of every ancestor node of the given node.

    Parameters:
        given_node:
        - when adding a node the new leaf must be 'given_node'
        - when deleting a node the parent of the deleted node must be 'given_node 
    
        del_mode - it must be set to 'true' when this function is being used 
        in the delete node func.
    */
    if (!(*given_node)) {printf("The given node is empty!!!\n"); return; }

    if (!del_mode)
    {
        (*given_node)->size = 1;
    }

    tree_node* ancestor_node = (*given_node)->parent;

    while (ancestor_node != NULL)
    {   //node.size = node.left.size + node.right.size + 1
        int childrens_size = 0;
        //if the given node parents has two childs...    
        if (ancestor_node->left)
        {
            childrens_size += ancestor_node->left->size;
        }
        if (ancestor_node->right)
        {
            childrens_size += ancestor_node->right->size;
        }

        ancestor_node->size = childrens_size + 1;
        ancestor_node = ancestor_node->parent;
        
    }


}