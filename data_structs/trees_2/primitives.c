#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

tree_node* create_tree_node(tree_node** parent, int given_value)
{
  tree_node* tmp = (tree_node *)calloc(1, sizeof(tree_node));

  tmp->parent = (*parent);
  tmp->value = given_value;
  
  return tmp;
}


void malloc_binary_tree(struct binary_tree **bt, int first_value)
{//creates heaps on memory for the tree, the root node and its node.
  (*bt) = (binary_tree *)calloc(1,sizeof(binary_tree));
  (*bt)->root = (tree_node *)calloc(1,sizeof(tree_node));
  (*bt)->root->value = first_value;
  
  if ((*bt) != NULL && (*bt)->root != NULL)
    {
      printf("allocation succeed.\n");
    }
    else
    {
      printf("allocation failed.\n");   
      return;
    }

}


  tree_node* recursive_free(tree_node** root)
{
  //free all the nodes recursively.
  if ((*root) == NULL)
  { //base case
    return (*root);
  }
  else
  { //recursive calls
    recursive_free(&((*root)->right));
    recursive_free(&((*root)->left));
    free((*root));
  }
  
}

void free_tree(binary_tree** tree)
{ //free the allocated heaps and set the pointer to NULL

    recursive_free(&(*tree)->root);
    (*tree)->root = NULL;
    free((*tree));
     
}
