'''
The GCD algorithm computes the greatest common divisor of two numbers A and B recursively.
'''

def gcd(x, y):
    if (y==0):              # base case 
        return x
    else:                   # recursive case
        return gcd(y, x%y)

if __name__ == "__main__":
    print (gcd(x=100, y=20))