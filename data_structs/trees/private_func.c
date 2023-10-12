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


tree_node* subtree_first(struct tree_node * subtree_root)
{ //traversal inorder, returns the first node inorde
 if (subtree_root == NULL) {return NULL;}
  tree_node* current_node = subtree_root;
  //printf("before the while: %d\n", current_node->value);
  while (current_node->left != NULL)
  { 
    //printf("node[%d]\n", current_node->value);
    //printf("the parent of %d is %d\n", current_node->value, current_node->parent->value);
    current_node = current_node->left;
  }
  //printf("after the while: %d\n", current_node->value);
  return current_node;
}


tree_node* subtree_last(binary_tree** tree)
{//returns the last node in the tree (transversal order).
  tree_node* current_node = (*tree)->root;
  printf("looking for the last node...\n");
  while (current_node->right != NULL)
  {
    printf("node[%d]\n", current_node->value);
    current_node = current_node->right;
  }
  return current_node;
}

 tree_node* predecessor(struct tree_node *any_node) 
{
  /* Node's value should be inserted before
  return the sucessor's node (before node) of the given node(in transvers order)
  if there is no left node and the given node is a left child.. the sucessor is actually the left node of its parent node.
  */ 
    printf("-----------PREDECESSOR------------\n");
   if (any_node == NULL) {return NULL;}
  if (any_node->left != NULL) 
  { printf("case one\n");
    subtree_first(any_node->left);
    
  }else
      
  {   printf("case two\n");  
      // if any node is a right leaf....     
        if (any_node->parent != NULL)
        {
        if (any_node == any_node->parent->right)
        { 
          printf("case two.1\n");
          return any_node->parent;
        } 
        else
        {
          printf("case two.2\n");
        //if any node is a left leaf...
        if (any_node == any_node->parent->left)
        {
            printf("case two.3\n");
          return any_node;
        }
        else
        { 
          printf("case three\n");
          tree_node* current_node = any_node;
        
          while ( &current_node != &any_node->parent->right )
          { 
            //printf("node[%d]\n", current_node->value);
          
            current_node = current_node->parent;
      
          }
      
        return current_node;
      }
    }
  } printf("it's the root node!!!\n");
  return any_node;
}
}


 tree_node* sucessor(struct tree_node *any_node) 
{
  /* Node's value should be inserted
  return the sucessor's node (after node) of the given node(in transvers order)
  if there is no right node and the given node is a right child.. the sucessor is actually the left node of its parent node.
  */ 
   if (any_node == NULL) {return NULL;}

  if (any_node->right != NULL) 
  { //printf("case one\n");
    subtree_first(any_node->right);
    
  }else
  {   // if any node is a left leaf....
      if (any_node == any_node->parent->left)
      { 
        //printf("case two\n");
        return any_node->parent;
      } 
      else
      //if any node is a right leaf...
       if (any_node == any_node->parent->right)
       {
        return any_node;
       }
       else
      {
        //printf("case three\n");
        tree_node* current_node = any_node;
        
        while ( &current_node != &any_node->parent->left )
        { 
          //printf("node[%d]\n", current_node->value);
          
          current_node = current_node->parent;
      
        }
      
      return current_node;
    }
  }
}

 tree_node* recursive_free(tree_node** root)
{
  //free the all the nodes recursively.
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

bool is_leaf(struct tree_node* node)
{
  return (node->left == NULL && node->right == NULL && node->parent != NULL) ? true : false;
}