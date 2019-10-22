// Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands.
// We assume that the first card is already sorted then, we select an unsorted card. If the unsorted card is greater than the card in hand,
// it is placed on the right otherwise, to the left. In the same way, other unsorted cards are taken and put at their right place.

// A similar approach is used by insertion sort.

// Insertion sort is a sorting algorithm that places an unsorted element at its suitable place in each iteration.

#include<stdio.h>

void insert_sort(int* arr,int n);
//function uses inertion sort algorithm to sort the array in ascending order

void print_sorted_array(int *arr,int n);
//function to print the sorted array

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elements of the array :\n");
    for(int i = 0; i<n ;i++)
    {
        scanf("%d",&arr[i]);
    }

    insert_sort(arr,n);
    print_sorted_array(arr,n);
    return 0;
}

void print_sorted_array(int* arr,int n)
{
    printf("The sorted array: ");
    for(int i = 0; i<n; i++)
        printf("%d ",arr[i]);
}

void insert_sort(int* arr, int n)
{
    for(int i = 1; i<n; i++)
    {
        for(int j = i; arr[j]<arr[j-1] && j>=0; j--)
        {
            //elements of the array gets swapped if they aren't in ascending order.
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }
}



