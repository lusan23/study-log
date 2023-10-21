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


tree_node* subtree_last(tree_node* node)
{//returns the last node in a subtree (transversal order).
  tree_node* current_node = node;
  printf("looking for the last node...\n");
  if (current_node->right == NULL)
  {
    printf("there's no right child in the 'root' of this subtree.\n");
    return current_node;
  }
  printf("teste-last\n");
  while (current_node->right != NULL)
  {
    printf("node[%d]\n", current_node->value);
    current_node = current_node->right;
  }
  return current_node;
}

bool node_on_root_right(tree_node* given_node)
{
  //check if the given node is before or after the root. (in traversal order.)
  //if it returns false, it means that the given node is on the left of the root, 
  //and if it true means that the given node is in the right side. 
  tree_node* currt_node = given_node;
  tree_node* prev_node = currt_node;
   //leaking to random if it's root or not
  while (currt_node->parent != NULL)
  {
    prev_node = currt_node;
    currt_node = currt_node->parent;
  }
  return (currt_node->right == prev_node) ? true : false;

}

/*
 tree_node* predecessor(struct tree_node *any_node) 
{
  

  // If has a left child node, just return its left child.
  // if there's no left child... is the given node before or after the root? (it changes the way it looks for the predecessor)
  //   if it's after the root...
  //     if it's a left child leaf go up the tree and return its predecessor
  //     if
   
    printf("-----------PREDECESSOR------------\n");
  if (any_node == NULL) {return NULL;}
  if (any_node->left != NULL) 
  { //if the given node has a left child go to the first node of that subtree and return it
    printf("case 1\n");
    return any_node->left;
  }else
  { //if the given node doesn't not have a right child and is a left node itself...

      if (any_node == any_node->parent->left)
       {  printf("case 2\n");

          return any_node->parent;
       }
      else if (any_node == any_node->parent->right)
      { //if the given node doesn't not have a right child and is a right node itself...
        printf("case 3\n");
        while (any_node != any_node->parent->right)
        {
         
          any_node = any_node->parent;
        }
        return any_node->parent;
      }
    }

}
*/


 tree_node* predecessor(struct tree_node *any_node) 
{
  /*
  return the predesucessor's node (before node) of the given node(in transversal order)


  If has a left child node, just return its left child.
  if there's no left child... is the given node before or after the root? (it changes the way it looks for the predecessor)
    if it's after the root...
      if it's a left child leaf go up the tree and return its predecessor
      if
  */ 
    printf("-----------PREDECESSOR------------\n");
  if (any_node == NULL) {return NULL;}
  printf("input:%d\n", any_node->value);
  if (any_node->left != NULL) 
  { //if the given node has a left child go to the first node of that subtree and return it
    printf("case one\n");
    return any_node->left;
  }else
      if (any_node->parent == NULL)
      {
        printf("it's the root!!!\n");
        return any_node;
      }
      if(node_on_root_right(any_node))
      { // if the given node comes after the root...
        printf("testing it!!!\n");
        if (any_node == any_node->parent->left)
        {//if the given node is a left child and and doesn't a left child go up 
         //the tree and find your predecessor.
          
          while (any_node != any_node->parent->right)
          {
            any_node = any_node->parent;
          }
          return any_node->parent;
        }else
        {//if the given is a right child and doesn't have a left child return its parent!!!
          return any_node->parent;
        }
      }
      else
      {//if the node is before the root... (NOT TESTED YET!!!)
        if (any_node == any_node->parent->left && any_node->parent->parent->right == any_node->parent)
        {//if it's a left child leaft and its on the right side of its subtree 
         //root go up and return your predecessor


          while (any_node != any_node->parent->right)
          {
            any_node = any_node->parent;
          }
          return any_node->parent;
        }

        if (any_node == any_node->parent->left)
        {
          printf("it's the first one!!!\n");
          return any_node;
        }
      }
  {   
}
}

