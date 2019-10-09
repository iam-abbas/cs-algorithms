#include <iostream>

void SelectionSort(int list[], int size)
{
	int min_pos;
	for(int last_pos = 0; last_pos < size; last_pos++)
	{
		min_pos = last_pos;
		for(int i = last_pos; i < size; i++)
		{
			if(list[min_pos] > list[i]) min_pos = i;
		}
		int aux = list[last_pos];
		list[last_pos] = list[min_pos];
		list[min_pos] = aux;
	}
}

void PrintList(int list[], int size)
{
	for(int n = 0; n < size; n++)
	{
		std::cout << list[n] << " " << std::flush;
	}

	std::cout << std::endl;
}

int main()
{
	int list[6] {2, 1, 7, 3, 3, 5};
	PrintList(list, 6);
	SelectionSort(list, 6);
	PrintList(list,6);
	return 0;
}
