
/*
    Set of functions that affect the whole tree.

    to make the binary tree possible it's needed to make the traversal order == incresing key so function to insert before or after depending on the key value is necessary.

    if new_key >= given key.
        insert after
    else 
        insert before
*/

#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include"trees.h"

void insert(binary_tree** tree, int new_value)
{   //it goes down the tree until hit a leaf, that add it before or after the leaf depending of its value
    printf("------------starting global insert operations...-----------\n");
    if (alloc_succeed((*tree)->root))
    {
        tree_node* current_node = (*tree)->root;

        //root node case. deciding which subtree it should go, left or right. 
        if (current_node != NULL)
        {
            if (current_node->value <= new_value)
            {
                if (current_node->right != NULL) {current_node = current_node->right;}              
            }
            else
            {
                if (current_node->left != NULL) {current_node = current_node->left;} 
            }

            
            //child nodes case
            while (current_node->left != NULL && current_node->right  != NULL)
            {
                if (current_node->value <= new_value)
                {
                    if (current_node->right != NULL) {current_node = current_node->right;}  
                }
                else
                {
                    if (current_node->left != NULL) {current_node = current_node->left;}  
                }
            }
            
            if (current_node->value <= new_value)
            {
                printf("new value greater than current\n");
                subtree_insert_after(&(*tree), &current_node, new_value);
            }
            else
            {   printf("new value lower than current\n");
                subtree_insert_before(&(*tree), &current_node, new_value);
            }   
        }
       

   
    } 
    else
    {
        printf("Empty tree!!! You may use ´malloc_binary_tree´.\n");
    }
    printf("------------end-----------\n");

}