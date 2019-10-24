#----Median Of Median finding algorithm implimentation in python----


#used to avoid overflow
INT_MAX=2**32

#finding the kth element from the list
def kthS(a,k) :
    a.sort()
    return a[k-1]

#finding median from the fixed length of array( median of arr[] from index l to l+n )
def findmedian(a,l,n):
    a=a[l:l+n]
    a.sort()
    return a[n//2]

#This funrions uses median of median algo to find kthsmallest number in linear time
def kthSmallest(a,l,r,k):
    if k>0 and k<=r-l+1:
        n=r-l+1
        median=[0]*((n+4)//5)
        i=0
        #divide the array into smaller array of size 5 and find median of each small array
        while(i<n//5):
            median[i]=findmedian(a,l+i*5,5)
            i+=1
        # For last group with less than 5 elements 
        if i*5<n:
            median[i] = findmedian(a,l+i*5, n%5)  
            i+=1
        # Find median of all medians using recursive call.  
        # If median[] has only one element, then no need  
        # of recursive call
        if(i == 1):
            medOfMed = median[i-1]
        else:    
            kthSmallest(median, 0, i-1, i//2)
        # Partition the array around a medOfMed 
        # element and get position of pivot  
        # element in sorted array 
        pos = partition(a, l, r, medOfMed)
        if pos-l == k-1: 
            return a[pos]
        if (pos-l > k-1):
            return kthSmallest(a, l, pos-1, k)
        return kthSmallest(a, pos+1, r, k-pos+l-1) 
    return INT_MAX
#for swapping two array elements
def swap(arr, a, b): 
    temp = arr[a] 
    arr[a] = arr[b] 
    arr[b] = temp 

# It searches for x in arr[l..r],   
# and partitions the array around x
def partition(a,l,r,x):  
    for i in range(l,r):
        if (a[i] == x):
           break
    swap(a,i,r)
    i = l 
    for j in range(l,r):
        if (a[j] <= x):
            swap(a,i,j)
            i+=1
    swap(a,i,r); 
    return i;
#driver code
def main():
    #Total number of elements in the list is n
    n=int(input("Enter value of n:"))
    k=(n+1)//2
    a=[]
    #entering n elements to the lsit
    for i in range(n):
        x=int(input())
        a.append(x)
    #if total number of elements is even just print the kth elements
    if(n%2==0):
        print("result is: %d"%kthS(a,k))
        return
    #if total number of elements is odd the use median of median algo to find kth smallest
    print("result %d"%kthSmallest(a, 0, n-1, k))
#Calling the main funtion
if __name__ == '__main__':
    main()
