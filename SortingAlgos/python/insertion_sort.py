def insertion_sort(source_array: list) -> list:
    """
    Implementation of the polynomial O(n^2) Insertion Sort algorithm

    Arguments:
        source_array - array of integers to be sorted

    Returns:
        Contents of array argument
    """
    # Create copy to avoid affecting source array
    array = source_array

    # Everything to the left of index i is sorted
    for i in range(1, len(array)):
        key = array[i]

        # Insert current key into sorted sequence
        j = i - 1

        # Iterate until current position >= key
        while j >= 0 and array[j] > key:
            array[j + 1] = array[j]
            j -= 1

        array[j + 1] = key

    return array


if __name__ == "__main__":
    import random

    NUM_VALUES = 10
    MAX_VALUE = 100

    # Uncomment to generate consistent random values between each run
    # random.seed(0xd34db33f)

    # Generate list of NUM_VALUES random values in range [0, MAX_VALUE]
    unsorted = [random.randint(0, NUM_VALUES) for _ in range(0, MAX_VALUE + 1)]

    # Perform sort, asserting result matches Python's default sorting functionality
    sorted_arr = insertion_sort(unsorted)
    print("Sorted successfully!" if sorted_arr ==
          sorted(unsorted) else "Did not sort!")
