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
  binary_tree* t;
  malloc_binary_tree(&t, 100);
  
  subtree_insert_after(&t,&t->root, 10);
  
  assert(t->root->right->value == 10);
  printf("----\n");
  
  subtree_insert_after(&t,&t->root, 20);
  subtree_insert_after(&t, &t->root->right, 30);
  subtree_insert_after(&t, &t->root, 40);
  subtree_insert_after(&t, &t->root->right, 50);
  subtree_insert_after(&t, &t->root->right->left, 70);
 

  assert(t->root->right->left->value == 20);
  assert(t->root->right->right->value == 30);
  assert(t->root->right->left->left->value == 40);
  assert(t->root->right->right->left->value == 50);
  assert(t->root->right->left->right->value == 70);

  for (int j = 0; j <= 5; j++)
  //test it in different levels, choose_rand_node(tree, steps)
  { tree_node* random_node = choose_rand_node(&t, 3);
    tree_node* scsr = sucessor(random_node);

    printf("The sucessor of %d is %d.\n", random_node->value, scsr->value);  
  }
  printAll(t);
  free_tree(&t);
}
