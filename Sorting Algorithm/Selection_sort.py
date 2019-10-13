new_list = input("Enter list: ")
arr = list(map(int, new_list.split(",")))

for i in range(len(arr)):
    pivot = i
    for j in range(i,len(arr)):
        if arr[j]<arr[pivot]:
            pivot = j;
    arr[pivot],arr[i] = arr[i],arr[pivot]

print(arr)
