// A C++ program to find k'th smallest element using max heap 
#include<iostream> 
#include<climits> 
using namespace std; 

// Prototype of a utility function to swap two integers 
void swap(int *x, int *y); 

// A class for Max Heap 
class MaxHeap 
{ 
	int *harr; // pointer to array of elements in heap 
	int capacity; // maximum possible size of max heap 
	int heap_size; // Current number of elements in max heap 
public: 
	MaxHeap(int a[], int size); // Constructor 
	void maxHeapify(int i); //To maxHeapify subtree rooted with index i 
	int parent(int i) { return (i-1)/2; } 
	int left(int i) { return (2*i + 1); } 
	int right(int i) { return (2*i + 2); } 

	int extractMax(); // extracts root (maximum) element 
	int getMax() { return harr[0]; } // Returns maximum 

	// to replace root with new node x and heapify() new root 
	void replaceMax(int x) { harr[0] = x; maxHeapify(0); } 
}; 

MaxHeap::MaxHeap(int a[], int size) 
{ 
	heap_size = size; 
	harr = a; // store address of array 
	int i = (heap_size - 1)/2; 
	while (i >= 0) 
	{ 
		maxHeapify(i); 
		i--; 
	} 
} 

// Method to remove maximum element (or root) from max heap 
int MaxHeap::extractMax() 
{ 
	if (heap_size == 0) 
		return INT_MAX; 

	// Store the maximum vakue. 
	int root = harr[0]; 

	// If there are more than 1 items, move the last item to root 
	// and call heapify. 
	if (heap_size > 1) 
	{ 
		harr[0] = harr[heap_size-1]; 
		maxHeapify(0); 
	} 
	heap_size--; 

	return root; 
} 

// A recursive method to heapify a subtree with root at given index 
// This method assumes that the subtrees are already heapified 
void MaxHeap::maxHeapify(int i) 
{ 
	int l = left(i); 
	int r = right(i); 
	int largest = i; 
	if (l < heap_size && harr[l] > harr[i]) 
		largest = l; 
	if (r < heap_size && harr[r] > harr[largest]) 
		largest = r; 
	if (largest != i) 
	{ 
		swap(&harr[i], &harr[largest]); 
		maxHeapify(largest); 
	} 
} 

// A utility function to swap two elements 
void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

// Function to return k'th largest element in a given array 
int kthSmallest(int arr[], int n, int k) 
{ 
	// Build a heap of first k elements: O(k) time 
	MaxHeap mh(arr, k); 

	// Process remaining n-k elements. If current element is 
	// smaller than root, replace root with current element 
	for (int i=k; i<n; i++) 
		if (arr[i] < mh.getMax()) 
		mh.replaceMax(arr[i]); 

	// Return root 
	return mh.getMax(); 
} 

// Driver program to test above methods 
int main() 
{ 
	int arr[] = {12, 3, 5, 7, 19}; 
	int n = sizeof(arr)/sizeof(arr[0]), k = 4; 
	cout << "K'th smallest element is " << kthSmallest(arr, n, k); 
	return 0; 
}
