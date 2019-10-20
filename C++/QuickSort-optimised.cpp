#include<iostream> 
using namespace std; 

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition
        // If left part is smaller, then recur for left 
        // part and handle right part iteratively 
        if (pi - low < high - pi)
        {
                    quickSort(arr, low, pi - 1);
                    low = pi + 1;
        }
        else
        {
                    quickSort(arr, pi + 1, high);
                    high = pi - 1;
        }  
    }  
}
void print(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 
 
int main() 
{ 
    int n;
    cin >> n;
    int a[1000];
    for(int i = 0; i < n; i++) cin >> a[i];
    quickSort(a, 0, n - 1);
    print(a, n); 
    return 0; 
} 
