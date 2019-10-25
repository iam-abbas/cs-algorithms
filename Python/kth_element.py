#!/usr/bin/python3

# Usage:  kth_element(place_of_element,largest_or_smallest,array)
# If you are looking for the 3rd largest element of "myarray": kth_element(3,'largest',myarray)

def kth_element(k,large_or_small,mylist):

    if large_or_small == "largest":
        modifier = 1
    elif large_or_small == "smallest":
        modifier = -1
    else:
        print("Valid values for the sort are 'largest' or 'smallest'")
        exit(1)

    if len(mylist) < k or k < 1:
        print("ERROR: Array size is " + str(len(mylist)) + ", but requested value is " + str(k) + "...")
        return None

    newlist = [None] * k

    while len(mylist) > 0:
        test = mylist.pop()
        for i in range(0,k):
            if newlist[i] == None or test * modifier > newlist[i] * modifier:
                newlist.insert(i,test)
                newlist.pop()
                #print(newlist)  # Uncomment to see the value list build in action
                break

    return(newlist[k-1])

if __name__ == "__main__":
    mylist = [ 42, 39, 857, 20, 3884, 82, 0, 84, 8, 3, -50, -1000 ]
    print(kth_element(1,'smallest',mylist))
