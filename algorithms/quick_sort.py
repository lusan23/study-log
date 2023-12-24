""" implementetion of the quicksort algorithm  """

# worst case O(n^2)
# avereage case Theta(nlogn)

def sort_pivot(arr: list) -> None: 
    """ sort the first middle and last elements in the array
    
    Precodition: arr's length >= 3

    """
    length = len(arr)
    initial_pivot = arr[0]
    middle_pivot = arr[length >> 1]
    final_pivot = arr[length-1]
    sorted_pivots = [initial_pivot, middle_pivot, final_pivot]
    sorted_pivots.sort()
    arr[0], arr[length >> 1], arr[length-1] = sorted_pivots[0], sorted_pivots[1], sorted_pivots[2]
    print(f"choosen pivot:{sorted_pivots[1]}")
    pass

    

def swap(arr, index_a, index_b):
    """ swap the to elements using its given indexes: a an db """
    tmp = arr[index_b]
    arr[index_b] = arr[index_a]  
    arr[index_a] = tmp 
    

def quick_sort(arr):
    """ recursive function for rearranging the array 
    arr = [9, 8, 7, 6, 5, 4, 3, 2, 1]
    quick_sort(arr)
    arr
    [1, 2, 3, 4, 5, 6, 7, 8 , 9]
    """
    length = len(arr)
    # base case len(arr) == 1
    if (length == 1):
        return  None
    
    # pivot selection: 
    # 1. sort first, middle and last and swap middle by last 
    sort_pivot(arr)
    mid_index, lst_index = length >> 1, length-1
    swap(arr, mid_index, lst_index)

    # define left and right element
    left_item_i, right_item_i = 0, lst_index-1
    
    # keep going to left and right until left's index is bigger than right
    # and if every item to the left of pivot smaller, also if every item to the right of pivot is bigger:
        # swap left and right

    left_ok = False
    right_ok = False

    while  not_pivot_condition:
        print(f" loop init:{arr}")

        if (left_item_i > right_item_i):
            left_item_i , right_item_i = 0, lst_index-1

        if ( arr[left_item_i] > arr[lst_index] and arr[right_item_i] < arr[lst_index]  ):

            swap( arr,left_item_i , right_item_i ) 
        else:
            left_ok = True

        if ( arr[right_item_i] < arr[lst_index] and arr[left_item_i] > arr[lst_index] ):
            pivot_condition = False
            swap( arr,left_item_i , right_item_i) 
        else:
            not_pivot_condition = False
        
            pivot_condition = False
            
        left_item_i += 1
        right_item_i -= 1 

    # swap back middle pivot with left_item 
    swap(arr,left_item_i , lst_index)
    
    # call quick sort for the left and right side of the pivot 
    print(f"before next call:{arr}")
    quick_sort(arr[:length >> 1])
    quick_sort(arr[length >> 1:])


if __name__ == "__main__":
    # import doctest
    # doctest.testmod()

    arr = [9, 8, 7, 6, 5, 4, 3, 2, 1]
    quick_sort(arr)
    print(arr)
    
    
