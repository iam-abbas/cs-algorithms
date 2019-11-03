if __name__ == '__main__':
	m=int(input("Enter number of machines:"))
	n=int(input("Enter number of jobs:"))
	t=[]
	for i in range(n):
		print("Enter time to complete jon no ",i+1)
		a=int(input())
		t.append(a)
	#print(t)
	M=[0]*m
	k=0
	#print(M)
	for j in range(m):
		if M[j]==0:
			M[j]+=t[k]
			k=k+1
	#print(M)
	for i in range(n-m):
		x=min(M)
		for l in range(m):
			if M[l]==x:
				z=l
		#print(l)
		M[z]+=t[k]
		k=k+1
	print("Max span= %d"%max(M))



