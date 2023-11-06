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

        Delete Cases:
            1 - the given node is a leaf - so it will be easily removed 
            (it might get random values afer freed).
                1.2 - when a node is deleted it sets a deleted frag as true, 
                so when we use free_tree()it won't cause a double free error.

            2 - the given node is not a leaf - Its value will be swaping 
            with its predecessor/sucessor (depending on what side of the 
            root the given node is.)

    //Base Case
    */
    if(is_leaf(&(*given_node)))
    {   tree_node* parent = (*given_node)->parent;
        printf("node value:%d\n", (*given_node)->value);
        (*given_node)->size = 0;
        (*given_node)->height = 0;
        (*given_node)->value = 0;
        
        (*given_node)->is_freed = 1;
        (*given_node)->value = 0;
        update_properties(&parent, true);

        //unlink the given node from its parent
        // if (parent->left == (*given_node))
        // {
        //     parent->left = NULL;
        // }
        // else if (parent->right == (*given_node))
        // {
        //     parent->right = NULL;
        // }
        //the freed flag is implemented to handle the double free exception.

        free((*given_node));
        
      
        
    }
    else
    {   
        //If the given node is in the left side of the subtree.
        if ((*given_node)->left && !(*given_node)->left->is_freed)
        {
            tree_node* prdcsr = predecessor(&(*given_node));
            swap_nodes(&(*given_node), &prdcsr);
            subtree_delete(&prdcsr);
        }

        //If the given node is in the right side of the subtree...
        else if ((*given_node)->right && !(*given_node)->right->is_freed)
        {
            tree_node* scsr = sucessor(&(*given_node));
            swap_nodes(&(*given_node), &scsr);
            subtree_delete(&scsr);
        }
        
    }
}