bool is_last(tree_node* given_node)
{
  bool is_right_child = false;
  while (given_node->parent != NULL)
  {
    if (given_node == given_node->parent->right)
    {
      is_right_child = true;
    }
    else {return false;}
    given_node = given_node->parent;
  }
  return is_right_child;
}

/*
 tree_node* sucessor(struct tree_node *any_node) 
{
  // Node's value should be inserted
  // return the sucessor's node (after node) of the given node(in transvers order)
  // if there is no right node and the given node is a right child.. 
  // the sucessor is actually the left node of its parent node.
  // 

  //printf("----------SUCESSOR--------------\n");
   if (any_node == NULL) {return NULL;}

  if (any_node->parent == NULL) 
  {
    printf("This is a subtree function! please, don't pass the root node as an argument. It maybe can cause error in some cases.\n"); 
    
  }

  if (any_node->right != NULL) 
  { printf("sucessor: case one\n");
    subtree_first(any_node->right);
    
  }else
    //if there's no right child and itself is a left child...
    if (any_node->parent->left == any_node)
    { printf("sucessor: case two\n");
      return any_node->parent;
    }
    else 
      {//if there's no right child and it's a right child
      printf("sucessor: case three\n");
      if (is_last(any_node))
      {
        return any_node;
      }
        while (any_node != any_node->parent->left )
        {  
            any_node = any_node->parent;
        }
          return any_node->parent;
      }
  } 

*/

 tree_node* sucessor(struct tree_node *any_node) 
{
  /* Node's value should be inserted
  return the sucessor's node (after node) of the given node(in transvers order)
  if there is no right node and the given node is a right child.. 
  the sucessor is actually the left node of its parent node.
  */ 

  //printf("----------SUCESSOR--------------\n");
   if (any_node == NULL) {return NULL;}

  if (any_node->right != NULL) 
  { printf("sucessor: case one\n");
    subtree_first(any_node->right);
    
  }else

  if (node_on_root_right(any_node))
  {
    
      // if any node is a left leaf....
      if (any_node == any_node->parent->left)
      { 
        printf("sucessor: case two, in %d\n", any_node->value);
        return any_node->parent;
      } 
      else
      //if any node is a right leaf...
       if (any_node == any_node->parent->right)
       { 
        if (is_last(any_node) == true)
        {
          if (any_node->left != NULL)
          {
            return any_node->left;
          }
          return any_node;
        }

        if (any_node->parent == any_node->parent->parent->left && any_node->left )
        { 
          
          //printf("THE LEFT NODE OF %d IS %p\n", any_node->value, &any_node->left);
          while (any_node != any_node->parent->right)
          {
            any_node = any_node->parent;
          }
        }else if (any_node == any_node->parent->right)
        {//if it's a right child leaf...
        
        
        while (any_node != any_node->parent->left)
        {
          any_node = any_node->parent;
        }
        
        while (any_node != any_node->parent->right)
        {
          any_node = any_node->parent;
        }
        return any_node;
        }
       }
  
   
    
    return any_node;
  } ///HANDLE (INSERT_BEFORE) NODES IN THE FUTURE.
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

tree_node* get_root(tree_node* given_node)
{
  tree_node* currt_node = given_node;

  while (currt_node->parent != NULL)
  {
    currt_node = currt_node->parent;
  }
  
  return currt_node;
}

void printAll(binary_tree* tree)
{
  
  printf("--------------PRINT ALL------------------\n");
  //printf("before subtree_first functigion:%d\n", tree->root->value);
  tree_node* first_node = subtree_first(tree->root);
  printf("teste\n");
  tree_node* last_node = subtree_last(tree->root);
  int node_count = 0;
  //printf("||node[%d]=%d\n", node_count, first_node->value);

  while (first_node != last_node)
  {   //printf("||nodevsparent[%p]=%p\n", &first_node,&first_node->parent);

      printf("||node[%d]=%d\n", node_count, first_node->value);
      first_node = sucessor(first_node);
      break;      
  }

  if (first_node != NULL)
  {
    printf("||node[%d]=%d\n", node_count, first_node->value);
  }


}