#include<stdio.h>
#include<stdlib.h>

typedef struct node {
  int value;
  struct node * next;
  struct node * previous;
  
}node_t;

void check_allocation(void * node) {
  //checks if the dinamic allocation was successful.
  printf("checking memory allocation...\n");
  if (node  == NULL) {
    printf("Memory allocation failed!\n");
    exit(EXIT_FAILURE); 
  }
  
}

void initList(node_t** head, int defaultVal) {
  /* Takes a empty node_t variable and updates it as an two node linked list.

  node_t** because the pointer/argument "node_t** head" points to pointer "head" 
  that points to somewhere else in memory . 

  create tail node
  allocate memory for head 
  insert value to head 
  allocate memory for tail
  insert value to tail
  finish list adding null to tail.
  */

  printf("setting up a new linked list...\n");
  node_t * tail;
  *head = (node_t*)malloc(sizeof(node_t));
  check_allocation(&head);

  (*head)->value = defaultVal;
  (*head)->next = (node_t*)malloc(sizeof(node_t));
  (*head)->previous = NULL;
  
  check_allocation(&(*head)->next);
  
  (*head)->next->value = defaultVal +1;
  (*head)->next->next = NULL;
  (*head)->next->previous = *head;
  
}



void print_list(node_t * head) {
  /*interacts through the whole list 
  
  create current node
  current node = head
  while current node is not the last node
    print current element's value
    go to the next element
  */
  printf("interacting with the linked list...\n");
  node_t * current = head;
  while (current != NULL) {
    printf("[%d,->]\n", current->value);
    current = current->next;
  }
   
}

void append(node_t ** n, int val) {
  /*interacts through all list and add a new tail (last element) 

  create current node,
  current node = head,

  while current node is not the last node
    go to the next element

  current node is now the last node(tail),
  allocate memory for tail,
  insert value to tail node,
  finish the list inserting null in tail.
  */

  printf("adding a new tail...\n");
  node_t * current = *n;
  
  while (current->next != NULL) {
    current = current->next;
  }
  printf("tail found!\n");
  current->next = (node_t *)malloc(sizeof(node_t));
  check_allocation(current->next);
  
  current->next->value = val;
  current->next->next = NULL;
  current->next->previous = current;
  
} 

void push(node_t ** head, int val) {
  /*creates a new head (a new first element in the list.)

    create a new node
    allocate memory to new node

  */
  printf("adding a new head...\n");
  node_t * new_node;
  new_node = (node_t *)malloc(sizeof(node_t));

  new_node->value = val;
  new_node->next = *head;
  new_node->previous = NULL;
  *head = new_node;

}

int pop(node_t ** head){
  /*Delete the first element in the list.

    create a new node, 
    save the second node and its value in the new node,
    free/delete current head,
    make the new node become head.
  */
  printf("deleting the current head...\n");
  int retval = -1;
  node_t * next_node = NULL;

  check_allocation(*head);
  next_node = (*head)->next;
  next_node->previous = NULL;
  free(*head);
  *head = next_node;

  return retval;
}

int remove_last(node_t * head) {
  printf("removing laste element in the list...\n");
  int retval = 0;
  /*if there is only one item in the list, remove it */
  if (head->next == NULL) {
    retval = head->value;
    free(head);
    return retval;
  }

  /*get to the second to last node in the list*/
  node_t * current = head;
  while (current->next->next != NULL) {
    current = current->next;
  }

  /*now current points to the second last item*/
  retval = current->next->value;
  free(current->next);
  current->next = NULL;
  return retval;
}

int remove_by_index(node_t ** head, int n) {
  
  printf("removing node of index %d", n);
  int i = 0;
  int retval = -1;
  node_t * current = *head;
  node_t * temp_node = NULL;

  if (n == 0) {
    return pop(&(*head));
  }
  //go to the node right before the one that's going to deleted (n-1)
  for (i = 0; i < n-1; i++) {
    if (current->next == NULL) {
      return -1; 
    }
    current = current->next;
  }

  //the node can't be the tail!
  if (current->next == NULL) {
    return -1;
  }
  //make the node before n refer to the node after and delete node n 
  temp_node = current->next;
  retval = temp_node->value;
  current->next = temp_node->next;
  current->next->previous = current;
  free(temp_node);

  return retval;
}

int main() {
  node_t * head = NULL;
  initList(&head, 0);
  append(&head, 2);
  append(&head, 3);
  append(&head, 4);
  print_list(head);
  remove_by_index(&head, 3);
  print_list(head);
  /*
  append(&head, 10);
  print_list(head);
  push(&head, 999);
  print_list(head);
  pop(&head);
  print_list(head);
  remove_last(head);
  print_list(head);
  remove_by_index(&head, 1);
  print_list(head);
  */
  return 0;
}
