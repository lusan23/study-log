#include<stdio.h>
#include<stdlib.h>
#include"../tree.h"

tree_node* recursion_find_ith(tree_node** given_node, unsigned int ith)
{   
    /*
    This function applies a sequence of each node on the subtree
        traversal order == sequence order 

        Returns the ith node of the given search tree.
        
        Parameters:
        - given_node: it should be the pointer to the root of the subtree
        - ith: value to be searched for
    */
   //this is for when there's no room to go down anymore.


   if ((is_leaf(&(*given_node))))
   {
        return (*given_node);
   } 
   

   unsigned int size_left_node;

   if ((*given_node)->left){

    size_left_node = (*given_node)->left->size;
   }else { 
    size_left_node = 0;}

    if (ith == size_left_node) { return (*given_node);}
    if (ith < size_left_node) { recursion_find_ith(&(*given_node)->left, ith);}
    else if (ith > size_left_node) { recursion_find_ith(&(*given_node)->right, ith - size_left_node - 1);}


}

tree_node* subtree_find_ith(tree_node** given_node, unsigned int ith)
{
    /*
        This function work is a filte to handle exceptions
    */
    if (!(*given_node)) 
   {      
        printf("this subtree is empty subtree!!!\n");
        return NULL;
   }

    unsigned int size_left_node = (*given_node)->left->size;
    if (ith > (*given_node)->size){
        
        printf("%d is out of indexes range!!!\n", ith); return NULL;
    }

    tree_node* node =  recursion_find_ith(&(*given_node), ith);

    return node;
}
