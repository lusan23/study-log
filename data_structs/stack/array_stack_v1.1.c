//stack implementation baise using structs (peek,pop and push are O(1))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack_i {
  int init[4];
  int * first;
  int * last; 
} stack_i;

void  createStack(struct stack_i * entry)
{
  //O(1)
  memset(entry->init, 0, sizeof(entry->init)); 
  entry->first = NULL;
  entry->last = NULL;
  
  printf("initialized!\n");
  
}

int  is_empty( stack_i * entry)
{
  //O(1)
  // verify if the stack is empty by looking if  the pointer last is pointing to null or somewhere in memory. 
  return (entry->first == NULL) ? 1 : 0;
  
}

int  is_full (stack_i * entry) {
  //O(1)
  
  return (entry->init[3] != 0 ) ? 1 :  0;
}

int  peek(stack_i * entry)
{
  //O(1) 
  return (entry->last != NULL ) ? *entry->last : -1;
}

int push(stack_i * entry, int value) {
  //O(1)
  // insert a new element on the top of the previous elements. 
  printf("pushing...\n");
  if (is_full(entry))
  {
    printf("stack full!!\n");
    return -1;
  } else if (is_empty(entry))
    {//if it's empty set the first element and indicate last and first data.
      entry->init[0] = value;
      entry->first = &entry->init[0];
      entry->last = &entry->init[0];
      return 1;

    } 
  else 
    
    {
      /*
      //if the stack has atleast one element...
      //change the pointer 'last'to the next memory address (2bytes reader) (it only works because arrays are consecutive in memory.)
      */
      entry->last++;
      *entry->last = value;
    } return 1;
}

int pop(stack_i * entry)
{
  //O(1) 
  int retval;
  printf("popping...\n");
  if (is_empty(entry))
  {
    return -1;
  } else if (entry->last == entry->first)
    {//if there's only the first element...
      entry->last = NULL;
      retval = *entry->first;
      *entry->first = 0;
      entry->first = NULL;
    }

  else
    {
      retval = *entry->last;
       *entry->last = 0; 
       entry->last--;
       return retval;
    }
   return 1;
}
  




void print_all(stack_i * entry) {

  //0(n) done
  printf("--------\n");
  for (int i = 3; i >=  0; i--) {

    printf("|  %d  |MA:%p\n", entry->init[i],&entry->init[i] );
    printf("--------\n");
    
  }
  printf("end of stack\n\n");
}

int main ()
{
  stack_i s;
  createStack(&s);
  print_all(&s);
  is_empty(&s) ? printf("\nstack empty\n") : printf("\nstack not empty!!!\n");
  is_full(&s) ? printf("\nstack full!!\n") : printf("\nstack not full!\n");
  //printf("TESTE:%d", peek(&s));
  push(&s, 10);
  push(&s, 27);
  push(&s, 999991);
  push(&s, -230);
  push(&s, 10);
  print_all(&s);
  pop(&s);
  pop(&s);
  pop(&s);
  pop(&s);
  pop(&s);
  
  
  print_all(&s);
  //printf("TESTE:%d", peek(&s));
  return 0;

}
