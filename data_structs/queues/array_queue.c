//Practicing the implementation of queues (FIFO) as an array
//(Except by constain, which is O(n) all of the operations are Big O constant)

#include<stdio.h>
#include<string.h>
#include"queue.h"

<<<<<<< HEAD
=======
//Practicing the implementation of queues (FIFO) as array
/*
  5 sized queue for int elements
operations:
queued done
unqueueddone
isEmpty done
isFull done
Peek done

//Aditional 
Clear all
return size
contain a specific number?

(Except by contain, which is O(n) all of the operations are Big O constant)
*/


>>>>>>> ec7458d813dbc2d05af4f6c2bc53020db1ce2e2f
int prepareQueue(queue_arr * queue)
{
  // stablish default values for all members of the structure. 
  printf("DEBUGGING:RESET\n");
  memset(queue->arr, '\0', sizeof(queue->arr));
  queue->last = NULL;
  queue->first = NULL;
  queue->size = 0;
  return 0;
}

int is_empty(queue_arr  queue)
{
  return (queue.first == NULL && queue.last == NULL && queue.size == 0) ? 1 : 0;
}

int  is_full (queue_arr  queue) 
{
  //O(1)
  return (queue.arr[4] != '\0' ) ? 1 : 0;
}

int enqueue(queue_arr *  queue, char value)
{
  // insert a new element on the top of the previous elements. 
  if (is_full(*queue))
  {
    printf("stack full!!\n");
    return -1;
  } else if (is_empty(*queue))
    {//if it's empty set the first element and indicate last and first data.

      queue->arr[0] = value;
      queue->first = &queue->arr[0];
      queue->last = &queue->arr[0];
      queue->size++;
      
      return 1;
    } 
  else 
    
    {
      /*
      if the stack has atleast one element...
      change the pointer 'last'to the next memory address (2bytes reader) (it only works because arrays are consecutive in memory.)
      */
      queue->last++;
      *queue->last = value;
      queue->size++;
    } return 1;
}

char dequeue(queue_arr * queue)
{
  char retval;

  if (!is_empty(*queue))
  {
    retval = *queue->first;
    *queue->first = '\0';
    queue->first++;
    queue->size--;
    return retval;
  } else 
  {//if the queue is empty reset the pointers to their original position.
    prepareQueue(&(*queue));
  }
 
}

char peek(queue_arr queue)
{
  return *queue.first;
}

void clearAll(queue_arr * queue)
{
  prepareQueue(&(*queue));
}
<<<<<<< HEAD

int size(queue_arr queue)
{
  return queue.size;
}

void printQueue(queue_arr queue)
{
  if (!is_empty(queue))
  {
    printf("current size:%d\n",size(queue));
    for(int i = 0; i<=4; i++)
    {
      
      if (i != 4)
	{
	  printf("|"); printf("%c", queue.arr[i]); printf("|");
	}
      else {printf("|"); printf("%c", queue.arr[i]); printf("|\n");}

      
    }
  
  }
}

int contain(queue_arr queue, char value)
{
  for (int i = 0; i<= (size(queue)-1); i++)
    {
      if (value == queue.arr[i])
	{
	  return 1;
	}
    }

  return 0;
}
=======
>>>>>>> ec7458d813dbc2d05af4f6c2bc53020db1ce2e2f
