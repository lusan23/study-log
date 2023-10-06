# Dinamic Array

This is a simple implementation of [dinamic array](/data_structs/array/dinamic_array.c) in C for learning porpuses 

## How is it structured?

### The queue itself is implemented as two structs C struct:

```C
typedef struct dinamic_array
{
    int size;
    int * i;
}dinamic_array;
```
`dinamic_array` stores an int pointer (that will be the dinamic array).

