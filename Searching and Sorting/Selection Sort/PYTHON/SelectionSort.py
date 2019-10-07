#Call 'main()' in the terminal/console to run Selection Sort on desired unsorted sequence.

#This algorithm returns the sorted sequence of the unsorted one and works for positive values.

def SelectionSort(arr):
    pos = 0
    min_num = 0
    for i in range(0, len(arr)):
        min_num = arr[i]
        pos = i
        for j in range(i+1, len(arr)):
            if min_num > arr[j]:
                min_num = arr[j]
                pos = j
        if pos != i:
            arr[i], arr[pos] = arr[pos], arr[i]
    return arr
            
def main():
    arr = list()
    print("Enter the elements of array to be sorted.\
          Type 'x' (along with inverted commas) for termination")
    while True:
        el = input()
        if el is 'x' or el is 'X':
            break
        else:
            arr.append(int(el))
    arr = SelectionSort(arr)
    print("Sorted array is : {}", arr)
    return 0

if __name__ == "__main__":
    main()
