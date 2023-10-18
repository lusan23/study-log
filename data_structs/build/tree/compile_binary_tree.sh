#!/bin/bash


# test functions.
sudo gcc -o bt.o -c ../../trees/basic_operations.c 

sudo gcc -o pf.o -c ../../trees/private_func.c

sudo gcc -o go.o -c ../../trees/global_operations.c

sudo gcc -o test_bt.o -c ../../trees/tests/test_bt.c

sudo gcc -o test_first.o -c ../../trees/tests/test_first.c

sudo gcc -o test_last.o -c ../../trees/tests/test_last.c

sudo gcc -o test_predecessor.o -c ../../trees/tests/test_predecessor.c

sudo gcc -o test_sucessor.o -c ../../trees/tests/test_sucessor.c

sudo gcc -o test_insert_after.o -c ../../trees/tests/test_insert_after.c

sudo gcc -o test_insert_before.o -c ../../trees/tests/test_insert_before.c

sudo gcc -o test_choose_rand_node.o -c ../../trees/tests/choose_rand_node.c

sudo gcc -o test_global_insert.o -c ../../trees/tests/test_global_insert.c

sudo gcc -o tbt.o -c ../../trees/tests/test_main.c 


#gcc -g -o bin_tree bt.o tbt.o pf.o 

gcc -o bin_tree go.o bt.o tbt.o test_bt.o test_first.o test_last.o test_predecessor.o test_sucessor.o test_insert_after.o test_insert_before.o pf.o test_choose_rand_node.o test_global_insert.o  -fsanitize=address # no debugger 

./bin_tree 