#include<stdio.h>
#include"tree.h"



 tree_node* subtree_first(tree_node** given_node)
{
    if ((*given_node) == NULL)
    {
        return NULL;
    }
    tree_node* current_node = (*given_node);

    while (current_node->left != NULL)
    {
        current_node = current_node->left;
    }

    return current_node;
}

 tree_node* subtree_last(tree_node** given_node)
{
    if ((*given_node) == NULL)
    {
        return NULL;
    }
    tree_node* current_node = (*given_node);

    while (current_node->right != NULL)
    {
        current_node = current_node->right;
    }

    return current_node;
}


tree_node* sucessor(tree_node** given_node) 
{   //Return the sucessor node in traversal order or NULL if the given is the last node.
    tree_node* current_node = (*given_node);

    if (current_node == NULL)
    {
        return NULL;
    }

    if (current_node->right)
    {
        return subtree_first(&current_node->right);
    }
    else
    {
        tree_node* parent = current_node->parent;
        while (parent != NULL && parent->right == current_node)
        {
            current_node = parent;
            parent = parent->parent;
        }

        if (parent != NULL)
        {
            return parent;
        }
        else
        {
            return NULL; // If there is no successor
        }
    }
}
