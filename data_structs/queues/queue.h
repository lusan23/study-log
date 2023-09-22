#ifndef QUEUE_H
#define QUEUE_H


typedef struct queue_arr
{
  char  arr[5];
  char * first;
  char * last;
} queue_arr;

int prepareQueue( queue_arr * queue);
int is_empty(queue_arr queue);
int  is_full (queue_arr  queue);
int enqueue(queue_arr *  queue, char value);
char dequeue(queue_arr * queue);
char peek(queue_arr queue);
void clearAll(queue_arr * queue);
#endif
