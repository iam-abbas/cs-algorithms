# Python3 program for stable marriage problem 
import collections
import numpy as np
from random import randrange
import matplotlib.pyplot as plt
import math


def calculate(prefer,N,rank):
  cnt1=0
  cnt2=0
  cnt3=0
  a=[]
  i=0
  for i in range(len(couple)):
    if (prefer[N+i][rank]==couple[i]):
      cnt1=cnt1+1
      cnt3=cnt3+1
  i=0
  for i in range(len(couple)):
    if ((N+i)==prefer[couple[i]][rank]):
      cnt2=cnt2+1
      cnt3=cnt3+1 

  return cnt3      

def calculate2(prefer,N):
  cnt1=0
  cnt2=0
  cnt3=0
  a=[]
  i=0
  for i in range(len(couple)):
    j=0
    for j in range(len(prefer[N+i])):
      if (prefer[N+i][j]==couple[i]) and (j<(N/2)):
        cnt1=cnt1+1
        cnt3=cnt3+1
  i=0
  for i in range(len(couple)):
    j=0
    for j in range(len(prefer[i])):
      if ((N+i)==prefer[couple[i]][j]) and (j<(N/2)):
        cnt2=cnt2+1
        cnt3=cnt3+1 

  return cnt3

def calculate_woman(prefer,N,rank):
  cnt1=0
  cnt2=0
  cnt3=0
  a=[]
  i=0
  for i in range(len(couple)):
    if (prefer[N+i][rank]==couple[i]):
      cnt1=cnt1+1
      cnt3=cnt3+1

  i=0
  for i in range(len(couple)):
    if ((N+i)==prefer[couple[i]][rank]):
      cnt2=cnt2+1
      cnt3=cnt3+1 

  return cnt1  

def calculate_man(prefer,N,rank):
  cnt1=0
  cnt2=0
  cnt3=0
  a=[]
  i=0
  for i in range(len(couple)):
    if (prefer[N+i][rank]==couple[i]):
      cnt1=cnt1+1
      cnt3=cnt3+1

  i=0
  for i in range(len(couple)):
    if ((N+i)==prefer[couple[i]][rank]):
      cnt2=cnt2+1
      cnt3=cnt3+1 

  return cnt2

def autolabel(rects):
   #...................
    for rect in rects:
        height = rect.get_height()
        ax.annotate('{}'.format(height),
                    xy=(rect.get_x() + rect.get_width() / 2, height),
                    xytext=(0, 3),  
                    textcoords="offset points",
                    ha='center', va='bottom')
def autolabel2(rects):
   #...................
    for rect in rects:
        height = rect.get_height()
        ax2.annotate('{}'.format(height),
                    xy=(rect.get_x() + rect.get_width() / 2, height),
                    xytext=(0, 3), 
                    textcoords="offset points",
                    ha='center', va='bottom')        

def wPrefersM1OverM(prefer, w, m, m1,N): 
  
  # Check if w prefers m over her current engagment m1
  i=0 
  for i in range(N): 
    # If m1 comes before m in lisr of w, 
    # then w prefers her current engagement, don't do anything 
    if (prefer[w][i] == m1): 
      return True

    if (prefer[w][i] == m): 
      return False

# Prints stable matching for N boys and N girls.
'''
def stableMarriage(prefer,N): 
  
  # Stores partner of women. 
  wPartner = [-1 for i in range(N)] 

  # An array to store availability of men. 
  # If mFree[i] is false, then man 'i' is free, otherwise engaged. 
  mFree = [False for i in range(N)] 

  freeCount = N 

  # While there are free men 
  while (freeCount > 0): 
    
    # Pick the first free man (we could pick any) 
    m = 0
    while (m < N): 
      if (mFree[m] == False): 
        break
      m += 1

    # One by one go to all women according to 
    # m's preferences. Here m is the picked free man 
    i = 0
    while i < N and mFree[m] == False: 
      w = prefer[m][i] 

      # The woman of preference is free, w and m become partners (Note that 
      # the partnership maybe changed later). So we can say they are engaged not married 
      if (wPartner[w - N] == -1): 
        wPartner[w - N] = m 
        mFree[m] = True
        freeCount -= 1

      else: 
        
        # If w is not free ,Find current engagement of w 
        m1 = wPartner[w - N] 

        # If w prefers m over her current engagement m1, 
        # then break the engagement between w and m1 and engage m with w. 
        if (wPrefersM1OverM(prefer, w, m, m1,N) == False): 
          wPartner[w - N] = m 
          mFree[m] = True
          mFree[m1] = False
      i += 1

    

  # Print couple 
  for i in range(N):
    couple.append(wPartner[i]); 
    print(i, "\t", wPartner[i]) 
'''    

