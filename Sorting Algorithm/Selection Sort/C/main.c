#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int size)
{
	int count, minIndex, minValue, i;
	for(count=0; count<size-1; count++)
	{
	minIndex = count;
	minValue = arr[count];
	for(i=count+1; i<size; i++){
		if(arr[i] < minValue)
		{
			minValue = arr[i];
			minIndex = i;
		}
	}
		arr[minIndex] = arr[count];
		arr[count] = minValue;
	}
    printf("sorted array:");
   for(i=0; i<size; i++)
        {
            printf("%d ,",arr[i]);
        }
}

int main()
{
    int size,key,k;
    printf("input the size of the array:");
    scanf("%d",&size);
    int data[size];
    for(k=0;k<size;k++)
    {
        printf("input %d element of the array:",k+1);
        scanf("%d",&data[k]);
    }
    selectionSort(data,size);
}
