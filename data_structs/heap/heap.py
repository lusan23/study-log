""" implementation of the heap data structure and  the heap sort algorithm """
from math import floor
binary_tree = [None, 3, 5, 1, 9, 2, 7, 10, 4, 6] # unsorted array 


def heapify_max(bt, n, i) -> None:
    """ makes a regular complete binary tree into a max heap 
    Precondition 0 < i

    left child = i * 2
    right child = i * 2 + 1
    
    """

    # check the childs of each node 

    # if it's the parent < child swap them
    largest = i
    left = i* 2
    right= i*2 + 1

    if (left < n) and (bt[left] > bt[largest]):
        largest = left

    if (right < n) and (bt[right] > bt[largest]):
        largest = right
    
    if largest != i:
        bt[largest], bt[i] = bt[i], bt[largest]

        heapify_max(bt, n, largest)

def build_heap(bt):
    n = len(bt)

    for i in range(n//2, 0, -1):
        heapify_max(bt, n, i)


if __name__ == "__main__":
    print(f"unsorted:\n{(binary_tree)}")

    build_heap(binary_tree)
    print(f"sorted:\n{(binary_tree)}")