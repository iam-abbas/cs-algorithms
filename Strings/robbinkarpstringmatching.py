import math
d = 256
def search(pat, txt, q): 
	M = len(pat) 
	N = len(txt) 
	p = 0 
	t = 0 
	h = pow(d,M-1)%q
	for i in range(M): 
		p = (d*p + ord(pat[i]))%q 
		t = (d*t + ord(txt[i]))%q 
	for i in range(N-M+1): 
		if p==t: 
			for j in range(M): 
				if txt[i+j] != pat[j]: 
					break

			j+=1
			if j==M: 
				print ("Pattern found at index " ,i)
		if i < N-M: 
			t = (d*(t-ord(txt[i])*h) + ord(txt[i+M]))%q 
			if t < 0: 
				t = t+q 
txt = "Sourav Mondal SM"
pat = "SM"
q = 101 
search(pat,txt,q) 
