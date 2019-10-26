def nthMagicNo(n): 
  
    pow = 1
    answer = 0
  
    # Go through every bit of n 
    while (n): 
  
        pow = pow*5
  
        # If last bit of n is set 
        if (n & 1): 
            answer += pow
  
        # proceed to next bit 
        n >>= 1 # or n = n/2 
      
    return answer 
  
  
# Driver program to test above function 
n = 10
print("nth magic number is", nthMagicNo(n)) 
  
