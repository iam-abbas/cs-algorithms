#ifndef HEAPSORT_HEAPSORT_H_
#define HEAPSORT_HEAPSORT_H_

//Helper macros to access left,right child and parent
#define RIGHT(i) ((i<<1)+2) 
#define LEFT(i) ((i<<1)+1)
#define PARENT(i) ((i-1)>>1)

class HeapSort:{

private:
	int heapSize;
	void maxHeapify(int* arr, int idx);
	void buildMaxHeap(int* arr, int size);
public:
	HeapSort();
	virtual void sort(int* arr, int size);
	virtual ~HeapSort();
};

#endif /* HEAPSORT_HEAPSORT_H_ */
