
total = int(input()) +1
quantity_coins = list(map(int, input().split()))
quantity_coins = [0] + quantity_coins
coins = [0,2,5,10,20,50,100]
value = [[0 for col in range(total)] for row in range(7)]
value[0][0] = 1

for i in range(1,len(coins)):
    for j in range(total):
        limit = min(quantity_coins[i],j//coins[i])
        for k in range(limit+1):
            value[i][j] = value[i][j] + value[i-1][j-(coins[i]*k)]
print(value[-1][-1])
# Dynamic Programming Python implementation of Coin  
# Change problem 
def count(S, m, n): 
  
    # table[i] will be storing the number of solutions for 
    # value i. We need n+1 rows as the table is constructed 
    # in bottom up manner using the base case (n = 0) 
    # Initialize all table values as 0 
    table = [0 for k in range(n+1)] 
  
    # Base case (If given value is 0) 
    table[0] = 1
  
    # Pick all coins one by one and update the table[] values 
    # after the index greater than or equal to the value of the 
    # picked coin 
    for i in range(0,m): 
        for j in range(S[i],n+1): 
            table[j] += table[j-S[i]] 
  
    return table[n] 
  
# Driver program to test above function 
arr = [1, 2, 3] 
m = len(arr) 
n = 4
x = count(arr, m, n) 
print (x) 

