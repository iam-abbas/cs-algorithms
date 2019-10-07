#!/usr/bin/env python
# coding: utf-8

#Author: fabiovini08

import os
import numpy as np


# Creates an adjacency matrix from a file

#File format:   A .txt file where the first line has a number N that
#                represents the #nodes and the following lines have numbers
#                pairs X Y that represents the edge X -> Y
def read_graph(filename):
    f = open(filename,'r+')
    lines = f.readlines()
    f.close();
    N = int(lines.pop(0))
    M = np.zeros([N,N])
    for l in lines:
        i,j = l.split()
        i = int(i)
        j = int(j)
        
        M[i,j] = 1
    i = 0
    return M

# absorbing node treatment 
def dumping_fac(M,fac = 0.15):
    A = (1-fac)*M + fac * 1/M.shape[0] * np.ones(M.shape)
    return A

# No link page treatment
def mat_norm(M):
    for c in (M.T):
        s = np.sum(c)
        if s == 0:
            c = np.ones([1,N]) * 1/N
        else:
            c = 1/np.sum(c) * c
        c.reshape([10,1])
        M[:,i] = c;
        i = i+1  
    return M  

#Compute the relevance of each page
def page_rank(M, tol = 0.001, nIter = 500):
    # Returns the vector v where each position has a value of relevance
    # of the respective node

    M = mat_norm(M)
    M = dumping_fac(M)
    N = M.shape[0]
    v = np.ones([N,1]) * 1/N
    for i in range(nIter):
        v1 = M.dot(v)
        err = np.linalg.norm(v-v1,2)
        v = v1
        if err < tol:
            numI = i
            break
    return v, numI
    
##  Algorith Test

M = read_graph('graph.txt')
print(M)
A = dumping_fac(M)
print(A)
v, it = page_rank(A)
print(v)
val = max(v)
print(val, it)

