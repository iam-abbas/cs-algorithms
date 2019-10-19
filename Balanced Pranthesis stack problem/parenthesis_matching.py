# -*- coding: utf-8 -*-
"""
Created on Fri Oct 18 23:13:34 2019

@author: Prajwal
"""




def push(x, stack):
    stack.append(x)


def pop(stack):
    x=stack.pop()
    return x

def is_empty(stack):
    if(len(stack)==0):
        return 1
    else:
        return 0

def match(exp):
    stack=list()
    for i in exp:
        ch=i
        #checks for opening brackets
        if(ch=='('):
            push(ch, stack)
        elif(ch=='['):
            push(ch, stack)
        elif(ch=='{'):
            push(ch, stack) 
            
            
        #checks for closing brackets    
        elif(ch==')'):
            if((is_empty(stack))==0):
                x=pop(stack)
                if(x != '('):
                    return 0
            else:
                return 0
        elif(ch==']'):
            if((is_empty(stack))==0):
                x=pop(stack)
                if(x != '['):
                    return 0
            else:
                return 0
        elif(ch=='}'):
            if((is_empty(stack))==0):
                x=pop(stack)
                if(x != '{'):
                    return 0
            else:
                return 0
            
    #checks is all elements of stack are dealt with
    if(is_empty(stack)):
        return 1
    else:
        return 0
        
        
if __name__=='__main__':
    string=input('Enter the parenthesis string  :  ')
    result=match(string)
    if(result):
        print('Parenthesis are matched')
    else:
        print('Parenthesis are not matched')
                
                
    
        

        