# Python program 
# The main function that returns number of ways to get sum 'x' 
# with 'n' dice and 'm' with m faces. 


def findWays(f, d, s): 
	# Create a table to store results of subproblems. One extra 
	# row and column are used for simpilicity (Number of dice 
	# is directly used as row index and sum is directly used 
	# as column index). The entries in 0th row and 0th column 
	# are never used. 
	mem = [[0 for i in range(s+1)] for j in range(d+1)] 
	# Table entries for no dices 
	# If you do not have any data, then the value must be 0, so the result is 1 
	mem[0][0] = 1
	# Iterate over dices 
	for i in range(1, d+1): 

		# Iterate over sum 
		for j in range(1, s+1): 
			# The result is obtained in two ways, pin the current dice and spending 1 of the value, 
			# so we have mem[i-1][j-1] remaining combinations, to find the remaining combinations we 
			# would have to pin the values ??above 1 then we use mem[i][j-1] to sum all combinations 
			# that pin the remaining j-1's. But there is a way, when "j-f-1> = 0" we would be adding 
			# extra combinations, so we remove the combinations that only pin the extrapolated dice face and 
			# subtract the extrapolated combinations. 
			mem[i][j] = mem[i][j - 1] + mem[i - 1][j - 1] 
			if j - f - 1 >= 0: 
				mem[i][j] -= mem[i - 1][j - f - 1] 
	return mem[d][s] 

# Driver code 

print(findWays(4, 2, 1)) 
print(findWays(2, 2, 3)) 
print(findWays(6, 3, 8)) 
print(findWays(4, 2, 5)) 
print(findWays(4, 3, 5)) 
