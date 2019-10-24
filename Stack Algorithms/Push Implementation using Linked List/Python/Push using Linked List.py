def createStack(): 
	stack = [] 
	return stack 

def isEmpty(stack): 
	return len(stack) == 0

def push(stack, item): 
	stack.append(item) 
	print(item + " pushed to stack ") 
	
stack = createStack() 
push(stack, str(10)) 
push(stack, str(20)) 
push(stack, str(30)) 
