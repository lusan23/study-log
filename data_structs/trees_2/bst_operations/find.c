#include<stdio.h>
#include<stdlib.h>
#include"../tree.h"

tree_node* subtree_find(tree_node** given_node, int given_value)
{   //THIS FUNCTION IS MEANT TO WORK IN A BINARY WHERE TRAVERSAL == 
    //Returns the tree node that contains the given value on the given subtree.
    if ((*given_node) == NULL)
    {
        printf("Value not found!!\n");
        return NULL;
    }
    //traversal order
    if (given_value < (*given_node)->value)
    {
        subtree_find(&(*given_node)->left, given_value);
    }
    else if ((*given_node)->value == given_value)
    {
        return (*given_node);
    } 
    else if (given_value > (*given_node)->value )
    {
        subtree_find(&(*given_node)->right, given_value);
    }
    
}