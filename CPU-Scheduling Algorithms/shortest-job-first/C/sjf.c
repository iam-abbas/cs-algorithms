#include<stdio.h>

struct process { // structure of a process.
int burst_time;
int waiting_time;
int turnaround_time;
int process_id;
};
struct process read(int i) { //function that returns a process with a process id and burst_time
struct process p;
p.process_id = i+1;
scanf("%d",&p.burst_time);
return p;
}
int calc_waitingtime(int burst_time, int process_id, int waiting_time) { //function that calculates and returns waiting_time of a process
  int time ;
  time = waiting_time + burst_time;
  return time;
}
int main() {
  int n, i, avg_waitingtime, avg_turnaroundtime=0, j;
  struct process p[50];
  printf("enter number of processes you want");
  scanf("%d",&n);
  for(i=0; i < n; i++) {
    printf("enter burst time of the process p[%d]",i);
    p[i] = read(i);
  }
  for(i=0; i < n-1; i++) { //sort the process in ascending order of their burst_time
    for(j=0 ; j< n-i-1; j++) {
      if(p[j].burst_time > p[j+1].burst_time) {
        struct process rep;
        rep = p[j];
        p[j] = p[j+1];
        p[j+1] = rep;
      }
    }
  }
  for(i=0; i < n ; i++) {
    if(i==0)
      p[i].waiting_time = 0;
    else {
      p[i].waiting_time = calc_waitingtime(p[i-1].burst_time, p[i].process_id, p[i-1].waiting_time);
      p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
  }
  printf("\nProcess_id Burst Time Waiting Time Turnaround Time");
  for(i=0 ; i < n ; i++) {
    printf("\n%d\t%d\t%d\t\t%d",p[i].process_id,p[i].burst_time,p[i].waiting_time,p[i].turnaround_time);
    avg_waitingtime = avg_waitingtime + p[i].waiting_time;
    avg_turnaroundtime = avg_turnaroundtime + p[i].turnaround_time;
  }
  printf("\naverage waiting time : %f\naverage turn around time : %f\n",(float)avg_waitingtime/n,(float)avg_turnaroundtime/n);
}
