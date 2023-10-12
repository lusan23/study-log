/*
implementation of a binary tree based on this lesson: 
https://www.youtube.com/watch?v=76dhtgZt38A&list=PLUl4u3cNGP63EdVPNLG3ToM6LaEUuStEY&index=10

DEVELOPMENT NOTE FOR TOMORROW:
TO MAKE INSERT_BEFORE I NEED TO MAKE PREDECESSOR* AND SUBTREE_LAST*
TOMORROW FIX THE PRINTALL
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"trees.h"
#include<assert.h>


void malloc_binary_tree(struct binary_tree **bt, int first_value)
{//creates heaps on memory for the tree, the root node and its node.
  (*bt) = (binary_tree *)calloc(1,sizeof(binary_tree));
  (*bt)->root = (tree_node *)calloc(1,sizeof(tree_node));
  (*bt)->root->value = first_value;
  
  if (*bt != NULL && alloc_succeed((*bt)->root))
    {
      printf("allocation succeed.\n");
    }
    else
    {
      printf("allocation failed.\n");   
    }

}
void free_tree(binary_tree** tree)
{ //free the allocated heaps and set the pointer to NULL
    
    recursive_free(&(*tree)->root);
    (*tree)->root = NULL;
    free((*tree));
    (*tree)->root = NULL;
    
}

void subtree_insert_after(binary_tree** tree, tree_node** entry_node, int new_value)
{//add another after entry node in the in-order tranversal of the tree
  
  if (!(*entry_node)->right)
  { 
    printf("case one\n");
    (*entry_node)->right = (tree_node *)calloc(1, sizeof(tree_node));
    (*entry_node)->right->value = new_value;
    (*entry_node)->right->parent = (*entry_node);
    assert((*entry_node)->right->parent->value == (*entry_node)->value);
    (*tree)->size++;
  }
  else
  { 
    printf("case two\n");
    tree_node * scsr =  sucessor((*entry_node)); 
    scsr->left = (tree_node *)calloc(1, sizeof(tree_node));

    scsr->left->value = new_value;
    scsr->left->parent = scsr;
    assert(scsr->left->value == new_value);
    assert(scsr->left->parent->value ==scsr->value);
    (*tree)->size++;
  }
}


/*
void swap_prescr_node(tree_node** node)
{
     tree_node* tmp_node = (*tree)->left;
    (*to_be_deleted_node)->left = (*to_be_deleted_node);
    (*to_be_deleted_node) = tmp_node;
}
*/
tree_node* subtree_delete(struct tree_node** to_be_deleted_node)
{
  /* a leaf node == having a parent and no childs.
  a recursion function that has a base case which is: to_be_deleted_node == a leaf node
  otherwise keep swaping the current node with their precessors or sucessors until the current node is a leaf.
  */
  tree_node* retnode;
  //BASE CASE
  if (is_leaf((*to_be_deleted_node)))
  {   //if it's a leaf node just erase it
      retnode = (*to_be_deleted_node);
      (*to_be_deleted_node) = NULL;
      return retnode;
  }else
  // TWO POSSIBLE RECURSION CALLS
  if ((*to_be_deleted_node)->left != NULL)
  {  //swap the current node with their precessors until the current node is a leaf.
    tree_node* tmp_node = (*to_be_deleted_node)->left;
    (*to_be_deleted_node)->left = (*to_be_deleted_node);
    (*to_be_deleted_node) = tmp_node;

    subtree_delete(&((*to_be_deleted_node)->left));
  }else
  if((*to_be_deleted_node)->right != NULL)
  { //swap the current node with its sucessor until the current node is a leaf.
    tree_node* tmp_node = (*to_be_deleted_node)->right;
    (*to_be_deleted_node)->right = (*to_be_deleted_node);
    (*to_be_deleted_node) = tmp_node;

    subtree_delete(&((*to_be_deleted_node)->right));
  }

}


void printAll(binary_tree* tree)
{
  printf("--------------PRINT ALL------------------\n");
  //printf("before subtree_first function:%d\n", tree->root->value);
  tree_node* first_node = subtree_first(tree->root);
  int node_count = 0;
  //printf("||node[%d]=%d\n", node_count, first_node->value);
  while (node_count <= tree->size-1 )
  {   printf("||nodevsparent[%p]=%p\n", &first_node,&first_node->parent);
      printf("||node[%d]=%d\n", node_count, first_node->value);
      first_node = sucessor(first_node);
      node_count++;
      
  }
    printf("||node[%d]=%d\n", node_count, first_node->value);

}