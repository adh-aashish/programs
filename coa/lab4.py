import lab2 

def normaliseString(str1,str2):
    diff = abs((len(str1) - len(str2)))
    if diff != 0:
        if len(str1) < len(str2):
            str1 = ('0' * diff) + str1
            
        else:
            str2 = ('0' * diff) + str2
           
    return [str1,str2]

def getInput():
    q = input("Enter divident\n")
    m = input("Enter divisor\n")
    return [m,q]

def shiftLeft(a,q):
    qtemp = q[0]
    q = q[1:]
    a = a + qtemp
    a = a[1:]
    return [a,q] 

def main():
    a = '0'
    temp = '0'
    [m,q] = getInput()
    [a,q] = normaliseString(a,q)
    [m,q] = normaliseString(m,q)
    a = '0' + a;
    m = '0' + m;
    n=len(q)
    for i in range(n-1,-1,-1):
        [a,q] = shiftLeft(a,q)
        temp = lab2.subtract(a,m)[0]
        if(temp[0] == '0'):
            q = q + '1'
            a = temp
        else:
            q = q + '0'

    print("Quotient:\t"+q)
    print("\nRemainder:\t"+a)

if __name__ == '__main__':
    main()