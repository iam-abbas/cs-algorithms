def BubbleSort(lst):  
    lst = list(lst) #copy collection to list   
    for passesLeft in range(len(lst)-1, 0, -1):  
        for i in range(passesLeft):  
            if lst[i] < lst[i + 1]:  
               lst[i], lst[i + 1] = lst[i + 1], lst[i]  
    return lst