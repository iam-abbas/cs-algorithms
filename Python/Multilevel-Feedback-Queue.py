class process:
    def __init__(self,process_id,arrival_time,burst_time,priority,q,ready):
        self.process_id=process_id
        self.arrival_time=arrival_time
        self.burst_time=burst_time
        self.priority=priority
        self.ready=ready
        self.q=q
    
    
def Queue(t1):
    t1=int(t1)
    if(t1==0 or t1==1 or t1==2 or t1==3):
        return 1
    else:
        return 2


limit=int(input("Enter Total Number of Processes:"))

Process=[]
for i in range(limit):
    pid=int(input("Process ID:"))
    time=int(input("Arrival Time:"))
    btime=int(input("Burst Time:"))
    priority=int(input("Process Priority:"))
    q=Queue(priority)
    ready=0
    Process_1=process(process_id=pid,arrival_time=time,burst_time=btime,priority=priority,q=q,ready=ready)
    Process.append(Process_1)

time=Process[0].burst_time
for i in range(limit):
    for count in range(limit):
        if Process[count].arrival_time<time:
            Process[count].ready=1
    for count in range(i,limit-1):
        for j in range(count+1,limit):
            if Process[count].ready==1 and Process[j].ready==1:
                if Process[count].q==2 and Process[j].q ==1:
                    temp=Process[count]
                    Process[count]=Process[j]
                    Process[j]=temp
    for count in range(i,limit-1):
        for j in range(count+1,limit):
            if Process[count].ready==1 and Process[j].ready==1:
                if Process[count].q==1 and Process[j].q==1:
                    if Process[count].burst_time>Process[j].burst_time:
                        temp=Process[count]
                        Process[count]=Process[j]
                        Process[j]=temp
                    else:
                        break

    print("\nProcess[%d]:\tTime:\t%d To %d\n" %(Process[i].process_id, time, time + Process[i].burst_time))
    time=time+Process[i].burst_time
    for count in range(i,limit):
        if Process[count].ready==1:
            Process[count].ready=0