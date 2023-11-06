/*
    Functions for checking the current state of a given node.
*/
#include<stdio.h>
#include"tree.h"
#include<stdbool.h>


unsigned int max_equal(unsigned int a, unsigned int b)
{
    return (a >= b) ? a : b;
}

bool is_leaf(tree_node** given_node)
{
    /*
        Verifies if a given node is a leaf.
        
        it verifies not only if childs has NULL but also if their children were freed or not.
    */
    bool has_parent =false;
    bool has_left = false;
    bool has_right = false;

    if ((*given_node)->parent != NULL)
    {
        has_parent = true;
    }

    if ((*given_node)->left != NULL)
    {
        has_left = true;
        if ((*given_node)->left->is_freed == 1)
        {
            has_left = false;
        }
    }

    if ((*given_node)->right != NULL)
    {
        has_right = true;
        if ((*given_node)->right->is_freed == 1)
        {
            has_right = false;
        }
    }
    return (has_parent && !has_left && !has_right) ? true : false;
}

bool is_root(tree_node** given_node)
{
    /*
        Verifies if a given node is the root.
        
        it verifies not only if the children have NULL value, but also if their children were freed or not.
    */
    return ((*given_node)->parent == NULL && (((*given_node)->left == NULL || (*given_node)->left->is_freed) && ((*given_node)->right == NULL) || (*given_node)->right->is_freed)) ? true : false;
}
