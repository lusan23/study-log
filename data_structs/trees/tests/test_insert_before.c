#include<stdio.h>
#include"../trees.h"
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include"test.h"

void test_insert_before(void)
{
  printf("-------starting inser before test...-------\n");
  binary_tree* t;
  malloc_binary_tree(&t, 100);
  printAll(t);
  subtree_insert_before(&t, &t->root, 200);

  printf("root:%d\nnew_node:%d\n",t->root->value, t->root->left->value);
  printAll(t);

  free_tree(&t);
  
}
