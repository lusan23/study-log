#include<stdio.h>
#include"trees.h"
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
void test_bt(void)
{
  binary_tree *tree;
  malloc_binary_tree(&tree, 1);
  assert(tree != NULL);
  assert(tree->root != NULL);
  
  free_tree(&tree);
}

void test_insert(void)
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


   }

  free_tree(&t);
}

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
      printf("LAST TEST\n");

      for (int j = 0; j <= 100; j++)
      {
        int value = rand() % 10;
        printf("inserting %d...\n", value);
        subtree_insert_after(&t, &t->root, value);
      }
   }

  printAll(t);
  free_tree(&t);
}

int main(void)
{
  test_bt();
  test_insert();
  test_last();
  return 0;
}
