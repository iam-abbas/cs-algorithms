//https://www.thecrazyprogrammer.com/2017/05/travelling-salesman-problem.html
#include<iostream>
 
using namespace std;
 
int ary[10][10],completed[10],n,cost=0;
 
void takeInput()
{
	int i,j;
 
	cout<<"Enter the number of villages: "; //Take input for number of destinations to be visited
	cin>>n; 
 
	cout<<"\nEnter the Cost Matrix\n";             //input of the cost matrix
 
	for(i=0;i < n;i++)
	{
		cout<<"\nEnter Elements of Row: "<<i+1<<"\n";
 
		for( j=0;j < n;j++)
			cin>>ary[i][j];
 
		completed[i]=0;
	}
 
	cout<<"\n\nThe cost list is:";
 
	for( i=0;i < n;i++)                                  //Calculates the cost list for the matrix
	{
		cout<<"\n";
 
		for(j=0;j < n;j++)
			cout<<"\t"<<ary[i][j];
	}
}
//Computes the least cost and returns the value 
int least(int c)
{
	int i,nc=999;
	int min=999,kmin;
 
	for(i=0;i < n;i++)
	{
		if((ary[c][i]!=0)&&(completed[i]==0))
			if(ary[c][i]+ary[i][c] < min)
			{
				min=ary[i][0]+ary[c][i];
				kmin=ary[c][i];
				nc=i;
			}
	}
 
	if(min!=999)
		cost+=kmin;
 
	return nc;
}
//Provides min cost for a city
void mincost(int city)
{
	int i,ncity;
 
	completed[city]=1;
 
	cout<<city+1<<"--->";
	ncity=least(city);
 
	if(ncity==999)
	{
		ncity=0;
		cout<<ncity+1;
		cost+=ary[city][ncity];
 
		return;
	}
 
	mincost(ncity);
}
 //Driver code for the above functions
int main()
{
	takeInput();
 
	cout<<"\n\nThe Path is:\n";
	mincost(0); //passing 0 because starting vertex
 
	cout<<"\n\nMinimum cost is "<<cost;
 
	return 0;
}
