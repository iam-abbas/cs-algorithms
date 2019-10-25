#!/usr/bin/python3

def kth_element(k,mylist):
    if len(mylist) < k or k < 1:
        print("You've selected an index outside the bounds of the array.")
        return None

    newlist = [None] * k

    while len(mylist) > 0:
        test = mylist.pop()
        for i in range(0,k):
            if test > newlist[i] or newlist[i] == None:
                newlist.insert(i,test)
                newlist.pop()
                break

    return(newlist[k-1])

if __name__ == "__main__":
    mylist = [ 42, 39, 857, 20, 3884, 82, 0, 84, 8, 3 ]
    print kth_element(-2,mylist)
