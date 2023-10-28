#include<stdio.h>
#include<stdlib.h>
#include"tree.h"


void swap_nodes(tree_node** node_src, tree_node** node_dest)
{
    /*
        It don't actually swap the node structure, but only its values.
        Meant for swaping predecessor/sucessors with a given node. 
    */
    int tmp = (*node_dest)->value;
    (*node_dest)->value = (*node_src)->value;
    (*node_src)->value = tmp;
}

void subtree_delete(tree_node** given_node)
{
    /*
        Delete a leaf, if the given node it's not a leaf 
            make it a leaf(recursively) and delete it.

        //Base Case
    */
    if(is_leaf(&(*given_node)))
    {
        free((*given_node));
        //the freed flag is implemented to handle the double free exception.
        (*given_node)->is_freed = 1;
        (*given_node) = NULL;
        
        
    }
    else
    {   
        //If the given node is in the left side of the subtree.
        if ((*given_node)->left)
        {
            tree_node* prdcsr = predecessor(&(*given_node));
            swap_nodes(&(*given_node), &prdcsr);
            subtree_delete(&prdcsr);
        }

        //If the given node is in the right side of the subtree...
        else if ((*given_node)->right)
        {
            tree_node* scsr = sucessor(&(*given_node));
            swap_nodes(&(*given_node), &scsr);
            subtree_delete(&scsr);
        }
        
    }
}