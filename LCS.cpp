#include<bits/stdc++.h>
#include<string.h>
using namespace std;
//This function will return longest common subsequence of two given string;
int LCS(char str1[], char str2[], int n, int m)
{
	vector<char>vec;
	int L[n+1][m+1];		//initialize a 2D array;
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0 || j==0)
				L[i][j]=0;
			else if(str1[i-1]==str2[j-1]) 	//if 'i'th character of 1st string equal to 'j'th character of
			{								//2nd string then push that character to the vector and go for
				L[i][j]=1+L[i-1][j-1];		//next character of both string;
				vec.push_back(str1[i-1]);
			}
			else							//else return max of 'i-1' characters of 1st string and j characters
				L[i][j]=max(L[i-1][j],L[i][j-1]);	//and 'i' characters of 1st string and 'j-1' characters of
		}											//2nd sgtring;
	}
	int c=L[n][m];
	cout << "\nLargest Common Subsequence is: ";
	for(int i=vec.size()-c;i<vec.size();i++)	//print longest common subsequence;
		cout << vec[i];
	cout << endl;
	return L[n][m]; 	//return length of longest common subsequence;
}
int main()
{
	char str1[100],str2[100];
	cout << "Enter the two string: " << endl;
	cin>>str1>>str2;	//enter two string;
	int n=strlen(str1);	//length of first string;
	int m=strlen(str2);	//length of second string;
	cout << "Length of Largest Common Subsequence: " << LCS(str1, str2, n, m);	//print LCS of two string;
	return 0;
}
