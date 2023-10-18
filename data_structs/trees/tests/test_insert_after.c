#include<stdio.h>
#include"../trees.h"
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include"test.h"

void test_insert_after(void)
{
  printf("insert after test...\n");
  binary_tree *t;
  malloc_binary_tree(&t,1);

   if (alloc_succeed(t->root))
   {
    /*
    tests based on the inorder transversal rule:
    the right child node x of node y == x node is after y
    the left child node x of node y ==  x node is before y

    */
      printf("worked!\n");

      subtree_insert_after(&t,&t->root, 10);
      assert(t->root->right->value == 10);
      printf("----\n");

      subtree_insert_after(&t,&t->root, 20);
      assert(t->root->right->left->value == 20);

      subtree_insert_after(&t, &t->root->right, 30);
      assert(t->root->right->right->value == 30);

      subtree_insert_after(&t, &t->root, 40);
      assert(t->root->right->left->left->value == 40);

      subtree_insert_after(&t, &t->root->right, 50);
      assert(t->root->right->right->left->value == 50);
    printAll(t); 
      for (int j = 0; j <= 5; j++)
      {
        int value = rand() % 100;
        tree_node* random_node = choose_rand_node(&t, 3);
        //printf("inserting %d. after %d..\n", value, random_node->value);
        subtree_insert_after(&t, &random_node, value);
      }
   }

  printAll(t);
  free_tree(&t);
}
