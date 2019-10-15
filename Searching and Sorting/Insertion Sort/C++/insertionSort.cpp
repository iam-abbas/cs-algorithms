#include <iostream>
using namespace std;
/*
Insertion Sort (Recursive)

Compiled in Visual Studio 2019
by Divakar Lakhera

*/

/**

	Insertion_sort not recursive
	@parameter 1 : the starting address of the array.
	@parameter 2 : the starting index from where you want to sort it.
	@parameter 3 : the last index till which you want to sort.

*/

void insertion_sort(int *arr, int from, int to)
{
	int key = 0;
	int j = 0;
	
	for(int i = from + 1; i <= to; i++)
	{
		key = arr[i];
		j = i - 1;
		while(key < arr[j] && j >= from)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}


/*

	void doiSort(int buf[], int len, int maxl)

		- buf: array to sort
		- len: no of elements "not to sort" (set it to 1 or 0 for complete array).
		       Setting it to any another no will result in "len" no of elements of starting of array to not get sorted and will be added at the end of sorted array.
			   Eg for above:
			       Input array(arr): 10 9 8 7 6 5 4 3 2 1 
				   param: arr,4,10
				   Output(arr): 1 2 3 4 5 6 10 9 8 7
		- maxl: length of array to sort

*/




void doiSort(int buf[], int len, int maxl)
{
	if (len >= maxl)
	{
		return;
	}
	if (len == 1)
	{
		if (buf[0] > buf[1])
		{
			//cout << " Shift 1" << endl;
			int r = buf[1];
			buf[1] = buf[0];
			buf[0] = r;
		}
		doiSort(buf, 2, maxl);
	}
	else
	{
		int m = buf[len];
		for (int i = 0; i < len; i++)
		{
			if (buf[i] > m)
			{
				//cout << "insert " << buf[i] << "->" << buf[len] << " " << endl;
				for (int j = len; j > i; j--)
				{
					int t = buf[j];
					buf[j] = buf[j - 1];
					buf[j - 1] = t;
				}
				break;
			}
		}

		doiSort(buf, len + 1, maxl);
	}
	return;
}

/*
Some Test Driver code
int main()
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = 10 - i;
	}

	doiSort(a,1,10);

	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}

	return 0;
}

*/
