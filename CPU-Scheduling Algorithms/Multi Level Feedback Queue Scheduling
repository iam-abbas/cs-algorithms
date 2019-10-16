#include<stdio.h> 
 
#define N 10 
 
typedef struct 
{ 
      int process_id, arrival_time, burst_time, priority;
      int q, ready; 
}process_structure; 
 
int Queue(int t1) 
{ 
      if(t1 == 0 || t1 == 1 || t1 == 2 || t1 == 3) 
      { 
            return 1; 
      } 
      else
      {
            return 2; 
      }
} 
 
int main() 
{ 
      int limit, count, temp_process, time, j, y; 
      process_structure temp; 
      printf("Enter Total Number of Processes:\t"); 
      scanf("%d", &limit);  
      process_structure process[limit]; 
      for(count = 0; count < limit; count++) 
      { 
            printf("\nProcess ID:\t"); 
            scanf("%d", &process[count].process_id); 
            printf("Arrival Time:\t"); 
            scanf("%d", &process[count].arrival_time); 
            printf("Burst Time:\t"); 
            scanf("%d", &process[count].burst_time); 
            printf("Process Priority:\t"); 
            scanf("%d", &process[count].priority); 
            temp_process = process[count].priority; 
            process[count].q = Queue(temp_process);
            process[count].ready = 0; 
      }
      time = process[0].burst_time; 
      for(y = 0; y < limit; y++) 
      { 
            for(count = y; count < limit; count++) 
            { 
                  if(process[count].arrival_time < time) 
                  {
                        process[count].ready = 1; 
                  } 
            } 
            for(count = y; count < limit - 1; count++) 
            {
                  for(j = count + 1; j < limit; j++) 
                  { 
                        if(process[count].ready == 1 && process[j].ready == 1) 
                        { 
                              if(process[count].q == 2 && process[j].q == 1) 
                              { 
                                    temp = process[count]; 
                                    process[count] = process[j]; 
                                    process[j] = temp; 
                              } 
                        } 
                  } 
            } 
            for(count = y; count < limit - 1; count++) 
            { 
                  for(j = count + 1; j < limit; j++) 
                  {
                        if(process[count].ready == 1 && process[j].ready == 1) 
                        { 
                              if(process[count].q == 1 && process[j].q == 1) 
                              { 
                                    if(process[count].burst_time > process[j].burst_time) 
                                    { 
                                          temp = process[count]; 
                                          process[count] = process[j]; 
                                          process[j] = temp; 
                                    } 
                                    else 
                                    { 
                                          break; 
                                    } 
                              } 
                        } 
                  } 
            } 
            printf("\nProcess[%d]:\tTime:\t%d To %d\n", process[y].process_id, time, time + process[y].burst_time); 
            time = time + process[y].burst_time; 
            for(count = y; count < limit; count++) 
            { 
                  if(process[count].ready == 1) 
                  { 
                        process[count].ready = 0; 
                  } 
            } 
      } 
      return 0; 
}
