/*
implementation of a binary tree based on this lesson: 
https://www.youtube.com/watch?v=76dhtgZt38A&list=PLUl4u3cNGP63EdVPNLG3ToM6LaEUuStEY&index=10

DEVELOPMENT NOTE FOR TOMORROW:
TO MAKE INSERT_BEFORE I NEED TO MAKE PRECESSOR AND SUBTREE_LAST
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"trees.h"
#include<assert.h>
bool alloc_succeed(struct tree_node *bt)
{ //verifies with a memory allocation was sucessfull
  if (bt != NULL)
    {
      return true;
    }
  return false;
}


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

tree_node* subtree_first(struct tree_node * subtree_root)
{ //traversal inorder, returns the first node inorde
 if (subtree_root == NULL) {return NULL;}
  tree_node* current_node = subtree_root;
  while (current_node->left != NULL)
  { printf("node[%d]\n", current_node->value);
    current_node = current_node->left;
  }

  return current_node;
}

static tree_node* subtree_last(binary_tree** tree)
{
  tree_node* current_node = (*tree)->root;

  while (current_node->right != NULL)
  {
    printf("node[%d]\n", current_node->value);
    current_node = current_node->right;
  }
  return current_node;
}


tree_node* sucessor(struct tree_node *any_node) 
{
  /* Node's value should be inserted
  return the sucessor's node (after node) of the given node(in transvers order)
  if there is no right node and the given node is a right child.. the sucessor is actually the left node of its parent node.
  */ 
   if (any_node == NULL) {return NULL;}

  if (any_node->right != NULL) 
  { 
    subtree_first(any_node->right);
  }else
  {
    tree_node* current_node = any_node;
    while ( current_node == any_node->parent->left )
    { 
      printf("node[%d]\n", current_node->value);
      current_node = current_node->parent;
    }
    return current_node;
  }
}

void free_tree(binary_tree** tree)
{ //free the allocated heaps and set the pointer to NULL
    free((*tree)->root);
    (*tree)->root = NULL;
    free((*tree));
    (*tree)->root = NULL;
}

void subtree_insert_after(tree_node** entry_node, int new_value)
{//add another after entry node in the in-order tranversal of the tree
      
  if (!(*entry_node)->right)
  { 
    (*entry_node)->right = (tree_node *)calloc(1, sizeof(tree_node));
    (*entry_node)->right->value = new_value;
  }else
  { 
    tree_node * scsr =  sucessor((*entry_node)); 
    scsr->left = (tree_node *)calloc(1, sizeof(tree_node));

    scsr->left->value = new_value;
    assert(scsr->left->value == new_value);
  }
}



bool is_leaf(struct tree_node* node)
{
  return (node->left == NULL && node->right == NULL && node->parent != NULL) ? true : false;
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