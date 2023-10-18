#include<stdio.h>
#include"../trees.h"
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include"test.h"



void test_bt(void)
{
  binary_tree *tree;
  malloc_binary_tree(&tree, 1);
  assert(tree != NULL);
  assert(tree->root != NULL);
  
  free_tree(&tree);
}