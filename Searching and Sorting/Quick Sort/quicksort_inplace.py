# Source : https://stackoverflow.com/questions/18262306/quicksort-with-python
# Thanks To alisianoi

import random


def qsort(x, first, last):
    if first >= last:
        return

    i, j = first, last
    pivot = x[random.randint(first, last)]

    while i <= j:
        while x[i] < pivot:
            i += 1
        while x[j] > pivot:
            j -= 1
        if i <= j:
            x[i], x[j] = x[j], x[i]
            i, j = i + 1, j - 1
    qsort(x, first, j)
    qsort(x, i, last)
