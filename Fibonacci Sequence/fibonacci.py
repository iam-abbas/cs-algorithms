# Method for nth fibonacci number using Dynamic Programing 

Fib = [0,1] 

def fibonacci(num): 
	if num<0: 
		print("incorrect value!! ") 
	elif num<=len(Fib): 
		return Fib[num-1] 
	else: 
		temp_fib = fibonacci(num-1)+fibonacci(num-2) 
		Fib.append(temp_fib) 
		return temp_fib 

# driver program 

print(fibonacci(5)) 


