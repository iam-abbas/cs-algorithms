#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(float *array, int size)
{
    vector<float> bucket[size];

    //inserting elements into buckets such that
    // arr[i] will be at size*arr[i] location
    for (int i = 0; i < size; i++)
    {
        bucket[int(size * array[i])].push_back(array[i]);
    }
    //sorting individual buckets as each bucket can
    // have more than one element
    for (int i = 0; i < size; i++)
    {
        sort(bucket[i].begin(), bucket[i].end());
    }
    int index = 0;
    //inserting elements into the original array
    for (int i = 0; i < size; i++)
    {
        while (!bucket[i].empty())
        {
            array[index++] = *(bucket[i].begin());
            bucket[i].erase(bucket[i].begin());
        }
    }
}
int main()
{
    float arr[] = {0.43, 0.36, 0.21, 0.41, 0.29, 0.58, 0.45, 0.97, 0.01, 0.65};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, arr_size);

    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }
}