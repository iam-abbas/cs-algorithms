import random as ran
#Fermat Probabilistic Primality Test:
#https://en.wikipedia.org/wiki/Primality_test#Fermat_primality_test
#using Fermat's Little Theorem to test for primality, which says that
#if a number p is prime, then for any number between 1 and p-1, a, the following
#relationship should hold:
#a^(p-1) mod p=1
#there exist a set of numbers known as the carmichael number which are composite
# numbers that may pass the test is a few trials, so the algorithm accounts for
#this by running it many times
def isPrime(n,k):
    #n is the number to be tested and k is the number of times to run the test
    for x in range(0,k):
        #choose a random integer between 1 and n-1
        y=ran.randint(1,n-1)
        #pow here is doing modular exponentiation
        if(pow(y,n-1,n)!=1):
            return False
    return True

#driver function to test code
x=71
if isPrime(x,1000):
    print(x,"is Prime!")
else:
    print(x,"is not Prime!")
print("\nPrimes list and chances to fail")
#list of some primes, have no fails
primes=[103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199]
for y in primes:
    fails=0
    for x in range(0,1000):
        if(not isPrime(y,1)):
            fails+=1 #count number of fails
    print(y,"fail chance:",fails/1000)

print("\nComposite list and chances to fail")
#list of composite numbers, have near 100% fails
comps=[171, 172, 174, 175, 176, 177, 178, 180, 182, 183, 184, 185, 186, 187, 188, 189, 190, 192, 194, 195]
for y in comps:
    fails=0
    for x in range(0,1000):
        if(not isPrime(y,1)):
            fails+=1
    print(y,"fail chance:",fails/1000)

print("\nCarmichael numbers list and chances to fail")
#showcases the carmichael numbers and how they are less likely to fail the test than other non-carmichael composite numbers
car=[561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973, 75361, 101101, 115921, 126217, 162401]
for y in car:
    fails=0
    for x in range(0,1000):
        if(not isPrime(y,1)):
            fails+=1
    print(y,"fail chance:",fails/1000)
