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
  subtree_insert_after(&tree, &tree->root, 6);

  assert(tree->root->value == subtree_first(tree->root)->value);
}