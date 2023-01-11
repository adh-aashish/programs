import lab1

def makeTwosComplement(a, size):
    l = len(a)
    a = list(a)
    if(l != size):
        raise Exception("Error size sent")
    else:
        for i in range(l-1, -1, -1):
            if(a[i] == '1'):
                a[i] = '0'
            else:
                a[i] = '1'
        a = ''.join(a)
    data = lab1.NbitAdder(a, '1')
    sum, carry = data.result()
    if(carry == 1):
        sum = str(carry)+sum
    return sum


def subtract(num1, num2):
    storenum2 = num2
    l1 = len(num1)
    l2 = len(num2)

    max = l1 if l1 >= l2 else l2
    num1 = num1.rjust(max, '0')
    num2 = num2.rjust(max, '0')
    # print(len(num1), len(num2))
    # print(num1, num2)
    # exit(0)
    num2 = makeTwosComplement(num2, max)

    # so, now 2s comp. is made
    data = lab1.NbitAdder(num1, num2)

    return data.result()


if __name__ == "__main__":
    num1 = input("Enter number 1: ")
    num2 = input("Enter number 2: ")

    res, carry = subtract(num1, num2)

    if (carry == 1):
        print(f"So, {num1}-{num2}={res}")
    else:
        res = makeTwosComplement(res, len(res))
        print(f"So, {num1}-{num2}=-{res}")