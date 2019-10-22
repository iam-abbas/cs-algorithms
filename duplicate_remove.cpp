#include<stdio.h>
#include<conio.h>
int main()
{
	int arr[10], i, j, k, Size;
	
	printf("\n Enter size of array :");
	scanf("%d",&Size);
	
	printf("\n Enter array elements:");
	for (i = 0; i<Size; i++)
	{
    	scanf("%d", &arr[i]);
   	}     
	for (i = 0; i<Size; i++)
	{
	for(j = i + 1; j < Size; j++)
	{
    	if(arr[i] == arr[j])
    	{
    	for(k = j; k < Size; k++)
    	{
    	arr[k] = arr[k + 1];
	}
	Size--;
	j--;
   }	}
}
 	printf("\n Final Array:\n");
 	for (i=0;i<Size;i++)
  	{
 		printf("%d\t", arr[i]);
  	}	     
getch();

 	return 0;
}

