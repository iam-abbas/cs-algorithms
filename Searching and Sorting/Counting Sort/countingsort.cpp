/* 
implementation of counting sort 
 in this sorting we have restriction  on maximum value of array
*/

#include<iostreams>
using namespace std;
int main()
{
	int a,b;
	cout<<"enter the length and maximum value\n";
	cin>>a>>b;
	int k1[a], k2[a];
	for(int i=0;i<a;i++) //taking input array 
	{
		cin>>k1[i];
		
	}
	int l1[b+1];  // creating an extra array for counting frequency of elements
	for(int i=0;i<b;i++)
	{
		l1[i]=0;
	}
	for(int i=0; i<a; i++)  //counting frequency of elements of array k1[]
	{
		l1[k1[i]]+=1;
	}
   for(int i=1; i<=a; i++) // updating l1 to know starting point of element's  of array k1
      l1[i]=l1[i]+l1[i-1];
   for(int i=a-1; i>=0; i--)
   {
       k2[l1[k1[i]]]=k1[i];   // puting elements in sorted order 
	   l1[k1[i]]-=1;   	
   }
	for(int i=1; i<=a;i++)  // printing array
      cout<<k2[i]<<" ";	
	return 0;
}
