import multiprocessing
import os
import time

def proc(n):
  time.sleep(n)
  
#creating processes
p0=multiprocessing.Process(target=proc,args=(2,))
p1=multiprocessing.Process(target=proc,args=(3,))
p2=multiprocessing.Process(target=proc,args=(6,))
p3=multiprocessing.Process(target=proc,args=(21,))

#Burst time for process
bursttime=[21,3,6,2]

#sorting just to compute sortest job first
burst.sort()

#storing intial time for all process with n+1 size
t=[0,0,0,0,0]

#intializing waiting time array of size n
wt=[0]*4

#intializing turn around time array
tt=[0]*4

#taking time at the beggining at t[0] rest of 
#all we take after a process end and t[j]-t[i]
#will compute the time taken to complete the process
t[0]=time.time()

#strating process p0
p0.start()
p0.join()

#taking time after process p0
t[1]=time.time()

#strating process p1
p1.start()
p1.join()

#taking time after process p1
t[2]=time.time()

#strating process p2
p2.start()
p2.join()

#taking time after process p2
t[3]=time.time()

#strating process p3
p3.start()
p3.join()

#taking time after process p3
t[4]=time.time()

i=0
while i<=4:
  tt[i]=t[i+1]-t[i]
  wt[i]=tt[i]-bursttime[i]
  i+=1
printf("Average waiting time:",sum(wt)/len(wt))

printf("Average turn around  time:",sum(tt)/len(tt))
