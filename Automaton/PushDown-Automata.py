# A Simple Implementation of Push Down Automaton:
##    Defining the 6 tuples:
#>  *  Q-->finite set of sets
#>  *  Sigma-->finite set of input alphabet
#>  *  Gamma-->finite set of stack alphabet
#>  *  Delta-->transition relation
#>  *  Q0-->start state
#>  *  Z-->initial stack symbol
#>  *  F-->set of accepting states

# Defining the states:

#* state 0: starting state

#* state 1:From state 0 whenever it sees a 1 or 2, it moves to state 1+pushes the element onto the stack
#* state 1:From state 1 whenever it sees a 1 or 2, it remains in state 1+pushes the element onto the stack

#* state 2:From state 1 whenever it sees a 0, it moves to state 2+pops from the stack
#* state 2:From state 1 whenever it sees a 0, it remains in state 2+pops from the stack

#* state 3:From state 0, if it sees a 0,it moves to state 3,the rejected state
#* state 3:From state 2, if it sees a 1 or 2 , it moves to state 3, the rejected state
#* state 3:If at the end, the stack is not empty, it moves to state 3,the rejected state

#stack functions
def push(a,list1):
    #pushing to the stack/adding to the top of the stack
    list1.append(a)
    return 1

def pop(list1):
    #for poping from the stack/removing the top element of the stack
    index=len(list1)-1
    if (index>0):
        list1.pop(index)
        return 1
    else:
        return 0

#    Q={0,1,2,3}
#    Sigma={0,1,2}
#    Starting state={0}
#    Z=#
#    F={2}

#setting the initial stack symbol
stack=['#']
#setting the starting state
state=0

#taking the input
input_string=input('Enter the String:')

#performing the operations
l=len(input_string)
i=0
if l%2==0:
    while i<l//2:
        letter=int(input_string[i])
        if letter in [1,2]:
            push(letter,stack)
            state=1
        else :
            state=3
            break
        i+=1
    
    while i<l:
        letter=int(input_string[i])
        if state==3:
            break
        if letter==0:
            state=2
            pop(stack)
        else:
            state=3
            break
        i+=1
else:
    state=3
    
if state==2 and len(stack)!=1:
    state=3
    

#checking the final state and displaying the result
if(state==2):
    print("The String is accepted")
else:
    print("The String is rejected")