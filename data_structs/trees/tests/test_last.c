#include<stdio.h>
#include"../trees.h"
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include"test.h"


void  test_last(void)
{
  binary_tree *t;
  malloc_binary_tree(&t,1);

   if (alloc_succeed(t->root))
   {
    /*
    tests based on the inorder transversal rule:
    the right child node x of node y == x node is after y
    the left child node x of node y ==  x node is before y

    */
  
      subtree_insert_after(&t, &t->root, 10);
      assert(t->root->right->value == 10);
      printAll(t);
      printf("--------------LAST TEST------------\n");

      for (int j =  0; j <= 5; j++)
      { 
        int value = rand() % 10;
        tree_node* random_node = choose_rand_node(&t, 3);
        
        printf("inserting %d. after %d..\n", value, random_node->value);
        subtree_insert_after(&t, &random_node, value);
      }
   }

  printf("the last node is %d.\n", subtree_last(t->root)->value);
  printAll(t);
  free_tree(&t);
}
