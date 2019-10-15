# Program in python to print primes smaller than or equal to 
# n using Sieve of Eratosthenes 

def Sieve(n): 
	 
	primer = [True for i in range(n + 1)] 
	x = 2
	while (x * x <= n): 
		
		# If primer[x] is not changed, then it is a prime 
		if (primer[x] == True): 
			
			# Update all multiples of x 
			for i in range(x* 2, n + 1, x): 
				primer[i] = False
		x += 1
	primer[0]= False
	primer[1]= False
	# Print all prime numbers 
	for x in range(n + 1): 
		if primer[x]: 
			print x, 

# driver program of seive
if __name__=='__main__': 
	n = 50
	print "prime numbers smaller", 
	print "than or equal to", n 
	Sieve(n) 
