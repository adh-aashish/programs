import lab1


def multiply(num1, num2):
    l1 = len(num1)
    l2 = len(num2)
    max = l1 if l1 >= l2 else l2
    psum = '0'
    for i in range(l2-1, -1, -1):
            if(num2[i] == '1'):
                step = num1
                for i in range(l2-1-i):
                    step = step+"0"
                data = lab1.NbitAdder(psum, step)
                psum, carry = data.result()
                if(carry == 1):
                    psum = str(carry)+psum
    return psum


if __name__ == "__main__":
    num1 = input("Enter first number: ")
    num2 = input("Enter second number: ")

    prod = multiply(num1,num2)
    print(prod)