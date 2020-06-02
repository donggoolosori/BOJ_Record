factorial_list = [0]*13


def factorial(num):
    if num == 1 or num == 0:
        factorial_list[num] = num
        return 1
    else:
        if factorial_list[num] != 0:
            return factorial_list[num]
        factorial_list[num] = num*factorial(num-1)
        return factorial_list[num]``


N = int(input())
print(factorial(N))
