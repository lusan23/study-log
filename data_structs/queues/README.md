# Queue as Array

This is a C implementation of a Queue data structure as a five sized array.
the First in First Out 
## How is it structured ?

### The queue itself is implemented as an C struct:
```C
typedef struct queue_arr
{
  char  arr[5];
  char * first;
  char * last;
  int size;
} queue_arr;
```

  The pointers `last` and `first` make allows insert and remove elements in a constant time complexity, rather than using loops, which would be in linear time.

Setting up:

The default value of an empty `queue_arr`'s  array  is '\0' and for the pointers `NULL`. The following function sets up the these default values.

```C
int prepareQueue(queue_arr * queue)

```

### Operations

`is_empty`, `is_full`, `clearAll` the  functions name describe themselves.

`size` The number of elements added to the array

```C
   int size(queue_arr queue)
```

it adds a new element to the array in clockwise direction.
```C
   int enqueue(queue_arr *  queue, char value)
```


