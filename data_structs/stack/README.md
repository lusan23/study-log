## [array_stack_v1.1.c](https://github.com/lusan23/study-log/blob/master/data_structs/stack/array_stack_v1.1.c)

This is a C implementation of a stack using arrays. The stack is a last-in-first-out (LIFO) data structure, which means that the last element added to the stack is the first element removed.

The following functions are provided:

* `createStack()`: Initializes a new stack.
* `is_empty()`: Checks if the stack is empty.
* `is_full()`: Checks if the stack is full.
* `peek()`: Returns the element at the top of the stack without removing it.
* `push()`: Adds a new element to the top of the stack.
* `pop()`: Removes the element at the top of the stack and returns it.
* `print_all()`: Prints all the elements in the stack in reverse order.

To use the stack, you first need to create a new stack using the `createStack()` function. Once you have created a stack, you can add elements to it using the `push()` function and remove elements from it using the `pop()` function. You can check if the stack is empty using the `is_empty()` function and check if the stack is full using the `is_full()` function. You can also print all the elements in the stack using the `print_all()` function.

Here is an example of how to use the stack:

```c
#include <stdio.h>
#include "stack.h"

int main() {
  stack_i stack;

  createStack(&stack);

  // Push some elements onto the stack.
  push(&stack, 1);
  push(&stack, 2);
  push(&stack, 3);

  // Print all the elements in the stack.
  print_all(&stack);

  // Pop an element from the stack and print it.
  int popped_element = pop(&stack);
  printf("Popped element: %d\n", popped_element);

  // Check if the stack is empty.
  if (is_empty(&stack)) {
    printf("The stack is empty.\n");
  } else {
    printf("The stack is not empty.\n");
  }

  return 0;
}
```

Output:

```
--------
|  3  |MA:0x7ffee4a689f0
--------
--------
|  2  |MA:0x7ffee4a689ec
--------
--------
|  1  |MA:0x7ffee4a689e8
--------
end of stack

Popped element: 3

The stack is not empty.
```
