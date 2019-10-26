def power(x, y):
    if(y == 0):
        return 1
    if(y < 0):
        n = (1/x) * power(x, (y+1)/2)
        return n*n
    if(y%2 == 0):
        m = power(x, y/2)
        return m*m
    else:
        return x * power(x, y-1)

def main():
    print("To calculate x^y ...\n")
    x = float(input("Please enter x: "))
    y = float(input("Please enter y: "))

    if(x==0):
        if(y > 0):
            print(0)
        else:
            print("x^y is not defined\n")
    else:
        print(power(x,y))
    exit

if __name__ == '__main__':
    main()