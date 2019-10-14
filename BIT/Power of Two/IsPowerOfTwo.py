number = int(input())

isPowerOf2 = number & (number - 1)

if isPowerOf2 == 0:
	print('Yes')
else:
	print('No')