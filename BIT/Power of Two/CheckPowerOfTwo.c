#include<stdio.h>

int main()
{
	int number,check;
	scanf("%d",&number);
    check= number & (number-1);
    if(check==0)
    printf("YES");
    else
    printf("NO");
}