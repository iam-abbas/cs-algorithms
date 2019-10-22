/* In Linear search, we search an element or value in a given array by traversing the array from the starting,
till the desired element or value is found.
If the desired element is found, the index position is displayed, else -1 is displayed.*/

#include<stdio.h>

int linear_search(int* arr, int ele, int n);
// function returns the index position if the element is found, else return -1

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elements of the array: \n");
    for(int i = 0; i<n; i++)
        scanf("%d",&arr[i]);

    int ele;
    printf("Enter the element to be searched: ");
    scanf("%d",&ele);

    int pos = linear_search(arr,ele,n);

    if(pos==-1) printf("%d not found.",ele);
    else printf("%d found at index position %d",ele,pos);

    return 0;
}


int linear_search(int* arr, int ele, int n)
{
    for(int i = 0; i<n; i++)
        if(arr[i]==ele) return i;

    return -1;
}