**Linked Lists**


Code based on this tutorial: https://www.learn-c.org/en/Linked_lists

```c
typedef struct node {
  int value;
  struct node * next;
  struct node * previous;  
} node_t;
```

The `node_t` is a struct representing a node in the linked list, containing an integer value and a pointer to the next node.

```c
void check_allocation(void * node) {
  // Checks if the dynamic allocation was successful
  // and terminates the program if allocation failed
}
```

The `check_allocation` checks if dynamic allocation was successful. If not, it prints an error message and exits the program.

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

The `initList` initializes a linked list with two nodes. It allocates memory for the head and tail, sets default values, and links them.

```c
void print_list(node_t * head) {
  // Prints the values of all nodes in the linked list
  
  // Traverse the list and print each node's value
}
```

The `print_list` traverses the list, starting from the head, and prints each node's value.

```c
void append(node_t ** n, int val) {
  // Adds a new node at the end of the linked list
  
  // Find the last node in the list
  // Allocate memory for the new tail node
  // Set the value of the new tail node
  // Establish the link between the new tail and the previous tail
}
```

The `append` adds a new node to the end of the list.

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

The `push` adds a new node after a specified value.

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

The `pop` inserts a new node at the beginning of the list.

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

The `remove_last` the name describes itself, removes the last node in the list.

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

The `remove_by_index` removes a node at a given index.

# Doubly Linked List

---

### Struct Definition<a name="struct-definition"></a>

```c
typedef struct node {
  int value;
  struct node * next;
  struct node * tail;   
  struct node * previous;
}node_t;
```

This defines a structure `node_t` which represents a node in the doubly linked list. It contains an integer value, and pointers to the next, tail, and previous nodes.

## Doubly Linked Lists have the functions as singly linked lists, plus these:

### Add After<a name="add-after"></a>

```c
void addAfter(node_t ** head, int ref_node_value, int new_value);
```

This function adds a new node with value `new_value` after the node with value `ref_node_value`.

### Add Before<a name="add-before"></a>

```c
void addBefore(node_t ** head, int ref_node_value, int new_value);
```

This function adds a new node with value `new_value` before the node with value `ref_node_value`.

---

# Doubly Linked List

## Working on it!!!



