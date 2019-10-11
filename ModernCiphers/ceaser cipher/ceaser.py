S=input('')
N=int(input(''))
enc=''
for i in S:
    if(i.isalnum()):
        if(ord(i)>=65 and ord(i)<=90):
            z=(ord(i)+N)
            if(z>90):
                while(z>90):
                    z-=26
                enc+=chr(z)
            else:
                enc+=chr(z)
        elif(ord(i)>=97 and ord(i)<=122):
            z=(ord(i)+N)
            if(z>122):
                while(z>122):
                    z-=26
                enc+=chr(z)
            else:
                enc+=chr(z)
        elif(ord(i)>=48 and ord(i)<=57):
            z=(ord(i)+N)
            if(z>57):
                while(z>57):
                    z-=10
                enc+=chr(z)
            else:
                enc+=chr(z)
    else:
        enc+=i
print(enc)