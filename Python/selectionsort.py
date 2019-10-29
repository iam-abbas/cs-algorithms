def selection_sort(a_list):
    for i in range(len(a_list)):
        min_pos = i

        for j in range(i+1, len(a_list)):
            if a_list[min_pos] > a_list[j]:
                min_pos = j
                
        aux = a_list[i]
        a_list[i] = a_list[min_pos]
        a_list[min_pos] = aux

    return a_list


if __name__ == "__main__":
    arr = [int(x) for x in input("Enter the array elements : ").split()]
    a = selection_sort(arr)
    print(a)
