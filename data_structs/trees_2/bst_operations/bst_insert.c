#include<stdio.h>
#include<stdlib.h>
#include"../tree.h"

void bst_subtree_insert(tree_node** give_node, int new_value)
{
    if (new_value >= (*give_node)->value) 
    {
        subtree_insert_after(&(*give_node), new_value);
    }
    else
    {
        subtree_insert_before(&(*give_node), new_value);
    }
}