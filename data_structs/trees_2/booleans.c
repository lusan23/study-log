/*
    Functions for checking the current state of a given node.
*/
#include<stdio.h>
#include"tree.h"
#include<stdbool.h>


bool max_equal(unsigned int a, unsigned int b)
{
    return (a >= b) ? true : false;
}

bool is_leaf(tree_node** given_node)
{
    /*
        Verifies if a given node is a leaf.
        
        it verifies not only if childs has NULL but also if their children were freed or not.
    */
    return ((*given_node)->parent != NULL && (((*given_node)->left == NULL || (*given_node)->left->is_freed) && ((*given_node)->right == NULL) || (*given_node)->right->is_freed)) ? true : false;
}