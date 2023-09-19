//do a stack of static array based 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int  stack[4];

void  createStack()
{
  //O(n) to be fixed
  memset(stack, 0, sizeof(stack));
  printf("initialized!\n");
  
}

int  is_empty()
{
  //O(1)
  /* verify if the stack is empty by looking if  the first element == 0 */ 
  if (stack[0] == 0)
  {
    printf("Empty stack!!!\n");
    return EXIT_FAILURE;
  }
  else { return 0;}
}

int is_full () {
  //O(1)
  
  return (stack[3] != 0 ) ? 1 :  0;
}

int peek()
{
  //O(n) to be fixed
  for (int i = 3; i >= 0; i--)
    {
      printf("teste:%d\n", i);
      if ( stack[i] != 0)
	{
	  return stack[i];
	  
        }
    }
  return -1;
}

int push(int value) {
  //O(n) to be fixed
  /* insert a new element on the top of the previous elements. */
  printf("pushing...\n");
  if (is_full(stack))
  {
    printf("stack full!!\n");
    return -1;
  }
  else
    {
      for (int i = 0; i <= 3; i++)
	{
        if ( stack[i] == 0)
	  {
	    stack[i] = value;
	    return 1; 
          }
        }
    } return 0;
}

int pop()
{
  //o(n) to be fixed
  printf("popping...\n");
   for (int i = 3; i >= 0 ; i--)
     {
     if (stack[i] != 0)
       {
	 stack[i] = 0;
	 return 1;
       }
     
     }
   return 0;
}

void print_all() {
  //0(n) done
  printf("--------\n");
  for (int i = 3; i >=  0; i--) {

    printf("|  %d  |\n",stack[i] );
    printf("--------\n");
    
  }
  printf("end of stack\n\n");
}

int main ()
{
  createStack();
  print_all();
  push(10);
print_all();
   push(-1);
print_all();
   push(10);
print_all();
   push(10);
print_all();
   push(10);
print_all();
  return 0;

}
