import lab2
import lab3
import sys
import lab1


def arithSR(a, q, q0, n):
    # print(type(a),type(q),type(q0))
    x = a+q+q0
    x = list(x)
    for i in range(len(x)-2, -1, -1):
        # print(i)
        x[i+1] = x[i]
    x = ''.join(x)
    return x[0:n], x[n:n+4], x[-1]


# def convertToBinary(num):
#     num = int(num)
#     while(num!=0):
#         x = num % 2
if __name__ == '__main__':
    num1 = input("Enter the multiplicand: ")
    num2 = input("Enter the multiplier: ")

    if(num1[0] == num2[0]):
        if(num1[0] == '-'):
            print(lab3.multiply(num1[1:], num2[1:]))
        else:
            print(lab3.multiply(num1, num2))
        sys.exit(0)

    if(num2[0] == '-'):
        # negative number is in num2 ,so swap num2 and num1
        num1, num2 = num2, num1

    #  now below this we by default know that num1 is negative so we do:
    num1 = num1[1:]
    # initialization
    n = len(num1) + 1  # this is the minimum required bits in our architecture
    num1 = num1.rjust(n, '0')
    num2 = num2.rjust(n, '0')
    # print(num1, num2)
    m = lab2.makeTwosComplement(num1, len(num1))
    # -m is num1
    q = num2
    q0 = '0'
    a = '0' * n
    perm_n = n
    while(n != 0):
        check = q[perm_n-1]+q0
        if(check == '00' or check == '11'):
            pass
        elif (check == '10'):
            data = lab1.NbitAdder(a, num1)
            a = data.result()[0]
        elif (check == '01'):
            data = lab1.NbitAdder(a, m)
            a = data.result()[0]

        a, q, q0 = arithSR(a, q, q0,perm_n)
        n = n-1

    finalRes = lab2.makeTwosComplement(a+q,len(a+q))
    print(a+q)
    print(f"-{finalRes}")