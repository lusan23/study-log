#include<stdio.h>
#include<stdlib.h>
#include"../tree.h"

tree_node* subtree_find(tree_node** given_node, int given_value, bool static_mode)
{   
    /*
    //THIS FUNCTION IS MEANT TO WORK IN A BINARY WHERE TRAVERSAL ORDER == SEQUENTIAL ORDER 
        Returns the tree node that contains the given value on the given subtree.
        
        Parameters:
        - given_node: pointer to the root of the subtree
        - given_value: value to be searched for

         - static_mode: It's a flag for when subtree_find() is called inside bst_insert() function.
            if is true it will return the a leaf node, so bst_insert() can create a child or overwrite it.
            if is false it has the possibility to return a NULL value.
    */
    if (static_mode) 
    {
        if (is_leaf(&(*given_node)))
        {
            return (*given_node);    
        }
    }
    else
    {
        if ((*given_node) == NULL)
            {
                printf("Value not found!!\n");
                return NULL;
            }
    }

    //traversal order
    if (given_value < (*given_node)->value)
    {
        subtree_find(&(*given_node)->left, given_value, static_mode);
    }
    else if ((*given_node)->value == given_value)
    {
        return (*given_node);
    } 
    else if (given_value > (*given_node)->value )
    {
        subtree_find(&(*given_node)->right, given_value, static_mode);
    }
    
}