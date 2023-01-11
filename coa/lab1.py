from pickletools import read_uint1


def AND(a,b):
    return a*b

def OR(a,b):
    return 1 if (a+b) >0 else 0

def NOT(a):
    return 1 if a==0 else 0

def NAND(a,b):
    return NOT(AND(a,b))

def NOR(a,b):
    return NOT(OR(a,b))

def XOR(a,b):
    return 1 if (a==1 and b ==0 or b==1 and a==0) else 0

def XNOR(a,b):
    return NOT(XOR(a,b))
    

class FullAdder(object):
    def __init__(self,a,b,c):
        self.a = a
        self.b = b
        self.c = c
    def sum(self):
        return XOR(XOR(self.a,self.b),self.c)
    def carry(self):
        return OR(AND(self.a,self.b),AND(XOR(self.a,self.b),self.c))

class NbitAdder():
    def __init__(self,A,B):
        self.A = A
        self.B = B
        # self.fullAdder = FullAdder()

    def result(self):
        l1 = len(self.A)
        l2 = len(self.B)
        # print(l1,l2)
        if(l1>l2):
            self.B = self.B.rjust(l1,'0')
        else:
            self.A = self.A.rjust(l2,'0')
        
        l1=len(self.A)
        carry = 0
        result = ""
        for i in range(l1-1,-1,-1):
            adder = FullAdder(int(self.A[i]),int(self.B[i]),carry)
            sum = adder.sum()
            carry = adder.carry()
            result = str(sum) + result
        
        return (result,carry)

if __name__ == "__main__":
    input1 = input("Enter first number: ")
    input2 = input("Enter second number: ")