def randomMarriage(prefer,N,k):
  n2=int(N/k);
  # Stores partner of women. 
  wPartner = [-1 for i in range(N)] 

  # An array to store availability of men. 
  # If mFree[i] is false, then man 'i' is free, otherwise engaged. 
  mFree = [False for i in range(N)] 
  freeCount = N 
  # While there are free men 
  while (freeCount > 0): 
    
    # Pick the first free man (we could pick any) 
    m = 0
    if(freeCount==n2):
        break

   # print(f"freecount {freeCount}")
    while (m < N): 
      if (mFree[m] == False): 
        break
      m += 1

    # One by one go to all women according to 
    # m's preferences. Here m is the picked free man 
    i = 0
    while i < N and mFree[m] == False: 
      w = prefer[m][i] 

      # The woman of preference is free, w and m become partners (Note that 
      # the partnership maybe changed later). So we can say they are engaged not married 
      if (wPartner[w - N] == -1): 
        wPartner[w - N] = m 
        mFree[m] = True
        freeCount -= 1

      else: 
        
        # If w is not free ,Find current engagement of w 
        m1 = wPartner[w - N] 
        # If w prefers m over her current engagement m1, 
        # then break the engagement between w and m1 and engage m with w. 
        if (wPrefersM1OverM(prefer, w, m, m1,N) == False): 
          wPartner[w - N] = m 
          mFree[m] = True
          mFree[m1] = False
      i += 1
    if(freeCount==n2):
        break
#assigning new random................

  while (freeCount > 0): 
    
    # Pick the first free man (we could pick any) 
    m = 0
    while (m < N): 
      if (mFree[m] == False): 
        break
      m += 1

    # One by one go to all women according to 
    # m's preferences. Here m is the picked free man 
    
    while mFree[m] == False: 
      x=randrange(N)
      #print(f"random {x} free count {freeCount} ")
      w = prefer[m][x] 
      # The woman of preference is free, w and m become partners (Note that 
      # the partnership maybe changed later). So we can say they are engaged not married 
      if (wPartner[w - N] == -1): 
        wPartner[w - N] = m 
        mFree[m] = True
        freeCount -= 1     
      
  # Print couple 
  i=0
  for i in range(N):
    couple.append(wPartner[i]); 
    #print(i, "\t", wPartner[i])
# Driver Code for 
########################################################################
v=[]
v.append(5)
v.append(10)
v.append(50)
v.append(100)
v.append(200)
v.append(500)
bardata3=[]
bardata=[]
couple=[]
gh=0
for gh in range(len(v)):
  #print(f"{v[gh]} is number of women or men (equal no of man and woman)")
  N=v[gh]
  prefer=[]
  prefer2=[]
  man=[]
  woman=[]

  #print("enter men's priority")
  i=0
  for i in range(N):        
      a=[] 
      b=[]
    # print(f"the {i} men priority ")
      b=np.random.permutation(N)
      j=0
      for j in range(len(b)):
        a.append(b[j]+N)  
      prefer.append(a) 
      man.append(b)

