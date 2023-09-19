# [doubly_linked_list.c](https://github.com/lusan23/study-log/blob/master/data_structs/LLists/doubly_linked_list.c)

This is a C implementation of a doubly linked list. A doubly linked list is a data structure that consists of a sequence of nodes where each node contains a value and two pointers, one to the next node in the list and one to the previous node in the list. This allows for efficient insertion and deletion operations at any point in the list.

The following functions are provided:

* `initList()`: Initializes a new linked list.
* `print_list()`: Prints all the elements in the linked list.
* `append()`: Adds a new element to the end of the linked list.
* `push()`: Adds a new element to the beginning of the linked list.
* `pop()`: Removes the element at the beginning of the linked list and returns its value.
* `remove_last()`: Removes the element at the end of the linked list and returns its value.
* `remove_by_index()`: Removes the element at the specified index in the linked list and returns its value.
* `addAfter()`: Inserts a new element after the node with the specified value.
* `addBefore()`: Inserts a new element before the node with the specified value.

Here is an example of how to use the linked list:

```c
#include <stdio.h>
#include "linked_list.h"

int main() {
  node_t *head = NULL;

  // Initialize the linked list.
  initList(&head);

  // Add some elements to the linked list.
  append(&head, 1);
  append(&head, 2);
  append(&head, 3);

  // Print all the elements in the linked list.
  print_list(head);

  // Remove the element at the beginning of the linked list.
  int popped_element = pop(&head);
  printf("Popped element: %d\n", popped_element);

  // Remove the element at the end of the linked list.
  int removed_element = remove_last(&head);
  printf("Removed element: %d\n", removed_element);

  // Remove the element at the specified index.
  int removed_at_index_element = remove_by_index(&head, 1);
  printf("Removed element at index 1: %d\n", removed_at_index_element);

  // Add a new element after the node with the value 1.
  addAfter(&head, 1, 4);

  // Add a new element before the node with the value 2.
  addBefore(&head, 2, 0);

  // Print all the elements in the linked list.
  print_list(head);

  return 0;
}
```

Output:

```
[1,->]
[2,->]
[3,->]
Popped element: 1
Removed element: 3
Removed element at index 1: 2
[0,->]
[1,->]
[4,->]
```
