#include<iostream.h>
#include<conio.h>
void main()
{
    clrscr();
    int size, arr[50], i, j, temp, index, small, count=0;
    cout<<"Enter Array Size : ";
    cin>>size;
    cout<<"Enter Array Elements : ";
    for(i=0; i<size; i++)
        cin>>arr[i];
    cout<<"Sorting array using selection sort...\n";
    for(i=0; i<(size-1); i++)
    {
        small = arr[i];
        for(j=(i+1); j<size; j++)
        {
            if(small>arr[j])
            {
                small = arr[j];
                count++;
                index = j;
            }
        }
        if(count!=0)
        {
            temp = arr[i];
            arr[i] = small;
            arr[index] = temp;
        }
        count=0;
    }
    cout<<"Now the Array after sorting is :\n";
    for(i=0; i<size; i++)
        cout<<arr[i]<<" ";
    getch();
}
