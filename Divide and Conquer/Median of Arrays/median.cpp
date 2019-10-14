 
#include <bits/stdc++.h> 
using namespace std; 
 
int getMedian(int arr1[], int arr2[], int n, int m)  
{  
    int i = 0; 
    int j = 0; 
    int c;  
    int m1 = -1, m2 = -1;  
  
    if((m + n) % 2 == 1)  
    {  
        for (c = 0; c <= (n + m)/2; c++) 
        {  
            if(i != n && j != m) 
            {  
                m1 = (arr1[i] > arr2[j]) ? arr2[j++] : arr1[i++];  
            }  
            else if(i < n) 
            {  
                m1 = arr1[i++];  
            }   
            else
            {  
                m1 = arr1[j++];  
            }  
        }  
        return m1;  
    }  

    else 
    {  
        for (c = 0; c <= (n + m)/2; c++)  
        {  
            m2 = m1;  
            if(i != n && j != m) 
            {  
                m1 = (arr1[i] > arr2[j]) ? arr2[j++] : arr1[i++];  
            }  
            else if(i < n) 
            {  
                m1 = arr1[i++];  
            }   
            else
            {  
                m1 = arr1[j++];  
            }  
        }  
        return (m1 + m2)/2;  
    }  
}  
  
int main()  
{  
    int arr1[] = {900};  
    int arr2[] = {5, 9, 10, 20};  
  
    int n1 = sizeof(arr1)/sizeof(arr1[0]);  
    int n2 = sizeof(arr2)/sizeof(arr2[0]);  
    cout << getMedian(arr1, arr2, n1, n2);  
    return 0;  
} 
