#A Dynamic Programming based Python Program for the Egg Dropping Puzzle 
import sys  
  
# Function to get minimum number of trials  
# needed in worst case with n eggs and k floors  
def eggDrop(n, k): 
  
    # If there are no floors, then no trials needed. If there is one floor, one trial needed. 
    if (k == 0 or k == 1): 
        return k 
  
    # We need k trials for one egg and k floors 
    if (n == 1): 
        return k 
  
    min = sys.maxsize 
  
    # Consider all droppings from 1st floor to kth floor and return the minimum of these values plus 1. 
    for x in range(1, k + 1): 
  
        res = max(eggDrop(n - 1, x - 1), eggDrop(n, k - x)) 
        if (res < min): 
            min = res 
  
    return min + 1
  
  
if __name__ == "__main__": 
  
    n = 2
    k = 36 
    #or
    #n=int(input("Enter number of eggs : "))
    #k=int(input("Enter number of floors : "))
    print("Minimum number of trials in worst case with", n, "eggs and", k, "floors is", eggDrop(n, k)) 
