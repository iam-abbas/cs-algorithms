# the method relies on the fact that if we multiply matrix [[1,1],[1,0]] with it self n times we get nth fibonacci number at (0,0)
#place
# Fibonacci Series : 0,1,1,2............

# function that returns nth with 0 based indexing 

def fastfibonacci(n): 
	
	f = [[1, 1], 
		[1, 0]] 
	if (n == 0): 
		return 0
	power(f, n - 1) 
		
	return f[0][0] 
	
def multiply(f, g): 
	
	a = (f[0][0] * g[0][0] + f[0][1] * g[1][0]) 
	s = (f[0][0] * g[0][1] + f[0][1] * g[1][1]) 
	d = (f[1][0] * g[0][0] + f[1][1] * g[1][0]) 
	h = (f[1][0] * g[0][1] + f[1][1] * g[1][1]) 
	
	f[0][0] = a 
	f[0][1] = s 
	f[1][0] = d 
	f[1][1] = h 
		
 
def power(f, n): 

	if( n == 0 or n == 1): 
		return; 
	g = [[1, 1], 
		[1, 0]]; 
		
	power(f, n // 2) 
	multiply(f, f) 
		
	if (n % 2 != 0): 
		multiply(f, g) 
	

 

