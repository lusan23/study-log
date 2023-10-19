#include<stdio.h>
#include"../trees.h"
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include"test.h"


void test_sucessor(void)
{
  //NEED TO BE TESTED AFTER THE ROTATE ALGORITHM IS IMPLEMENTED
  printf("-------starting sucessor test...-------\n");
  binary_tree *tree;
  malloc_binary_tree(&tree, 5);

  tree->root->right = (tree_node*)calloc(1, sizeof(tree_node));
  tree->root->right->value = 7;
  tree->root->right->parent = tree->root;
  
  tree->root->left = (tree_node*)calloc(1, sizeof(tree_node));
  tree->root->left->value = 3;
  tree->root->left->parent = tree->root;


  assert(sucessor(tree->root)->value = 7);
  //because it's a subtree operations
  assert(sucessor(tree->root->right)->value == 7);
  free_tree(&tree);
}
