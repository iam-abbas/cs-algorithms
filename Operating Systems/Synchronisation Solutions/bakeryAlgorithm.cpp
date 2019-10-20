#include <iostream>
#include <pthread.h>
#include <map>

using namespace std;

// Bakery's Algorithm to synchronisation problem is many processes feasible
// solution. In this program I am using using threads in instead of 
// processes for better interaction between threads and use global variable
// easily.

int value = 0;

// Synchronisation public variables
map<pthread_t, int> choosing, number;

void delay (int time) {
	for (int i = 0; i < time * 10000000; i++);
}

int maxNumber () {
	map<pthread_t, int> :: iterator j;
	int maxx = 0;
	
	for (j = number.begin(); j != number.end(); j++) {
		if (j->second > maxx) {
			maxx = j->second;
		}
	}
	
	return maxx;
}

bool maxPair(int a1, int a2, int b1, int b2) {
	if (a1 < b1) {
		return 1;
	} else if (a1 > b2) {
		return 0;
	} else {
		if (a2 < b2) {
			return 1;
		} else {
			return 0;
		}
	}
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

void* thread(void* params) {

	int* p = (int*) params;
	int change = *p;

	int threadId = pthread_self();
	
	map<pthread_t, int> :: iterator j;

	for (int i = 0; i < 10; i++) {
		// Entry section 
		choosing[threadId] = 1;
		number[threadId] = maxNumber()+1;
		choosing[threadId] =  0;
		for (j = choosing.begin(); j != choosing.end(); j++) {
   			while(j->second);
   			while(number[j->first] && maxPair(number[j->first], j->first, number[threadId], threadId));
		}

		criticalSection(change, pthread_self());	

		//Exit Section
		number[threadId]=0;
	}
}

int main() {
	pthread_t threadId[3];

	int k0 = 10, k1 = 20, k2 = -5;
	pthread_create(&threadId[0], NULL, thread, (void*) &k0);
	pthread_create(&threadId[1], NULL, thread, (void*) &k1);
	pthread_create(&threadId[2], NULL, thread, (void*) &k2);
	
	pthread_join(threadId[0], NULL);
	pthread_join(threadId[1], NULL);
	pthread_join(threadId[2], NULL);

	printf ("\nvalue = %d\n", value);
	return 0;
}
