#include<stdio.h>
#include<stdlib.h>
//#include"stack.h"
//simple integer stack implemented using a linked list. (unlimited elements.)

typedef struct node {
  int val;
  struct node * next; 
} stack_node;

typedef struct stack {
  int val;
  stack_node * top; 
  int size;
} ll_stack;

const int ERROR_CODE = -1;
const int TRUE = 1;
const int FALSE = 0;

void check_allocation(void * node) {
  //checks if the dinamic allocation was successful.
  printf("checking memory allocation...\n");
  if (node  == NULL) {
    printf("Memory allocation failed!\n");
    exit(EXIT_FAILURE); 
  }
  
}


int is_empty(ll_stack stack)
{
  return (stack.top == NULL) ? TRUE : FALSE;
}

void push(ll_stack * stack, int new_value)
{//Done O(1)
  /*Insert an new element by inserting a new head node*/
  if(is_empty(*stack))
    {
       stack->top = (stack_node*)malloc(sizeof(stack_node));
       check_allocation(stack->top);
       stack->top->val = new_value;
       stack->top->next = NULL; 
       stack->size= 1;
       
    }
  else
    {
     
      stack_node * new_node;
      new_node = (stack_node*)malloc(sizeof(stack_node));
      check_allocation(stack->top);
      
      new_node->val = new_value;
      new_node->next = stack->top;
      stack->top = new_node;
      stack->size+=1;
    
    }
}

int pop(ll_stack * stack) 
{ /*Done O(1)
Remove the last element inserted and return it*/
  int retval;

  if(!is_empty((*stack)))
  {
    retval = stack->top->val;
    stack->top = stack->top->next;
    
    if (stack->size > 0)
    {
      stack->size--; 
    }  
    return retval;
  }

  return retval;
}

int  print_list(ll_stack  stack) {
  /*Done
  interacts through the whole list */
  printf("interacting with the linked list...\n");
  if (is_empty(stack))
    {
      printf("    ERROR: EMPTY STACK!!!\n ");
      return ERROR_CODE;
    } else
    {
      stack_node * current = stack.top;
      while (current != NULL)
	    {
	      printf("[%d,->]\n", current->val);
	      current = current->next;
	    }
      return 0;
    }
   
}

int peek(ll_stack * stack) 
{
  /*Done, O(1)
  returns the the element on the top of the stack.*/
  if (!is_empty(*stack))
  {
    return stack->top->val;
  }
} 

int size(ll_stack * stack) 
{
  if (!is_empty(*stack))
  {
    return stack->size;
  } else

  {
    printf("ERROR:Empty stack!!!\n");
    return ERROR_CODE;
  }
}

void test_stack(ll_stack * stack) 
{
  for (int i = 1; i <= 100; i+=2) 
  {
    push(stack, i);
    printf("current stack size:%d\n",size(stack));
  }
  printf("peek test:%d\n",peek(stack));

  for (int i = 1; i <= 110; i++) 
  {
    pop(stack);
    printf("current stack size:%d\n",size(stack));
  }
}

int main(void)
{
  ll_stack  new_stack;
  new_stack.top = NULL;
  //(is_empty(new_stack)) ? printf("this stack is empty!!!\n") : printf("this stack isn't empty!!!\n"); 
  
  test_stack(&new_stack);
  
  
  return 0;
}
