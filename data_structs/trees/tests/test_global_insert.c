#include<stdio.h>
#include"../trees.h"
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include"test.h"

void test_global_insert(void)
{
  binary_tree *tree;
  malloc_binary_tree(&tree, 5);
  assert(tree != NULL);
  assert(tree->root != NULL);

  insert(&tree, 1);

  assert(tree->root->left->value == 1);

  insert(&tree, 9);
  assert(tree->root->right->value == 9);

  

  free_tree(&tree);
}