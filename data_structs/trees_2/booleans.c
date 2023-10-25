/*
    Functions for checking the current state of a given node.
*/
#include<stdio.h>
#include"tree.h"
#include<stdbool.h>

bool is_leaf(tree_node** given_node)
{
    return ((*given_node)->parent != NULL && (*given_node)->left == NULL && (*given_node)->right == NULL) ? true : false;
}