#include<stdio.h>
#include<string.h>
char array[100000],pattern[1000]; // max size of string and pattern
int main()
{
	int i,j,len_arr,len_pattern;

	scanf("%s",array);
	len_arr=strlen(array);
  
	scanf("%s",pattern);
	len_pattern=strlen(pattern);

	for(i=0;i<len_arr - len_pattern+1;i++)
	{
		for (j=0;j<len_pattern;j++)
		{
			if (array[i+j]!=pattern[j])
				break;						//pattern doesn't exist if even one element doesn't match
		}   //by sm2bhat
			if (j==len_pattern)				//j==pattern_length implies the pattern is present
				printf("Pattern found at position: %d\n",i+1);
	}
	return 0;
}