#print("enter women's priority")
  i=0
  for i in range(N):          
      a =[] 
      #print(f" the {i} women priority ")
      a=np.random.permutation(N)
      prefer.append(a) 
      woman.append(a)

  '''    
  print("men's priority")
  i=0
  for i in range(0,N): 
      j=0
      for j in range(len(prefer[i])): 
          print(prefer[i][j]-N, end = " ") 
      print() 

  print("women's priority ")
  i=0
  for i in range(N,2*N):
      j=0 
      for j in range(len(prefer[i])): 
          print(prefer[i][j], end = " ") 
      print()   
  
  #print("Woman ", " Man") 
  '''
  couple.clear()
  i=0
  c1=0
  c2=0
  c3=0
  c4=0
  c11=0
  c22=0
  c33=0
  c44=0

  for i in range(100):
    #print("Zero random ")
    randomMarriage(prefer,N,N+1)
    c1=c1+calculate_woman(prefer,N,0)
    c11=c11+calculate_man(prefer,N,0)
    #print(couple)
    #print(f" c1 {c1}")
    couple.clear()
    #print("Half random ")
    randomMarriage(prefer,N,2)
    c2=c2+calculate_woman(prefer,N,0)
    c22=c22+calculate_man(prefer,N,0)
    #print(couple)
    #print(f" c2 {c2}")
    couple.clear()
    #print("1/3rd random ")
    randomMarriage(prefer,N,3)
    c3=c3+calculate_woman(prefer,N,0)
    c33=c33+calculate_man(prefer,N,0)
    #print(couple)
    #print(f" c3 {c3}")
    couple.clear()
    #print("full random ")
    randomMarriage(prefer,N,1)
    c4=c4+calculate_woman(prefer,N,0)
    c44=c44+calculate_man(prefer,N,0)
    #print(couple)
    #print(f" c4 {c4}")
    couple.clear()
    #print(f"{c1} {c2} {c3} {c4} c4---\n")
    #print(f"{c11} {c22} {c33} {c44} c44--\n")

  
  #print(f"{c1} {c2} {c3} {c4} women data\n")
  #print(f"{c11} {c22} {c33} {c44} men data\n")
  c1=math.ceil(c1/100)
  c2=math.ceil(c2/100)
  c3=math.ceil(c3/100)
  c4=math.ceil(c4/100)

  c11=math.ceil(c11/100)
  c22=math.ceil(c22/100)
  c33=math.ceil(c33/100)
  c44=math.ceil(c44/100)

  a=[]
  b=[]

  a.append(c1)
  a.append(c2)
  a.append(c3)
  a.append(c4)
  
  b.append(c11)
  b.append(c22)
  b.append(c33)
  b.append(c44)

  #print(a)
  #print(b)
  bardata.append(a)
  bardata3.append(b)
 
 

bardata2=[]
bardata22=[]

j=0
for j in range(4):
    ent=[]
    ent2=[]
    i=0
    for i in range(len(v)):
        ent.append(bardata[i][j])
        ent2.append(bardata3[i][j])
        #print(bardata[i][j],end=" ")
    bardata2.append(ent)
    bardata22.append(ent2)

print(" BAR DATA FOR WOMEN FIRST PREFERENCE \n")
i=0
for i in range(len(bardata2)):
    j=0
    for j in range(len(bardata2[i])):
        print(bardata2[i][j],end=" ")
    print("\n")

print(" BAR DATA FOR MEN FIRST PREFERENCE \n")
i=0
for i in range(len(bardata22)):
    j=0
    for j in range(len(bardata22[i])):
        print(bardata22[i][j],end=" ")
    print("\n")            


labels=[]
i=0
for i in range(len(v)):
  labels.append(str(v[i]))
  #print(v[i],end=" ")

# Add some text for labels, title and custom x-axis tick labels, etc.
x = np.arange(len(labels))  # the label locations
width = 0.20  # the width of the bars
fig, ax = plt.subplots()
rects1 = ax.bar(x +0.10, bardata2[0], width, label='DAA')
rects2 = ax.bar(x +0.30, bardata2[1], width, label='Half Random')
rects3 = ax.bar(x +0.50, bardata2[2], width, label='1/3rd Random')
rects4 = ax.bar(x +0.70, bardata2[3], width, label='Full Random')
# Add some text for labels, title and custom x-axis tick labels, etc.
ax.set_xlabel('NO OF WOMAN')
ax.set_ylabel('NO OF WOMAN GETTING THEIR FIRST PREFERENCE ')
ax.set_title('COMPARISON FOR DIFFERENT SETS OF DATA')
ax.set_xticks(x)
ax.set_xticklabels(labels)
ax.legend()
autolabel(rects1)
autolabel(rects2)
autolabel(rects3)
autolabel(rects4)
fig.tight_layout()
#bardat for womaan
#plt.show()
#bardata for man.....

