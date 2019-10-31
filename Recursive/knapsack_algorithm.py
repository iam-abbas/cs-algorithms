'''
(0-1 Knapsack) example
The example solves the 0/1 Knapsack Problem: 
how we get the maximum value, given our knapsack just can hold a maximum weight of w, 
while the value of the i-th item is a1[i], and the weight of the i-th item is a2[i]?

i = total item
w = total weigh of knapsack can carry
'''

# a1: item value
a1 = [100, 70, 50, 10]

# a2: item weight
a2 = [10, 4, 6, 12]

def knapsack01(items, weight):
    if (w == 0) or (i < 0):
        return 0
    elif (a2[i] > w):
        return knapsack01(i-1, w)
    else:
        return max(a1[i] + knapsack01(i-1, w-a2[i], knapsack01(i-1, w)))

if __name__ == "__main__":
    i = 3
    w = 12
    print (knapsack01(items=i, weight=w))