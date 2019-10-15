
#this program doesn't use inbuild list functions except append

def insertion(arr): #inserting an element at a particular index of the list
	global n
	x = int(input("postion :"))
	y = int(input("element :"))
	arr.append(arr[-1])
	for i in range(n-1,x,-1):
		arr[i] =arr[i-1]
	arr[x] = y
	n = n+1 #incrementing the list size variable


n =int(input('No. of elements : '))
arr = []
print("Input the elements of the list\n")
for i in range(n):
	x =int(input())
	arr.append(x)


insertion(arr)
print(arr)
