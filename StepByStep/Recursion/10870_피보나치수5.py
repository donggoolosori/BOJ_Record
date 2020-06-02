def fibo(order):
    if order == 0:
        return 0
    elif order == 1:
        return 1
    else:
        return fibo(order-1)+fibo(order-2)


N = int(input())
print(fibo(N))
