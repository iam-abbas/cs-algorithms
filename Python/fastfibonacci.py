def fastfibonacci(i): 
    if i<0: 
        print("Incorrect input, enter number >= 0") 
    elif i==0: 
        return 0 
    elif i==1: 
        return 1
    else: 
        return fastfibonacci(i-1)+fastfibonacci(i-2) 
  
print(fastfibonacci(2)) 
