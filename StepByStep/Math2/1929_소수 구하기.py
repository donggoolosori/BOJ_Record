def isPrime(num):
    if num == 2:
        return True
    if num % 2 == 0 or num == 1:
        return False
    else:
        bound = int(num**(1/2))
        for i in range(3, bound+1):
            if num % i == 0:
                return False
    return True


M, N = map(int, input().split())
for num in range(M, N+1):
    if isPrime(num):
        print(num)
