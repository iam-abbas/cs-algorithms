
def Fibonacci(n): 
  if n<0: 
    print("Incorrect input") 
  # First Fibonacci number is 0 
  elif n==1: 
    return 0
  # Second Fibonacci number is 1 
  elif n==2: 
    return 1
  else: 
    return Fibonacci(n-1)+Fibonacci(n-2) 
  
print(Fibonacci(9))

#Fibonacci with Looping
def FibonacciLoop(n): 
  for i in range(9):
    if i == 0:
        print(0)
        after = 1
    elif i == 1:
        print(1)
        before = 1
    else:
        sums = before + after
        print(sums)
        before = after
        after = sums
        
print(FibonacciLoop(9))