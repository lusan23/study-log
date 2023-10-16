#!/bin/bash

sudo gcc -o bt.o -c ../../trees/binary_search_tree.c 

sudo gcc -o tbt.o -c ../../trees/test_binary_search_tree.c

sudo gcc -o pf.o -c ../../trees/private_func.c

#gcc -g -o bin_tree bt.o tbt.o pf.o 

gcc -o bin_tree bt.o tbt.o pf.o -fsanitize=address # no debugger 

./bin_tree 