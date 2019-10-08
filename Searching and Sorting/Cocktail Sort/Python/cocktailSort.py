def cocktailSort(unsorted):
    swapped = True
    start = 0 
    end = len(unsorted) -1
    while swapped:
        swapped = False
        # forward pass
        for i in range(start, end):
            if unsorted[i] > unsorted[i+1]:
                swapped = True
                unsorted[i], unsorted[i+1] = unsorted[i+1], unsorted[i]

        end -= 1

        # backward pass
        for i in range(end-1, start-1, -1):
            if unsorted[i] > unsorted[i+1]:
                swapped = True
                unsorted[i], unsorted[i+1] = unsorted[i+1], unsorted[i]
        
        start += 1
        print(unsorted)


def test():
    arr = [3,4,8,76,45,3,1,0,5,-34, 23]
    cocktailSort(arr)


if __name__ == "__main__":
    test()