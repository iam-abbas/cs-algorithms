/*
Explanation:
Given a array and an integer k, find the count of distinct elements in every sub-array of size k in the array.

Input:
arr[]={7,2,7,4,7,1,6,5}

Output:
No.of distinct elements in the sub-array { 2, 1, 2, 3, 2 } is 3
No.of distinct elements in the sub-array { 1, 2, 3, 2, 1 } is 3
No.of distinct elements in the sub-array { 2, 3, 2, 1, 4 } is 4
No.of distinct elements in the sub-array { 3, 2, 1, 4, 5 } is 5
*/
#include <stdio.h>

void findDistinctCount(int a[], int n, int k)
{
	
	for (int x = 0; x <= n - k; x++)
	{
		int distinct = 0;
		for (int i = x; i < x + k; i++)
		{
			distinct++;
			for (int j = x; j < i; j++)
			{
				if (a[i] == a[j])
				{
					distinct--;
					break;
				}
			}
		}
		printf("No.of distinct elements in the sub-array [%d, %d] "
				"is %d\n", x, x + k - 1, distinct);
	}
}
int main(void)
{
	int ar[] = { 2, 1, 2, 3, 2, 1, 4, 5 };
	int k = 5;
	int n = sizeof(ar) / sizeof(ar[0]);
	findDistinctCount(ar, n, k);
	return 0;
}