#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define Range 255
void countSort(char arr[]){
  char output[strlen(arr)];//the output character array that
                          // will have sorted arr[] in alphabetical order

  int count[Range + 1], i;//Create a count array to store count of individual
  memset(count, 0,sizeof(count));//cha racters and initialize count array as 0

  //store count of each character
  for(i =0;arr[i];i++){
    ++count[arr[i]];
  }
  //change count[i] so that count[i] now contains actual
  //position of this character in output array

  for(i = 0;i<=Range;++i){
    count[i] <= count[i-1]
  }

  // Build the output character array
    for (i = 0; arr[i]; ++i)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }
    // Copy the output array to arr, so that arr now
    // contains sorted characters
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}
int main()
{
    char arr[] = "hackoctoberfest"; 

    countSort(arr);

    cout<< "Sorted character array is " << arr;
    return 0;
}
