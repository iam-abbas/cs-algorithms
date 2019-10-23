# To heapify subtree rooted at index i.
# n is size of heap
def heapify(arr, n, i):
    large = i  # Initialize large as root
    l = 2 * i + 1     # left = 2*i + 1
    r = 2 * i + 2     # right = 2*i + 2
 
    # If left child of root exists and is
    # greater than root
    if l < n and arr[i] < arr[l]:
        large = l
 
    # If right child of root exists and is
    # greater than root
    if r < n and arr[large] < arr[r]:
        large = r
 
    # Change root, if needed
    if large != i:
        arr[i],arr[large] = arr[large],arr[i]  #swapping done
 
        # Heapify the root.
        heapify(arr, n, large)
 

def heapSort(arr):
    n = len(arr)
 
    # Build a maxheap.
    for i in range(n, -1, -1):
        heapify(arr, n, i)
 
    # One by one extract elements
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]   # swapping done
        heapify(arr, i, 0)
 

s = input()
arr = list(map(int, s.split()))
heapSort(arr)
n = len(arr)
print ("Sorted array is:")
for i in range(n):
    print ("%d" %arr[i]),