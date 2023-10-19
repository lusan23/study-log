#include<stdio.h>
#include"../trees.h"
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include"test.h"


void  test_last(void)
{
  binary_tree *tree;
  malloc_binary_tree(&tree, 5);

  tree->root->right = (tree_node*)calloc(1, sizeof(tree_node));
  tree->root->right->value = 7;
  
  tree->root->left = (tree_node*)calloc(1, sizeof(tree_node));
  tree->root->left->value = 3;
  assert(subtree_last(tree->root)->value == 7);
  assert(subtree_last(tree->root->right)->value == 7);
  assert(subtree_last(tree->root->left)->value == 3);
  
  
  
  free_tree(&tree);
}
