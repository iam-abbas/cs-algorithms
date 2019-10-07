#For binary search to execute, list/array to be searched, must be a sorted sequence.

#Call 'main()' in the terminal/console to run Binary Search on desired sorted sequence.

#This algorithm returns the presence and position of number to be searched, 
#in the sorted sequence.

def BinarySearch(arr, lb, ub, num):
    flag, mid = 0, 0
    while lb <= ub:
        mid = (lb+ub)/2
        if arr[mid] == num:
            flag = 1
            break
        elif arr[mid] < num:
            lb = mid + 1
            BinarySearch(arr, lb, ub, num)
        else:
            ub = mid - 1
            BinarySearch(arr, lb, ub, num)
    return flag, mid
            
def main():
    arr = list()
    print("Enter the elements of array in increasing/deceasing order.\
          Type 'x' (along with inverted commas) for termination")
    while True:
        el = input()
        if el is 'x' or el is 'X':
            break
        else:
            arr.append(int(el))
    print("Enter the number to be searched")
    num = int(input())
    ub = len(arr)
    flag, pos = BinarySearch(arr, 0, ub, num)
    if flag == 1:
        print("Number is present in the array at {} postion".format(pos+1))
    else:
        print("Number is not present in the array")
    return 0

if __name__ == "__main__":
    main()
