gcc -o ./real_bt ../private_func.c ../basic_operations.c ../global_operations.c  ../tests/*.c ./*.c -fsanitize=address && ./real_bt

dot -Tpng nodess.gv -o test_tree.png && sxiv test_tree.png