#include<stdio.h>
#include"../trees.h"
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include"test.h"
#include"../digraph/btdigraph.h"
void test_insert_before(void)
{
  printf("-------starting insert before test...-------\n");
  binary_tree* t;
  malloc_binary_tree(&t, 10);
  
   
  t->root->left = (tree_node*)calloc(1, sizeof(tree_node));
  t->root->left->value = 3;
  t->root->left->parent = t->root;
  

  
  printf("_____________random teste_____________\n");
  for (int j = 0; j <= 10; j++)
      {
        int value = rand() % 10;
        tree_node* random_node = choose_rand_node(&t, 2);
        subtree_insert_before(&t, &t->root->left, value);
      }
  
  assert(t->root->left->left->right->right  != NULL);
  create_digraph(t);

  printAll(t);
  free_tree(&t);
  
}
