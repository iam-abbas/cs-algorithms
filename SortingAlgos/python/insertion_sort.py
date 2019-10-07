def sort(source_array: list) -> list:
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
        while j > 0 and array[j] > key:
            array[j + 1] = array[j]
            j -= 1

        array[j + 1] = key

    return array
