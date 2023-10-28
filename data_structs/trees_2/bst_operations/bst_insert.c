#include<stdio.h>
#include<stdlib.h>
#include"../tree.h"



void bst_subtree_insert(tree_node** given_node, int new_value)
{
    tree_node * found_node = subtree_find(&(*given_node), new_value, true);
    found_node = create_tree_node(&found_node->parent, new_value); 
    printf("insert into subtree with new value %d\n", new_value);
}