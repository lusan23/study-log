//do a stack of array based.
//do a stack based linked lists.
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node * next;
} s_node;

typedef struct stacks
{
    //first needs to be declared as NULL
    struct node * first; 
    int size;
    struct node * last;
} stacks;


int is_empty(stacks * s) {
    if (s == NULL) {
        return 1;
    } else {return 0;}
}

int push(stacks ** s, int value) {
    s_node * f = NULL;
    if (is_empty(*s)) {
        printf("empty!!!");
        f = (s_node*)malloc(sizeof(s_node));
        f->next = NULL;
        f->val = value;

        *s = (stacks*)malloc(sizeof(stacks));
        (*s)->first = f;
        (*s)->last = f;
        (*s)->size++;
    } else {
        f = (s_node*)malloc(sizeof(s_node));
        f->next = NULL;
        f->val = value;
    }

}

typedef struct array {
    int size;
    int list[size];
} 

int main() {
    stacks * s = NULL;
    push(&s, 666);
    if (is_empty(s)) {printf("vazio!!!\n");}
    
    //printf("%d\n", s->first->val);

  return 0;
}