#!/usr/bin/python
# -*- coding: utf-8 -*-

"""
There are n stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. 
Count the number of ways, the person can reach the top.

This can be solved with recusive equation 
    ways(n) = ways(n-1)+ways(n-2)
and base cases
    ways(0)=1
    ways(n)=0 if n<0
this clearly resembles fibonacci series and can easily be solved in bottom up manner with ways(0)=1, ways(1)=1 
"""

n = int(input('Enter the number of stairs:'))
a = 1 # ways(0)
b = 1 # ways(1)
c = 1 # initial value
for _ in range(n - 1): 
    c = a + b
    a = b
    b = c
print('There are {} ways to climb {} stairs'.format(c, n))

			