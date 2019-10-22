#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

 void  main()
 {
 int i,j,n,temp;
 int *arr = (int *)malloc(n*sizeof(int));
 clrscr();
 printf("\nEnter size of the array:");
 scanf("%d",&n);

 printf("\nEnter elements of the array:");
 for(i=0;i<n;i++)
 scanf("%d",&arr[i]);

printf("\nBefor sorting:");
for( i=0;i<n;i++)
{
   printf("\t%d",arr[i]);

}
for(i =0;i<n-1;i++)
{
    for( j =0;j<n-i-1;j++)
      {
	if(arr[j] > arr[j+1])
	  {
	       temp = arr[j];
	       arr[j] = arr[j+1];
	       arr[j+1]= temp;
	  }
      }
 }
 printf("\nSorted array:");
 for(i=0;i<n;i++)
   {
     printf("\t%d",arr[i]);

   }
 getch();
 }