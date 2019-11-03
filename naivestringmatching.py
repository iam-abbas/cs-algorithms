def funtion(txt,pat):
	n=len(txt)
	m=len(pat)
	for i in range(n-m+1):
		for j in range(m):
			if(txt[i+j]!=pat[j]):
				break
			else:
				j+=1
		if(j==m):
			print("Found at:",i)


if __name__ == '__main__':
	txt="SouravMondalSM"
	pat="SM"
	funtion(txt,pat)
