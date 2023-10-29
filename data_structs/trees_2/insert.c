/*
    Functions that add new nodes to a SUBTREE.
    Obs.: The subtrees are not explicit implemented, what there's is a binary tree that point to a root that has childs.
*/

#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

tree_node* create_tree_node(tree_node** parent, int given_value)
{
  /*
    Creates a new node by allocating dinamic memory to it.

    Parameters:
        parent: the existent node where the new node will be attached to as a child.
        given_value: the value that will be stored in the inserted node. 
  */

  tree_node* tmp = (tree_node *)calloc(1, sizeof(tree_node));

  tmp->parent = (*parent);
  tmp->value = given_value;
  
  return tmp;
}


void subtree_insert_after(tree_node** given_node, int new_value)
{   
    /*
        This function inserts a new node after the given node in traversal order.

        Parameters:
            given_node: the node where the new node will be inserted after.
            new_value: the value that will be inserted on the new node.
    */

    //add the new_node after the given node in traversal order.
    if ((*given_node)->right == NULL)
    {
        (*given_node)->right = create_tree_node(&(*given_node), new_value);
    }
    else
    {   
        tree_node* subtree_first_node =  sucessor(&(*given_node));
        
        subtree_first_node->left = create_tree_node(&subtree_first_node, new_value);
    }
}



void subtree_insert_before(tree_node** given_node, int new_value)
{   
    //add the new_node after the given node in traversal order.
    if ((*given_node)->left == NULL)
    {
        (*given_node)->left = create_tree_node(&(*given_node), new_value);
    }
    else
    {   
        tree_node* subtree_first_node =  predecessor(&(*given_node));
        subtree_first_node->right = create_tree_node(&subtree_first_node, new_value);
    }
}
