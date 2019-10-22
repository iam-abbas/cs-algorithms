#include<stdio.h>
#include<stdlib.h>
#define SIZE  5
#include<iostream>
using namespace std;
char a[SIZE];
int top=-1;
void push(int data)
{
    if(top==SIZE-1)
    {
        throw "Sorry! stack is full no more space\n";
    }
    else{
        a[++top]=data;
       // printf("element inserted\n");
    }
}
void pop()
{

    if(top==-1)
    {
        throw "empty stack can't be deleted\n";
       // printf("empty stack can't deleted\n");
    }
    else
    {
        //printf("deleted = %d\n",a[top]);
        top--;
    }

}
int topIndex()
{
    if(top==-1)
    {
        throw "Empty Stack";
    }
    else
    {
        return a[top];
    }
}
int size()
{
    return top+1;
}
bool empty()
{
    return top==-1;
}
int main()
{
    /*char ele;
    char ch ='y';
    while(ch=='y')
    {

      try{
        if(ele=='{')
            push(ele);
        else
            pop();
        cout<<"enter more put y";
        cin>>ch;
        }
        catch(const char *msg)
        {
            cout<<"not balanced";
        }
    }
    if(top==-1)
        cout<<"balanced";*/
   string braces="{[]}}";
   try{
       for(char c:braces)
       {
           if(c=='{' || c=='(' || c=='[')
                {
                    push(c);
                }
          else{
                if(c=='}' && topIndex()=='{')
                    {
                        pop();
                    }
                else if(c==')' && topIndex()=='(')
                    {
                        pop();
                    }
                else if(c==']' && topIndex()=='[')
                {

                    pop();
                }
                else
                {
                    throw "not balnced";
                }
           }
       }
       if(empty()==true)
       {
           cout<<"balanced";
       }
       else
       {
           cout<<"not balanced";
       }
   }
   catch(...)
   {
       cout<<"not balanced";
   }
}

