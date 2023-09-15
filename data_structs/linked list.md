**Linked Lists**

This file provides an explanation of the functionality and usage of the provided code.

Code based on this tutorial: https://www.learn-c.org/en/Linked_lists

```c
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
  int value;
  struct node * next;
  struct node * previous;  
} node_t;
```

The `node` struct is used to represent a node in a doubly linked list. It contains an integer value and pointers to the next and previous nodes in the list.

```c
void check_allocation(void * node) {
  // Checks if the dynamic allocation was successful
  // and terminates the program if allocation failed
}
```

The `check_allocation` function is a utility function that checks if a memory allocation was successful. If the allocation failed (i.e., the passed node is NULL), the function displays an error message and terminates the program.

```c
void initList(node_t** head, int defaultVal) {
  // Initializes an empty doubly linked list
  
  // Create the tail node
  // Allocate memory for the head node
  // Set the value of the head node
  // Allocate memory for the tail node
  // Set the value of the tail node
  // Establish the link between head and tail
}
```

The `initList` function initializes an empty doubly linked list. It takes a double pointer to a node (`head`) and a default value as parameters. It creates the tail node, allocates memory for the head node, sets its value, allocates memory for the tail node, sets its value, and establishes the link between the head and tail nodes.

```c
void print_list(node_t * head) {
  // Prints the values of all nodes in the linked list
  
  // Traverse the list and print each node's value
}
```

The `print_list` function iterates through the linked list and prints the value of each node.

```c
void append(node_t ** n, int val) {
  // Adds a new node at the end of the linked list
  
  // Find the last node in the list
  // Allocate memory for the new tail node
  // Set the value of the new tail node
  // Establish the link between the new tail and the previous tail
}
```

The `append` function adds a new node with the given value at the end of the linked list. It finds the last node in the list, allocates memory for the new tail node, sets its value, and establishes the link between the new tail node and the previous tail node.

```c
void push(node_t ** head, int val) {
  // Adds a new node at the beginning of the linked list

  // Create a new node
  // Allocate memory for the new node
  // Set the value of the new node
  // Establish the link between the new node and the current head
  // Update the head pointer to point to the new node
}
```

The `push` function adds a new node with the given value at the beginning of the linked list. It creates a new node, allocates memory for it, sets its value, establishes the link between the new node and the current head node, and updates the head pointer to point to the new node.

```c
int pop(node_t ** head){
  // Deletes the first node in the linked list and returns its value

  // Create a new node to store the second node
  // Save the value of the second node
  // Free the current head node
  // Update the head pointer to point to the second node
  // Return the value of the deleted node
}
```

The `pop` function deletes the first node in the linked list and returns its value. It creates a new node to store the second node, saves the value of the second node, frees the memory allocated for the current head node, updates the head pointer to point to the second node, and returns the value of the deleted node.

```c
int remove_last(node_t * head) {
  // Removes the last node from the linked list and returns its value

  // If there is only one item in the list, remove it
  // Traverse the list to find the second-to-last node
  // Save the value of the last node
  // Free the memory allocated for the last node
  // Update the next pointer of the second-to-last node to NULL
  // Return the value of the deleted node
}
```

The `remove_last` function removes the last node in the linked list and returns its value. If there is only one item in the list, it is removed directly. Otherwise, it traverses the list to find the second-to-last node, saves the value of the last node, frees the memory allocated for the last node, updates the next pointer of the second-to-last node to NULL, and returns the value of the deleted node.

```c
int remove_by_index(node_t ** head, int n) {
  // Removes a node at a given index from the linked list and returns its value

  // Handle the special case when the node to be removed is the first node
  // Traverse the list to find the node right before the one to be removed
  // Handle the case when the node to be removed is the last node
  // Make the previous node point to the next node
  // Free the memory allocated for the node to be removed
  // Return the value of the deleted node
}
```

The `remove_by_index` function removes a node at the given index from the linked list and returns its value. It handles the special case when the node to be removed is the first node, traverses the list to find the node right before the one to be removed, handles the case when the node to be removed is the last node, makes the previous node point to the next node, frees the memory allocated for the node to be removed, and returns the value of the deleted node.

```c
int main() {
  // Initialize the head of the linked list with default value
  // Append nodes to the linked list
  // Print the linked list
  // Remove a node at a given index
  // Print the updated linked list
  // Return 0 to exit the program
}
```

In the `main` function, the program initializes the head of the linked list with a default value, appends nodes to the linked list using the `append` function, prints the linked list using the `print_list` function, removes a node at a given index using the `remove_by_index` function, prints the updated linked list, and returns 0 to exit the program.

This documentation provides an overview of the code's functionality and usage.
