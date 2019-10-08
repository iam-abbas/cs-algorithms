//2 stacks in an array
#include<bits/stdc++.h>
using namespace std ;
class TwoStacks
{
    int *arr ;
    int size ;
    int top1 ;
    int top2 ;
public:
    TwoStacks()
    {
        this->size = 6 ;
        arr = new int[6] ;
        top1 = -1 ;
        top2 = 6 ;
    }
    void push1(int data)
    {
        if(top1 < top2-1)
        {
            top1++ ;
            arr[top1] = data ;
        }
        else
        {
            cout<<"Stack1 Over-Flow"<<endl ;
        }
    }
    void push2(int data)
    {
        if(top1 < top2-1)
        {
            top2-- ;
            arr[top2] = data ;
        }
        else
        {
            cout<<"Stack2 Over-Flow"<<endl ;
        }
    }
    void pop1()
    {
        if(top1>=0)
        {
            top1-- ;
        }
        else
        {
            cout<<"Stack1 Under-Flow"<<endl ;
        }
    }
    void pop2()
    {
        if(top2<size)
        {
            top2++ ;
        }
        else
        {
            cout<<"Stack2 Under-Flow"<<endl ;
        }
    }
    int top_elem_1()
    {
        if(top1>=0)
        {
            return arr[top1];
        }
        else
        {
            cout<<"Stack1 Under-Flow"<<endl ;
            return -1 ;
        }
    }
    int top_elem_2()
    {
        if(top2<size)
        {
            return arr[top2];
        }
        else
        {
            cout<<"Stack2 Under-Flow"<<endl ;
            return -1 ;
        }
    }
    bool isEmpty_1()
    {
        if(top1<0)
            return true ;
        else
            return false ;
    }
    bool isEmpty_2()
    {
        if(top2>=size)
            return true ;
        else
            return false ;
    }
    int size_1()
    {
        if(top1<0)
        {
            cout<<"Stack1 Under-Flow"<<endl ;
            return -1;
        }
        else
        {
            return top1+1 ;
        }
    }
    int size_2()
    {
        if(top2>=size)
        {
            cout<<"Stack2 Under-Flow"<<endl ;
            return -1;
        }
        else
        {
            return size-top2 ;
        }
    }
};
int main()
{
    TwoStacks ts ;
    ts.push1(1);
    ts.push1(2);
    ts.push2(6);
    ts.push1(3);
    ts.push2(5);
    ts.push1(4);
    cout<<"Top in Stack 1 : "<<ts.top_elem_1()<<endl ;
    ts.pop1() ;
    cout<<"Top in Stack 1 : "<<ts.top_elem_1()<<endl ;
    cout<<"Top in Stack 2 : "<<ts.top_elem_2()<<endl ;
    ts.push2(10);
    cout<<"Top in Stack 2 : "<<ts.top_elem_2()<<endl ;
    ts.push1(3) ;
    ts.pop1();
    ts.pop1();
    ts.pop1();
    ts.pop2();
    ts.pop2();
    ts.pop2();
    ts.pop1();
    ts.pop2();
}
