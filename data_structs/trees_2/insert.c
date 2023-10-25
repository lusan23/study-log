#include<stdio.h>
#include<stdlib.h>
#include"tree.h"


void subtree_insert_after(tree_node** given_node, tree_node** new_node)
{   
    //add the new_node after the given node in traversal order.
    if ((*given_node)->right == NULL)
    {
        (*given_node)->right = (*new_node);
    }
    else
    {   
        tree_node* subtree_first_node =  sucessor((*given_node)->left);
        subtree_first_node = (*given_node);
    }
}



void subtree_insert_after(tree_node** given_node, tree_node** new_node)
{   
    //add the new_node after the given node in traversal order.
    if ((*given_node)->left == NULL)
    {
        (*given_node)->left = (*new_node);
    }
    else
    {   
        tree_node* subtree_first_node =  predecessor((*given_node)->right);
        subtree_first_node = (*given_node);
    }
}
