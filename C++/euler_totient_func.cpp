#include<cstdio>
#include<iostream>

int phi[1000006], prime[1000006]; 
void sievephi(int n) 
{
    int i,j;

    for(i=1; i<=n; i++) phi[i]=i; 

    phi[1]=1;  
    prime[1]=1; 

    for(i=2; i<=n; i++)
    {
        if(!prime[i])   
        {
            for(j=i;j<=n; j+=i)
            {
                prime[j+i]=1;   
                phi[j]=(phi[j]/i)*(i-1);    
                                            
            }
        }
    }
}


int main()
{
    int i,n=10;
    sievephi(n);

    for(i=1; i<=n; i++)
        if(!prime[i])
        printf("%d ", i);
    printf("\n");

    for(i=1; i<=n; i++)
        printf("%d = %d\n", i, phi[i]);

    return 0;
}
