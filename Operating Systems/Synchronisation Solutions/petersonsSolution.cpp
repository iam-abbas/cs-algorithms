#include <iostream>
#include <pthread.h>

using namespace std;

// Peterson's solution to synchronisation problem is 2 process feasible
// solution. In this program I am using using 2 threads in instead of 
// processes.

int value = 0;

// Synchronisation public variables
int flag[2], turn = 0;

void delay (int time) {
	for (int i = 0; i < time * 100000000; i++);
}

void criticalSection(int change, int thread) {
	printf ("\nRead by thread: %d", thread);
	int k = value;
	
	delay (1);
	
	printf ("\nCalculate by thread: %d", thread);
	k = k+change;
	
	delay (2);
	
	printf ("\nStore by thread: %d", thread);
	value = k;
}

void* thread0(void* params) {

	for (int i = 0; i < 10; i++) {
		// Entry section 
		flag[0] = 1;
		turn = 1;
		while (flag[1] && turn == 1);

		criticalSection(100, 0);	

		//Exit Section
		flag[0] = 0;
	}
}

void* thread1(void* params) {

	for (int i = 0; i < 10; i++) {
		// Entry section 
		flag[1] = 1;
		turn = 0;
		while (flag[0] && turn == 0);

		criticalSection(-20, 1);	

		//Exit Section
		flag[1] = 0;
	}
}

int main() {
	pthread_t threadId[2];

	pthread_create(&threadId[0], NULL, thread0, NULL);

	pthread_create(&threadId[1], NULL, thread1, NULL);

	pthread_join(threadId[0], NULL);
	pthread_join(threadId[1], NULL);


	printf ("\nvalue = %d\n", value);
	return 0;
}
