#include<stdio.h>

int main () {
    int term1 = 0 , term2 = 1, i, number, sequence;

    printf("What is the number of terms: ");
    scanf("%d",&number);
    printf("Fibonacci sequence: ");

    for(i=1; i<=number; i++) {
        sequence = (term1 + term2);
        printf("%d ", term1);
        term1 = term2;
        term2 = sequence;
    }
}
