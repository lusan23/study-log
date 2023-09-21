#include<stdio.h>
#include<string.h>
#include"queue.h"

//Practicing the implementation of queues (FIFO) as array
/*
  5 sized queue for int elements
operations:
queued done
unqueued
isEmpty done
isFull done
Peek

//Aditional 
Clear all
return size
constain a specific number?

(Except by constain, which is O(n) all of the operations are Big O constant)
*/
int prepareQueue(queue_arr * queue)
{
  // stablish default values for all members of the structure. 
  memset(queue->arr, '\0', sizeof(queue->arr));
  queue->last = NULL;
  queue->first = NULL;
  return 0;
}

int is_empty(queue_arr  queue)
{
  return (queue.first == NULL && queue.last == NULL) ? 1 : 0;
}

int  is_full (queue_arr  queue) 
{
  //O(1)
  return (queue.arr[4] != '\0' ) ? 1 : 0;
}

int queued(queue_arr *  queue, char value)
{
  // insert a new element on the top of the previous elements. 
  printf("pushing...\n");
  if (is_full(*queue))
  {
    printf("test:1\n");
    printf("stack full!!\n");
    return -1;
  } else if (is_empty(*queue))
    {//if it's empty set the first element and indicate last and first data.
      printf("test:2\n");
      queue->arr[0] = value;
      queue->first = &queue->arr[0];
      queue->last = &queue->arr[0];
      return 1;
    } 
  else 
    
    {
      printf("test:3\n");
      /*
      //if the stack has atleast one element...
      //change the pointer 'last'to the next memory address (2bytes reader) (it only works because arrays are consecutive in memory.)
      */
      queue->last++;
      *queue->last = value;
    } return 1;
}