labels2=[]
i=0
for i in range(len(v)):
  labels2.append(str(v[i]))
  #print(v[i],end=" ")


# Add some text for labels, title and custom x-axis tick labels, etc.
x2 = np.arange(len(labels2))  # the label locations
width = 0.20  # the width of the bars
fig2, ax2 = plt.subplots()
rects11 = ax2.bar(x2 +0.10, bardata22[0], width, label='Zero Random')
rects22 = ax2.bar(x2 +0.30, bardata22[1], width, label='Half Random')
rects33 = ax2.bar(x2 +0.50, bardata22[2], width, label='1/3rd Random')
rects44 = ax2.bar(x2 +0.70, bardata22[3], width, label='Full Random')
# Add some text for labels, title and custom x-axis tick labels, etc.
ax2.set_xlabel('NO OF MAN')
ax2.set_ylabel('NO OF MAN GETTING THEIR FIRST PREFERENCE')
ax2.set_title('COMPARISON FOR DIFFERENT SETS OF DATA')
ax2.set_xticks(x)
ax2.set_xticklabels(labels2)
ax2.legend()
autolabel2(rects11)
autolabel2(rects22)
autolabel2(rects33)
autolabel2(rects44)
fig2.tight_layout()
#plt.show()

############################################################
'''
print("NEW ALGOOOOOOOOOOOOOOOOO")
'''
for gh in range(4):
  N=10
  c1=0
  c2=0
  c3=0
  c4=0
  c5=0
  c6=0
  c7=0
  c11=0
  c22=0
  c33=0
  c44=0
  c55=0
  c66=0
  c77=0
  couple=[]
  #print(f"{N} is number of women or men (equal no of man and woman)")
  prefer=[]
  prefer2=[]
  man=[]
  woman=[]
  bardata2=[]

  #print("enter men's priority")

  for i in range(N):        
      a =[] 
      b=[]
    # print(f"the {i} men priority ")
      b=np.random.permutation(N)
      for j in range(len(b)):
        a.append(b[j]+N)  
      prefer.append(a) 
      man.append(b)

#print("enter women's priority")

  for i in range(N):          
      a =[] 
      #print(f" the {i} women priority ")
      a=np.random.permutation(N)
      prefer.append(a) 
      woman.append(a)
  '''
  print("men's priority")
  
  for i in range(0,N): 
      for j in range(len(prefer[i])): 
          print(prefer[i][j]-N, end = " ") 
      print() 

  print("women's priority ")

  for i in range(N,2*N): 
      for j in range(len(prefer[i])): 
          print(prefer[i][j], end = " ") 
      print()
  '''
  if gh==0:
    for zx in range(100):
      couple=[]       
      randomMarriage(prefer,N,N+1)
      c11=c11+calculate(prefer,N,0)
      c22=c22+calculate(prefer,N,1)
      c33=c33+calculate(prefer,N,2)
      c44=c44+calculate(prefer,N,3)
      c55=c55+calculate(prefer,N,4)
      c66=c66+calculate(prefer,N,N-1)
      c77=c77+calculate2(prefer,N)

    c1=math.ceil(c11/100)
    c2=math.ceil(c22/100)
    c3=math.ceil(c33/100) 
    c4=math.ceil(c44/100)
    c5=math.ceil(c55/100)
    c6=math.ceil(c66/100)
    c7=math.ceil(c77/100)

    bardata=[]
    bardata2=[]
    bardata.append(c1)
    bardata.append(c2)
    bardata.append(c3)
    bardata.append(c4)
    bardata.append(c5)
    bardata.append(c6)
    bardata.append(c7)
    bardata2.append(bardata)
    labels=[]
    labels.append(str(1))
    labels.append(str(2))
    labels.append(str(3))
    labels.append(str(4))
    labels.append(str(5))
    labels.append("LAST")
    labels.append("FIRST HALF")
    print(" BAR DATA FOR DAA FOR FIRST SECOND UPTO HALF AND LAST \n")
    i=0
    for i in range(len(bardata2)):
      j=0
      for j in range(len(bardata2[i])):
        print(bardata2[i][j],end=" ")
      print("\n")    

