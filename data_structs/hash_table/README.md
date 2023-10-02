# Dictionary Implementation as a Hash Table

This is a simple implementation of an [hash table](/data_structs/hash_table/simple_hash.c). 

## How is it structured?

### The queue itself is implemented as two structs C struct:

```C
typedef struct hash_node
{
  char key[200];
  char value[200];
} hash_node;
```
`hash_node` is the hash table unit, that stores the given data.

```C
typedef struct hash_tbl
{
  hash_node* table;
  int size;
} hash_tbl;

```

`hash_tbl` it's the table itself, containing a `hash_node` pointer that will be dynamic allocated with the given size.

# How to use it?

You can use these functions in your .c file just be including the path `"path_direct/hash.h"`.

### Creating a hash table

```C
hash_tbl* createHashTable(int size)
```
This function will return a `hash_tbl` pointer allocated dynamically with the given no-negative `size`.   
The variable that will receive defined must be a pointer as well!

Example:
```C
hash_tbl* table = createHashTable(10);
```

### Insert
```C
int insert(hash_tbl* table ,  char new_key[200], char new_value[200])
```
If it succeeds, stores `new_key` and `new_value` somewhere in the table and returns the given `new_key`s `hash code`, otherwise it will return `-1`.

Example:
```C
hash_tbl* CountriesCities = createHashTable(10);

insert(CountriesCities, "Brazil", "Rio de Janeiro");
```

### Search
```C
char * search(hash_tbl * table, char key[200])
```
If it succeeds return the `value` of `key`, if it fails return `NULL`.
Example:
```C
hash_tbl* teamPlayers = createHashTable(100);
insert(teamPlayers, "Neymar", "Al-Hilal");

search(teamPlayers, "Neymar");

```
### Delete
```C
char * delete(hash_tbl * table, char key[200])
```
If it succeeds replace the inserted info as `"\0"`(the deleted flag) and returns `value`, otherwise returns `NULL`.

Example:
```C
hash_tbl* favoriteFood = createHashTable(100);
insert(teamPlayers, "Luan", "Lasagne");

delete(favoriteFood, "Luan");
```
## Private functions
Two functions are meant to be used inside `Insert, Search, and Delete`.
Those are: `getInt` and `preHashing`, they aren't declared as static/private so you can call them whenever you would like to.

## Tests

I've made a few tests while implementing at [`test_hash.c`](/data_structs/hash_table/test_hash.c), the executable file on the folder [build](/data_structs/build/).

Thank you for taking a look! :)
