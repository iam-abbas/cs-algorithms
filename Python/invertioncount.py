#simple merge sort algorithm with invertion checking while merging
def mergeSort(nlist,count):
    print("Splitting ",nlist)
   # count=0
    if len(nlist)>1:
        mid = len(nlist)//2
        lefthalf = nlist[:mid]
        righthalf = nlist[mid:]

        count+=mergeSort(lefthalf,count)
        count+=mergeSort(righthalf,count)
        i=j=k=0       
        while i < len(lefthalf) and j < len(righthalf):
            if lefthalf[i] < righthalf[j]:
                nlist[k]=lefthalf[i]
                i=i+1
            else:
                nlist[k]=righthalf[j]
                count+=mid-i
                j=j+1
            k=k+1

        while i < len(lefthalf):
            nlist[k]=lefthalf[i]
            i=i+1
            k=k+1

        while j < len(righthalf):
            nlist[k]=righthalf[j]
            j=j+1
            k=k+1
    return count
#array declaration
arr=[]
#Total count of invertion set to 0 at the beggining
count=0
print("Enter number of elements:-")
n=int(input())
for i in range(0,n):
    x=int(input())
    arr.append(x)
print("Array elements are:")
print(arr)
print("Total Number of inversions are" ) 
print(mergeSort(arr,count))
