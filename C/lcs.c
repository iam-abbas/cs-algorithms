#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printMat(int** ar,int n,int m)
{
    int i = 0,j = 0;
    for(i =0 ; i< n ;i++)
    {
        for(j = 0; j< m; j++)
        {
            printf("%d\t", ar[i][j]);
        }
        printf("\n" );
    }
}
void LCSPrint(char* X, int** dir, int n, int m)
{
  //printf("%d-%d-%d\n",dir[n][m],n,m );
    if(dir[n][m]==1)
    {
        LCSPrint(X,dir,n-1,m-1);
        printf("%c",X[m-1] );
    }
    else if(dir[n][m] == 2)
    {
        LCSPrint(X, dir, n-1,m);
    }
    else if(dir[n][m]==3)
    {
        LCSPrint(X,dir,n,m-1);
    }
}
void LCS(char* p1, char* p2, int n1, int n2)
{
    int i = 0, j= 0;
    n1++;
    n2++;//Important
    int **ar = (int**)calloc(n1,sizeof(int*));
    int **dir = (int**)calloc(n1,sizeof(int*));
    for(i = 0; i< n1+1; i++)
    {
        ar[i] = (int*)calloc(n2,sizeof(int));
        dir[i] = (int*)calloc(n2,sizeof(int));
    }
    for(i = 1; i< n1; i++)
    {
        for(j = 1;j< n2; j++)
        {
            if(p1[i-1] == p2[j-1])
            {
                ar[i][j] = ar[i-1][j-1]+1;
                dir[i][j] = 1;
            }
            else
            {
                if(ar[i-1][j] >= ar[i][j-1])
                {
                    ar[i][j] = ar[i-1][j];
                    dir[i][j] = 2;
                }
                else
                {
                    ar[i][j] = ar[i][j-1];
                    dir[i][j] = 3;
                }
            }
        }
    }
    printMat(ar,n1,n2);
    printf("=========\n" );
    printMat(dir,n1,n2);
    LCSPrint(p2,dir,n1-1,n2-1);
}
int main()
{
    char X[] = "ABCBDAB";
    char Y[] = "BDCABA";

    int m = strlen(X);
    int n = strlen(Y);
    LCS(X,Y,m,n);
}
