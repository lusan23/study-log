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
int queued(queue_arr *  queue, char value);
#endif
