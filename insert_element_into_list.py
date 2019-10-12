# Python3 program to insert an element into sorted list 

# Function to insert element 
def insert(list, n): 
	
	# Searching for the position 
	for i in range(len(list)): 
		if list[i] > n: 
			index = i 
			break
	
	# Inserting n in the list 
	list = list[:i] + [n] + list[i:] 
	return list


list = [1, 2, 4] 
n = 3

print(insert(list, n)) 
