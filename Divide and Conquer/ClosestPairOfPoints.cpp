#include<bits/stdc++.h>
using namespace std;
#define LARGE_FLOAT 10000000000


struct point{
int x;
int y;
};

struct node{
char x;
int freq;
};

void sortX(point p[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        if(p[i].x>p[j].x)
        {
            point a=p[j];
            p[j]=p[i];
            p[i]=a;
        }
    }

}

float getMin(float dl,float dr)
{

    if(dl<dr)
        return dl;
    else
        return dr;
}

float getDistance(point a,point b)
{
    return (sqrt(((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y))));

}

float stripMinimum(point strip[],int size,float d)
{
    float m=d;

    for(int i=0;i<size;i++)
    for(int j=i+1;j<size;j++)
    {
        if(getDistance(strip[i],strip[j])<d)
          m=getDistance(strip[i],strip[j]);

    }
    return m;
}

float closest(point p[],int n)
{
    if(n<=3)
    {
        float min=LARGE_FLOAT;
        for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        if(getDistance(p[i],p[j])<min)
        min=getDistance(p[i],p[j]);

        return min;


    }


        int mid=n/2;
        point midPoint=p[mid];

        float dl=closest(p,mid);
        float dr=closest(p+mid,n-mid);

        float minimum=getMin(dl,dr);
        point strip[n];
        int x=0;
        for(int i=0;i<n;i++)
        {
            if(abs(p[i].x-midPoint.x)<minimum)
            {
                strip[x++]=p[i];
            }
        }
        float d=stripMinimum(strip,x,minimum);
        return getMin(minimum,d);
}



int main()
{
    point p[100];

    int n;
    cout<<"enter size"<<endl;
    cin>>n;

    cout<<"enter points"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].x>>p[i].y;
    }

    if(n==1)
        cout<<0<<endl;
    else{

       sortX(p,n);

    cout<<closest(p,n)<<endl;

    }

}
