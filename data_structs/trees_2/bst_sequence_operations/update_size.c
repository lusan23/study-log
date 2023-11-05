#include<stdio.h>
#include<stdlib.h>
#include"../tree.h"
#include<stdbool.h>

void update_size(tree_node** given_node, bool del_mode)
{
    /*

    this function updates the size of every ancestors of the given node in insertions and deletions.

    Parameters:
        given_node:
        - when adding a node the new leaf must be 'given_node'
        - when DELETING a node the parent of the deleted node must be 'given_node'
    
        del_mode - it must be set to 'true' when this function is being used 
        in the delete node func.
    */
    if (!(*given_node)) {printf("The given node is empty!!!\n"); return; }
    tree_node* ancestor_node = (*given_node)->parent;
    if (del_mode)
    {
        
        ancestor_node = (*given_node);
    }
    //properties of a leaf
    (*given_node)->size = 1;
    (*given_node)->height = 0;
    
    
    while (ancestor_node != NULL)
    {   //node.size = node.left.size + node.right.size + 1
        int childrens_size = 0;
        int left_height = 0, right_height = 0;
        //if the given node parents has two childs...    

        if (ancestor_node->left )
        {
            if (ancestor_node->left->is_freed != 1)
            {
                childrens_size += ancestor_node->left->size;
                left_height = ancestor_node->left->height;
            }
        }
        if (ancestor_node->right)
        {
            if (ancestor_node->right->is_freed != 1)
            {
                childrens_size += ancestor_node->right->size;
                right_height = ancestor_node->right->height;
            }
        }
        ancestor_node->size = childrens_size + 1;
        ancestor_node->height = max_equal(left_height,right_height) + 1;
        if (is_leaf(&ancestor_node)) {ancestor_node->height--;}
        if (is_root(&ancestor_node)) {ancestor_node->height= 0;}
        
        ancestor_node = ancestor_node->parent;
        
    }


}