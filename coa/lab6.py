def rjust_number(n1, n2):
    l1 = len(n1)
    l2 = len(n2)
    if l1 > l2:
        n2 = n2 .rjust(l1, '0')
    elif l2 > l1 :
        n1 = n1.rjust(l2, '0')

    return (n1, n2)

def twoComplement(B):
    B_1C = ""

    for i in range(len(B)):
        temp = '1' if B[i] == '0' else '0'
        B_1C = B_1C + temp
        temp = ''

    B_1C, ones = rjust_number(B_1C, '1')
    B_2C = add(B_1C, ones , len(ones))
    
    return B_2C


def add(A, B, N):
    A = A[::-1]
    B = B[::-1]

    res = ""
    Carry = 0 
    for i in range(N):
        S = int(A[i]) ^ int(B[i]) ^ Carry 
        Carry = ( int(A[i]) & int(B[i]) ) | ( Carry & ( int(A[i]) ^ int(B[i] ) ) )
        res = str(S) + res

    res = str(Carry) + res 

    return res 

def sub(A, B, N):

    B_2C = twoComplement(B)
    
    B_2C , A  = rjust_number(B_2C, A)

    res = add(A, B_2C, len(A))

    res = res[:len(res)-N-1:-1]
    res = res[::-1]

    return res

def booth(B,Q,N):
    Q_1 = "0"
    A = "0"
    A,B = rjust_number(A, B)



    for i in range(N):
        if(Q[-1] + Q_1 == "10"):
            A = sub(A,B,len(B))
            A = A[len(A)-N:]

        if( Q[-1] + Q_1 == "01"):
            A = add(A,B, len(B))
            A = A[len(A)-N:]


        Q_1 = Q[-1]
        Q = A[-1] + Q[:-1]
        A = A[0] + A[:-1]

    return (A+Q)


def main():
    multiplicand = input("Multiplicand ")
    multiplier = input("Multiplier ")
    l1 = len(multiplicand)
    print(booth(multiplicand, multiplier, l1))


if __name__ == '__main__':
    main() 
