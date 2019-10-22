// C++ program for Huffman Coding 
#include <bits/stdc++.h> 
using namespace std; 

// A Huffman tree node 
struct min_heap_node { 

	// One of the input characters 
	char data; 

	// Frequency of the character 
	unsigned freq; 

	// Left and right child 
	min_heap_node *left, *right; 

	min_heap_node(char data, unsigned freq) 

	{ 

		left = right = NULL; 
		this->data = data; 
		this->freq = freq; 
	} 
}; 

// For comparison of 
// two heap nodes (needed in min heap) 
struct compare { 

	bool operator()(min_heap_node* l, min_heap_node* r) 

	{ 
		return (l->freq > r->freq); 
	} 
}; 

// Prints huffman codes from 
// the root of Huffman Tree. 
void print_codes(struct min_heap_node* root, string str) 
{ 

	if (!root) 
		return; 

	if (root->data != '$') 
		cout << root->data << ": " << str << "\n"; 

	print_codes(root->left, str + "0"); 
	print_codes(root->right, str + "1"); 
} 

// The main function that builds a Huffman Tree and 
// print codes by traversing the built Huffman Tree 
void huff_code(char data[], int freq[], int size) 
{ 
	struct min_heap_node *left, *right, *top; 

	// Create a min heap & inserts all characters of data[] 
	priority_queue<min_heap_node*, vector<min_heap_node*>, compare> min_heap; 

	for (int i = 0; i < size; ++i) 
		min_heap.push(new min_heap_node(data[i], freq[i])); 

	// Iterate while size of heap doesn't become 1 
	while (min_heap.size() != 1) { 

		// Extract the two minimum 
		// freq items from min heap 
		left = min_heap.top(); 
		min_heap.pop(); 

		right = min_heap.top(); 
		min_heap.pop(); 

		// Create a new internal node with 
		// frequency equal to the sum of the 
		// two nodes frequencies. Make the 
		// two extracted node as left and right children 
		// of this new node. Add this node 
		// to the min heap '$' is a special value 
		// for internal nodes, not used 
		top = new min_heap_node('$', left->freq + right->freq); 

		top->left = left; 
		top->right = right; 

		min_heap.push(top); 
	} 

	// Print Huffman codes using 
	// the Huffman tree built above 
	print_codes(min_heap.top(), ""); 
} 

// Driver program to test above functions 
int main() 
{ 

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
	int freq[] = { 5, 9, 12, 13, 16, 45 }; 

	int size = sizeof(arr) / sizeof(arr[0]); 

	huff_code(arr, freq, size); 

	return 0; 
} 

// This code is contributed by Aditya Goel 
