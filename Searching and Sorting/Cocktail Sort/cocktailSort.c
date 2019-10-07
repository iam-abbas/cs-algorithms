#include<stdio.h>
#include<stdlib.h>

typedef enum{false, true} bool;

void cocktailSort(int unsorted[], int length);
void swap(int *a, int *b);
void printArray(int arr[], int length);

int main(void){
    int arr[] = {65,-3,23,4,0};
    int length = 5;
    cocktailSort(arr, length);
    printArray(arr, length);
    return 0;
}


void cocktailSort(int unsorted[], int length){
    bool swapped = true;
    int start = 0;
    int end = length -1;
    while (swapped){
        swapped = false;
        int i;
        for(i=start; i<end; i++){
            if (unsorted[i] > unsorted[i+1]){
                swap(&unsorted[i], &unsorted[i+1]);
                swapped = true;
            }
        }
        end --;
        for(i=end; i>start-1;i--){
            if(unsorted[i] > unsorted[i+1]){
                swap(&unsorted[i], &unsorted[i+1]);
                swapped = true;
                
            }
        }
    }
}

void swap(int *a, int *b){
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void printArray(int arr[], int length){
    int i;
    printf("[");
    for(i=0;i<length;i++){
        if((i+1) % 7 == 0){
            printf("\n ");
        }
        printf("%d%s", arr[i], (i==length-1 ? "]\n": ", "));
    }
}