# Add some text for labels, title and custom x-axis tick labels, etc.
    x = np.arange(len(labels))  # the label locations
    width = 0.20  # the width of the bars
    fig, ax = plt.subplots()
    rects1 = ax.bar(x +0.10, bardata2[0], width, label='DAA')
# Add some text for labels, title and custom x-axis tick labels, etc.
    ax.set_xlabel('PREFERENCE')
    ax.set_ylabel('NO OF PEOPLE')
    ax.set_title('COMPARISON FOR DIFFERENT SETS OF DATA')
    ax.set_xticks(x)
    ax.set_xticklabels(labels)
    ax.legend()
    autolabel(rects1)
    fig.tight_layout()
    #plt.show()

  if gh==1:    
    for zx in range(100):  
      couple=[]     
      randomMarriage(prefer,N,2)
      c11=c11+calculate(prefer,N,0)
      c22=c22+calculate(prefer,N,1)
      c33=c33+calculate(prefer,N,2)
      c44=c44+calculate(prefer,N,3)
      c55=c55+calculate(prefer,N,4)
      c66=c66+calculate(prefer,N,N-1)
      c77=c77+calculate2(prefer,N)
      
  
    c1=math.ceil(c11/100)
    c2=math.ceil(c22/100)
    c3=math.ceil(c33/100) 
    c4=math.ceil(c44/100)
    c5=math.ceil(c55/100)
    c6=math.ceil(c66/100)
    c7=math.ceil(c77/100)

    bardata2=[]
    bardata=[]
    bardata.append(c1)
    bardata.append(c2)
    bardata.append(c3)
    bardata.append(c4)
    bardata.append(c5)
    bardata.append(c6)
    bardata.append(c7)
    bardata2.append(bardata)
    labels=[]
    labels.append(str(1))
    labels.append(str(2))
    labels.append(str(3))
    labels.append(str(4))
    labels.append(str(5))
    labels.append("LAST")
    labels.append("FIRST HALF")
    print(" BAR DATA FOR HALF RANDOM FOR FIRST SECOND UPTO HALF AND LAST \n")

    i=0
    for i in range(len(bardata2)):
      j=0
      for j in range(len(bardata2[i])):
        print(bardata2[i][j],end=" ")
      print("\n")
# Add some text for labels, title and custom x-axis tick labels, etc.
    x = np.arange(len(labels))  # the label locations
    width = 0.20  # the width of the bars
    fig, ax = plt.subplots()
    rects1 = ax.bar(x +0.10, bardata2[0], width, label='Half Random')
# Add some text for labels, title and custom x-axis tick labels, etc.
    ax.set_xlabel('PREFERENCE')
    ax.set_ylabel('NO OF PEOPLE')
    ax.set_title('COMPARISON FOR DIFFERENT SETS OF DATA')
    ax.set_xticks(x)
    ax.set_xticklabels(labels)
    ax.legend()
    autolabel(rects1)
    fig.tight_layout()
    #plt.show()
  if gh==2:   
    couple=[]    
    for zx in range(100):  
      couple=[]     
      randomMarriage(prefer,N,3)
      c11=c11+calculate(prefer,N,0)
      c22=c22+calculate(prefer,N,1)
      c33=c33+calculate(prefer,N,2)
      c44=c44+calculate(prefer,N,3)
      c55=c55+calculate(prefer,N,4)
      c66=c66+calculate(prefer,N,N-1)
      c77=c77+calculate2(prefer,N)

 
    c1=math.ceil(c11/100)
    c2=math.ceil(c22/100)
    c3=math.ceil(c33/100) 
    c4=math.ceil(c44/100)
    c5=math.ceil(c55/100)
    c6=math.ceil(c66/100)
    c7=math.ceil(c77/100)
      
    bardata=[]
    bardata.append(c1)
    bardata.append(c2)
    bardata.append(c3)
    bardata.append(c4)
    bardata.append(c5)
    bardata.append(c6)
    bardata.append(c7)
    bardata2.append(bardata)
    labels=[]
    labels.append(str(1))
    labels.append(str(2))
    labels.append(str(3))
    labels.append(str(4))
    labels.append(str(5))
    labels.append("LAST")
    labels.append("FIRST HALF")
    print(" BAR DATA FOR 1/3RD RANDOM FOR FIRST SECOND UPTO HALF AND LAST \n")

    i=0
    for i in range(len(bardata2)):
      j=0
      for j in range(len(bardata2[i])):
        print(bardata2[i][j],end=" ")
      print("\n")

