#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
    /* Write the logic to reverse the array. */ 
    int* left_ptr = arr;
    int* right_ptr;
    int temp;
    for(i = 0; i < num; i++) {
        if(i == num - 1) {
            right_ptr = (arr + i);
        }
    }
    while(left_ptr < right_ptr) {
        temp = *right_ptr;
        *right_ptr = *left_ptr;
        *left_ptr = temp;
        right_ptr--;
        left_ptr++;
    }
      
    for(i = 0; i < num; i++) {
        printf("%d ", *(arr + i));
    }
    free(arr);
    return 0;
}
