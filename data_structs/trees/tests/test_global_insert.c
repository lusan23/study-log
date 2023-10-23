#include<stdio.h>
#include"../trees.h"
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include"test.h"
#include"../digraph/btdigraph.h"
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

  printf("-------------- random test -----------------------\n");
  for (int j = 0; j <= 2; j++)
  {
    tree_node* rand_node = choose_rand_node(&tree, 1);
    int rand_val = rand() % 10;
    printf("choosen value:%d\n", j);
    insert(&tree, j);

    /*
    if ( rand_node->value >= 5)
    {
      assert(tree->root->left->left == NULL && tree->root->left->right == NULL);
    }
    else
    {
      assert(tree->root->right->left == NULL && tree->root->right->right == NULL);
    }
    */
   
  }
  
  create_digraph(tree);
  printAll(tree);
  free_tree(&tree);
}