// CPP program to implement preemptive priority scheduling 
#include <bits/stdc++.h> 
using namespace std; 

struct Process { 
	int processID; 
	int burstTime; 
	int tempburstTime; 
	int responsetime; 
	int arrivalTime; 
	int priority; 
	int outtime; 
	int intime; 
}; 

// It is used to include all the valid and eligible 
// processes in the heap for execution. heapsize defines 
// the number of processes in execution depending on 
// the current time currentTime keeps a record of 
// the current CPU time. 
void insert(Process Heap[], Process value, int* heapsize, 
			int* currentTime) 
{ 
	int start = *heapsize, i; 
	Heap[*heapsize] = value; 
	if (Heap[*heapsize].intime == -1) 
		Heap[*heapsize].intime = *currentTime; 
	++(*heapsize); 

	// Ordering the Heap 
	while (start != 0 && Heap[(start - 1) / 2].priority > 
								Heap[start].priority) { 
		Process temp = Heap[(start - 1) / 2]; 
		Heap[(start - 1) / 2] = Heap[start]; 
		Heap[start] = temp; 
		start = (start - 1) / 2; 
	} 
} 

// It is used to reorder the heap according to 
// priority if the processes after insertion 
// of new process. 
void order(Process Heap[], int* heapsize, int start) 
{ 
	int smallest = start; 
	int left = 2 * start + 1; 
	int right = 2 * start + 2; 
	if (left < *heapsize && Heap[left].priority < 
							Heap[smallest].priority) 
		smallest = left; 
	if (right < *heapsize && Heap[right].priority < 
						Heap[smallest].priority) 
		smallest = right; 

	// Ordering the Heap 
	if (smallest != start) { 
		Process temp = Heap[smallest]; 
		Heap[smallest] = Heap[start]; 
		Heap[start] = temp; 
		order(Heap, heapsize, smallest); 
	} 
} 

// This function is used to find the process with 
// highest priority from the heap. It also reorders 
// the heap after extracting the highest priority process. 
Process extractminimum(Process Heap[], int* heapsize, 
					int* currentTime) 
{ 
	Process min = Heap[0]; 
	if (min.responsetime == -1) 
		min.responsetime = *currentTime - min.arrivalTime; 
	--(*heapsize); 
	if (*heapsize >= 1) { 
		Heap[0] = Heap[*heapsize]; 
		order(Heap, heapsize, 0); 
	} 
	return min; 
} 

// Compares two intervals according to staring times. 
bool compare(Process p1, Process p2) 
{ 
	return (p1.arrivalTime < p2.arrivalTime); 
} 

// This function is responsible for executing 
// the highest priority extracted from Heap[]. 
void scheduling(Process Heap[], Process array[], int n, 
				int* heapsize, int* currentTime) 
{ 
	if (heapsize == 0) 
		return; 

	Process min = extractminimum(Heap, heapsize, currentTime); 
	min.outtime = *currentTime + 1; 
	--min.burstTime; 
	printf("process id = %d current time = %d\n", 
		min.processID, *currentTime); 

	// If the process is not yet finished 
	// insert it back into the Heap*/ 
	if (min.burstTime > 0) { 
		insert(Heap, min, heapsize, currentTime); 
		return; 
	} 

	for (int i = 0; i < n; i++) 
		if (array[i].processID == min.processID) { 
			array[i] = min; 
			break; 
		} 
} 

// This function is responsible for 
// managing the entire execution of the 
// processes as they arrive in the CPU 
// according to their arrival time. 
void priority(Process array[], int n) 
{ 
	sort(array, array + n, compare); 

	int totalwaitingtime = 0, totalbursttime = 0, 
		totalturnaroundtime = 0, i, insertedprocess = 0, 
		heapsize = 0, currentTime = array[0].arrivalTime, 
		totalresponsetime = 0; 

	Process Heap[4 * n]; 

	// Calculating the total burst time 
	// of the processes 
	for (int i = 0; i < n; i++) { 
		totalbursttime += array[i].burstTime; 
		array[i].tempburstTime = array[i].burstTime; 
	} 

	// Inserting the processes in Heap 
	// according to arrival time 
	do { 
		if (insertedprocess != n) { 
			for (i = 0; i < n; i++) { 
				if (array[i].arrivalTime == currentTime) { 
					++insertedprocess; 
					array[i].intime = -1; 
					array[i].responsetime = -1; 
					insert(Heap, array[i], &heapsize, ¤tTime); 
				} 
			} 
		} 
		scheduling(Heap, array, n, &heapsize, ¤tTime); 
		++currentTime; 
		if (heapsize == 0 && insertedprocess == n) 
			break; 
	} while (1); 

	for (int i = 0; i < n; i++) { 
		totalresponsetime += array[i].responsetime; 
		totalwaitingtime += (array[i].outtime - array[i].intime - 
										array[i].tempburstTime); 
		totalbursttime += array[i].burstTime; 
	} 
	printf("Average waiting time = %f\n", 
		((float)totalwaitingtime / (float)n)); 
	printf("Average response time =%f\n", 
		((float)totalresponsetime / (float)n)); 
	printf("Average turn around time = %f\n", 
		((float)(totalwaitingtime + totalbursttime) / (float)n)); 
} 

// Driver code 
int main() 
{ 
	int n, i; 
	Process a[5]; 
	a[0].processID = 1; 
	a[0].arrivalTime = 4; 
	a[0].priority = 2; 
	a[0].burstTime = 6; 
	a[1].processID = 4; 
	a[1].arrivalTime = 5; 
	a[1].priority = 1; 
	a[1].burstTime = 3; 
	a[2].processID = 2; 
	a[2].arrivalTime = 5; 
	a[2].priority = 3; 
	a[3].burstTime = 7; 
	a[3].processID = 3; 
	a[3].arrivalTime = 1; 
	a[3].priority = 4; 
	a[3].burstTime = 2; 
	a[4].processID = 5; 
	a[4].arrivalTime = 3; 
	a[4].priority = 5; 
	a[4].burstTime = 4; 
	priority(a, 5); 
	return 0; 
} 