# Add some text for labels, title and custom x-axis tick labels, etc.
    x = np.arange(len(labels))  # the label locations
    width = 0.20  # the width of the bars
    fig, ax = plt.subplots()
    rects1 = ax.bar(x +0.10, bardata2[0], width, label='1/3rd Random')
# Add some text for labels, title and custom x-axis tick labels, etc.
    ax.set_xlabel('PREFERENCE')
    ax.set_ylabel('NO OF PEOPLE')
    ax.set_title('COMPARISON FOR DIFFERENT SETS OF DATA')
    ax.set_xticks(x)
    ax.set_xticklabels(labels)
    ax.legend()
    autolabel(rects1)
    fig.tight_layout()
    #plt.show()

  if gh==3:   
    couple=[]    
    for zx in range(100):
      couple=[]       
      randomMarriage(prefer,N,1)
      c11=c11+calculate(prefer,N,0)
      c22=c22+calculate(prefer,N,1)
      c33=c33+calculate(prefer,N,2)
      c44=c44+calculate(prefer,N,3)
      c55=c55+calculate(prefer,N,4)
      c66=c66+calculate(prefer,N,N-1)
      c77=c77+calculate2(prefer,N)

    
    c1=math.ceil(c11/100)
    c2=math.ceil(c22/100)
    c3=math.ceil(c33/100) 
    c4=math.ceil(c44/100)
    c5=math.ceil(c55/100)
    c6=math.ceil(c66/100)
    c7=math.ceil(c77/100)

    bardata=[]
    bardata2=[]
    bardata.append(c1)
    bardata.append(c2)
    bardata.append(c3)
    bardata.append(c4)
    bardata.append(c5)
    bardata.append(c6)
    bardata.append(c7)
    bardata2.append(bardata)
    labels=[]
    labels.append(str(1))
    labels.append(str(2))
    labels.append(str(3))
    labels.append(str(4))
    labels.append(str(5))
    labels.append("LAST")
    labels.append("FIRST HALF")
    print(" BAR DATA FOR FULL RANDOM FOR FIRST SECOND UPTO HALF AND LAST \n")

    i=0
    for i in range(len(bardata2)):
      j=0
      for j in range(len(bardata2[i])):
        print(bardata2[i][j],end=" ")
      print("\n")

# Add some text for labels, title and custom x-axis tick labels, etc.
    x = np.arange(len(labels))  # the label locations
    width = 0.20  # the width of the bars
    fig, ax = plt.subplots()
    rects1 = ax.bar(x +0.10, bardata2[0], width, label='Full Random')
# Add some text for labels, title and custom x-axis tick labels, etc.
    ax.set_xlabel('PREFERENCE')
    ax.set_ylabel('NO OF PEOPLE')
    ax.set_title('COMPARISON FOR DIFFERENT SETS OF DATA')
    ax.set_xticks(x)
    ax.set_xticklabels(labels)
    ax.legend()
    autolabel(rects1)
    fig.tight_layout()
    #plt.show()  
plt.show()






#############################################################
''' for assigning from second side (woman side )............
print("...FOR SECOND TURN ...")


for i in range(N): 
    a=[]
    for j in range(len(woman[i])): 
        a.append(woman[i][j]+N) 
    prefer2.append(a)

for i in range(N): 
    a=[]
    for j in range(len(man[i])): 
        a.append(man[i][j]) 
    prefer2.append(a)     

print("women's priority ")
for i in range(0,N): 
    for j in range(len(prefer2[i])): 
        print(prefer2[i][j]-N,end = " ") 
    print() 

print("man's priority ")
for i in range(N,2*N): 
    for j in range(len(prefer2[i])): 
        print(prefer2[i][j], end = " ") 
    print()  

print("Man ", "Woman") 
stableMarriage(prefer2,N)  
''' 



