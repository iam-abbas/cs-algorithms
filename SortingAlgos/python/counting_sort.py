def counting_sort(array: list) -> list:
    """
    Implementation of the linear O(n) Counting Sort algorithm

    Arguments:
        array - array of integers to be sorted

    Returns:
        Contents of array argument
    """
    # Number of items to be sorted
    n: int = len(array)

    # Get maximum value in array - represented by k in textbook
    max_val: int = max(array)

    # Create resultant sorting array, reserving space for n items
    sorted_arr: list = [None] * n

    # Count array is "temporary working storage" of max_val # of items
    count: list = [0] * (max_val + 1)

    # Set count[val] to contain number of elements equal to val in array
    for val in array:
        count[val] += 1

    # Set count[i] equal to number of elements <= i
    for i in range(len(count)):
        # Avoid attempting to access count[-1] if on first iteration
        count[i] += count[i - 1] if i != 0 else 0

    # Do sorting from end of array down
    for i in range(len(array) - 1, -1, -1):
        sorted_arr[count[array[i]] - 1] = array[i]
        count[array[i]] -= 1

    return sorted_arr


if __name__ == "__main__":
    import random

    NUM_VALUES = 10
    MAX_VALUE = 100

    # Uncomment to generate consistent random values between each run
    # random.seed(0xd34db33f)

    # Generate list of NUM_VALUES random values in range [0, MAX_VALUE]
    unsorted = [random.randint(0, NUM_VALUES) for _ in range(0, MAX_VALUE + 1)]

    # Perform sort, asserting result matches Python's default sorting functionality
    sorted_arr = counting_sort(unsorted)
    print("Sorted successfully!" if sorted_arr == sorted(unsorted) else "Did not sort!")
        
