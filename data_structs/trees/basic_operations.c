/*
implementation of a binary tree based on this lesson: 
https://www.youtube.com/watch?v=76dhtgZt38A&list=PLUl4u3cNGP63EdVPNLG3ToM6LaEUuStEY&index=10 
Obs.: on the lesson sucessor and predecessor are subtree operation but in this
implementations they work for the whole tree
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
      return;
    }

}
void free_tree(binary_tree** tree)
{ //free the allocated heaps and set the pointer to NULL
    
    recursive_free(&(*tree)->root);
    (*tree)->root = NULL;
    free((*tree));
 
    
}

void subtree_insert_after(binary_tree** tree, tree_node** entry_node, int new_value)
{//add another after entry node in the in-order tranversal of the tree
  
  if (!(*entry_node)->right)
  { //check its left child
    printf("case one: %d\n", new_value);
    (*entry_node)->right = (tree_node *)calloc(1, sizeof(tree_node));
    (*entry_node)->right->value = new_value;
    (*entry_node)->right->parent = (*entry_node);
    assert((*entry_node)->right->left == NULL);
    assert((*entry_node)->right->right == NULL);
    
    assert((*entry_node)->right->parent->value == (*entry_node)->value);
    (*tree)->size++;
  }
  else
  { 
    printf("case two: %d\n", new_value);
    tree_node * scsr =  sucessor((*entry_node)); 
    scsr->left = (tree_node *)calloc(1, sizeof(tree_node));
    scsr->left->value = new_value;
    scsr->left->parent = scsr;
    assert(scsr->left->value == new_value);
    assert(scsr->left->parent->value == scsr->value);
    (*tree)->size++;
  }
}


void subtree_insert_before(binary_tree** tree, tree_node** entry_node, int new_value)
{//add another after entry node in the in-order tranversal of the tree
  
  if ((*entry_node)->left == NULL)
  { //check its left child
    printf("case one: %d\n", new_value);
    (*entry_node)->left = (tree_node *)calloc(1, sizeof(tree_node));
    (*entry_node)->left->value = new_value;
    (*entry_node)->left->parent = (*entry_node);
    assert((*entry_node)->left->left == NULL);
    assert((*entry_node)->left->right == NULL);
    
    assert((*entry_node)->left->parent->value == (*entry_node)->value);
    (*tree)->size++;
  }
  else
  { 
    printf("case two: %d\n", new_value);
    tree_node * scsr =  predecessor((*entry_node)); 
    scsr->right = (tree_node *)calloc(1, sizeof(tree_node));
    scsr->right->value = new_value;
    scsr->right->parent = scsr;

    
    assert(scsr->right->value == new_value);
    assert(scsr->right->parent->value == scsr->value);
    
    (*tree)->size++;
  }
  
}



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
