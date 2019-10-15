# -*- coding: utf-8 -*-
"""
Created on Tue Oct 15 18:11:37 2019

@author: Vidhan Jhawar
"""

'''
Narayana Pandit's algorithm to find next lexicographically greatest permutation

Algorithm:
1. Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
2. Find the largest index l greater than k such that a[k] < a[l].
3. Swap the value of a[k] with that of a[l].
4. Reverse the sequence from a[k + 1] up to and including the final element a[n].
'''

import math

def nextGreater(w):
    w=list(w)
    l=len(w)
    flag=1
    for i in range(l-2,-1,-1):
        if(w[i]<w[i+1]):
            flag=0
            break
    if(flag==1):
        return 'no answer'
    for j in range(l-1,i,-1):
        if(w[j]>w[i]):
            break
    temp=w[i]
    w[i]=w[j]
    w[j]=temp
    for k in range(i+1,math.ceil((l+i-1)/2)+1):
        temp=w[k]
        w[k]=w[l-k+i]
        w[l-k+i]=temp
    return ''.join(w)

if __name__ == '__main__':
    w=input()
    print(nextGreater(w))