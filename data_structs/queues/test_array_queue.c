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
static queue_arr arrq;//variable modified globaly for testing porpuses

static void test_prep(void) 
{
    prepareQueue(&arrq);
    for (int i = 0; i<= 4; i++)
    {
      assert(arrq.arr[i] == '\0');
    }
    assert(is_empty(arrq) == 1);

    assert(is_full(arrq) == 0);
  
  printf("memory test OK.\n");
}



static void test_dequeued(void) 
{
  
  for (int i = 0; i <= 4; i++)
  { //was the first element actually removed?

    queue_arr old_q = arrq;
    char poppedChar =  dequeue(&arrq);

    assert(*arrq.first != poppedChar);
    if (arrq.arr[i+1] != '\0')
    { //were the elements moved forward after poping the first one?
     
      assert(*arrq.first ==  *(old_q.first + 1));
    }
  }
  printf("dequeue OK.\n");
}

void test_enqueue(void)
{
  for (int i = 0; i<= 4; i++)
    {
      char randomLetter = 'a' + random() % 26;  
      enqueue(&arrq, randomLetter);
      assert(*arrq.last == randomLetter);
    }
    printf("enqueue OK.\n");
}

static void test_peek(void)
{
  char last = peek(arrq);

  assert(last == *arrq.first);
  printf("peek OK.\n");
}

static void test_clear(void)
{
  clearAll(&arrq);
  assert(1 == is_empty(arrq));
  printf("clear OK.\n");
}

static void test_operations(void)
{
  test_enqueue();
  test_dequeued();
  test_peek();
  test_clear();
  //assert(arrq.a );
  //printf("%c\n", arrq.arr[0]);
}


int main(void)
{
  test_prep();
  
  test_operations();
  return 0;
}
