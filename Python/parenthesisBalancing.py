
#stack is used to make parenthesis balancing checker


def checker(inp):
  stre=''
  pairs={}
  pairs[')']='('
  pairs['}']='{'
  pairs[']']='['
  stack=[]
  for i in list(inp):
    if i==']' or i=='}' or i==')':
      len(stack)==0 or stack.pop() != pairs[i]  ? return False:pass
    else :
      stack.push(i)
  return True
    
  






def main():
  inp=str(input("Enter the word:"))
  print ( "balanced" if checker(inp) else "un-balanced")
  
  
  
main()
