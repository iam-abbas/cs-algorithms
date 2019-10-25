
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
  
#Fibonacci with Looping
def FibonacciLoop(n):
  if n == 1:
    return 0
  for i in range(1 + n):
    if i == 0:
        sums = after = 0
    elif i == 1:
        sums = before = 1
    else:
        sums = before + after
        before = after
        after = sums
  return sums
        
# Fibonacci with matrix multiplication
# (f[1], f[2]) * P = (f[2], f[3])
# (f[1], f[2]) * P^n = (f[n+1], f[n+2]) 
# P = [[0, 1],
#      [1, 1]]
def FibonacciBinPow(n):
    m = [[0, 1],[1, 1]]

    def multiply(a, b):
        # basic 2x2 matrix multiplication
        return [[a[0][0]*b[0][0]+a[0][1]*b[1][0], a[0][0]*b[0][1]+a[0][1]*b[1][1]],[a[1][0]*b[0][0]+a[1][1]*b[1][0], a[1][0]*b[0][1]+a[1][1]*b[1][1]]]

    def binpow(m, p):
        if p == 0:
            return [[1, 0], [0, 1]]
        if p % 2 == 0:
            c = binpow(m, p / 2)
            return multiply(c, c)
        return multiply(m, binpow(m, p - 1))

    return binpow([[0, 1], [1, 1]], n-1)[1][0]

for i in range(1, 10):
    print(Fibonacci(i), FibonacciLoop(i), FibonacciBinPow(i))
