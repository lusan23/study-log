#include<stdio.h>
#include"../trees.h"
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include"test.h"



void test_first(void)
{
  binary_tree *tree;
  malloc_binary_tree(&tree, 5);

  tree->root->right = (tree_node*)calloc(1, sizeof(tree_node));
  tree->root->right->value = 7;
  
  tree->root->left = (tree_node*)calloc(1, sizeof(tree_node));
  tree->root->left->value = 3;
  

  assert(3 == subtree_first(tree->root)->value);
  assert(7 == subtree_first(tree->root->right)->value);
  assert(3 == subtree_first(tree->root->left)->value);

  free_tree(&tree);
}