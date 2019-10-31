'''
The N choose K algorithm computes the binomial coefficient C(N, K)
'''

def nchoosek(n, k):
    if (k == 0) or (k == n):            # base case
        return 1
    else:                               # recursive case
        return nchoosek(n-1, k-1) + nchoosek(n-1, k)

if __name__ == "__main__":
    print (nchoosek(n=5, k=3))