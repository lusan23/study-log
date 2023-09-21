#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
#include<assert.h>
/*
  Test properties
    verify the behaviour of members in the queue structure 
    as operations manipulate its data.

  Test Operations
    verify the corrects of outputs and error handling of these operations.
*/
static queue_arr arrq;

void test_prep(void) 
{
    prepareQueue(&arrq);
    for (int i = 0; i<= 4; i++)
    {
      assert(arrq.arr[i] == '\0');
    }
    assert(is_empty(arrq) == 1);

    assert(is_full(arrq) == 0);
}

void test_operations(void)
{
  char test_array[5] = {'a','b','c','d','e'};
  for (int i = 0; i<= 4; i++)
    {
      queued(&arrq, test_array[i]);
      assert(arrq.arr[i] == test_array[i]);

    }
  //assert(arrq.a );
  //printf("%c\n", arrq.arr[0]);
}

int main(void)
{
  test_prep();
  
  test_operations();
  return 0;
}
