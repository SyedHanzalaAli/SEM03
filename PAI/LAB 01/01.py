num = input("enter number : ")

n = int(num)

nfloat = float(n)
nstring = str(n)
ncomplex = complex(n)

print(nfloat , nstring , ncomplex)

if(n//2)*2 == n:
    print( n , "is divisible by 2")
else:
    print( n , "is not divisible by 2")