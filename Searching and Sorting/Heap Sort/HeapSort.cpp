#include "HeapSort.h"
#include <algorithm>

HeapSort::HeapSort() {
	heapSize = 0;
}

HeapSort::~HeapSort() {};
void HeapSort::sort(int* arr, int size) {

	buildMaxHeap(arr, size);
	for (int i = size - 1; i > 0; --i) {
		//arr[0] is the largest element in heap, put it in the end
		std::swap(arr[0], arr[i]);

		//heap size is decreased after removing an element
		--heapSize;

		//heap is corrupted now, fix it
		maxHeapify(arr, 0);
	}

}

void HeapSort::maxHeapify(int* arr, int idx) {

	while (1) {
		int left = LEFT(idx);
		int right = RIGHT(idx);

		int largestIdx = idx;

		//get max element from me,my left child, my right child
		if (left < heapSize && arr[left] > arr[largestIdx])
			largestIdx = left;

		if (right < heapSize && arr[right] > arr[largestIdx])
			largestIdx = right;

		if (largestIdx == idx) //now it remains heap property
			break;

		//arr[largestIdx] now contains the smaller element to be pushed down
		std::swap(arr[idx], arr[largestIdx]);
		idx = largestIdx;
	}
}

void HeapSort::buildMaxHeap(int* arr, int size) {
	heapSize = size;
	for (int i = ((size) >> 1) - 1; i >= 0; --i)
		maxHeapify(arr, i);
}
