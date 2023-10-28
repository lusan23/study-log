#ifndef STACK_H
#define STACK_H

typedef struct node {
  int val;
  struct node * next; 
} stack_node;

typedef struct stack {
  int val;
  stack_node * top; 
  int size;
} ll_stack;

int is_empty(ll_stack stack);
void push(ll_stack * stack, int new_value);
int pop(ll_stack * stack);
int peek(ll_stack * stack);
int size(ll_stack * stack);

#endif
