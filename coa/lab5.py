import lab4
import lab1

def main():
    a = '0'
    temp = '0'
    [m,q] = lab4.getInput()
    [a,q] = lab4.normaliseString(a,q)
    [m,q] = lab4.normaliseString(m,q)
    a = '0' + a;
    m = '0' + m;
    n=len(q)
    for i in range(n-1,-1,-1):
        if(a[0] == '0'):
            [a,q] = lab4.shiftLeft(a,q)
            a = lab4.lab2.subtract(a,m)[0]
        else:
            [a,q] = lab4.shiftLeft(a,q)
            data = lab1.NbitAdder(a,m)
            a,c = data.result()
        if(a[0] == '0'):
            q = q + '1'
        else:
            q = q + '0'
    if(a[0] == '1'):
        data = lab1.NbitAdder(a,m)
        a,c = data.result()

    print("Quotient :"+q)
    print("Remainder :"+a)

if __name__ == '__main__':
    main()