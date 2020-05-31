def eratos(maxNum):
    primeList = [True]*maxNum
    dLimit = int(maxNum**0.5)
    for i in range(2, dLimit+1):
        if primeList[i]:
            for j in range(i+i, maxNum, i):
                primeList[j] = False
    return [i for i in range(2, maxNum) if primeList[i]]


primeList = eratos(10000)
T = int(input())
for _ in range(T):
    n = int(input())
    for i in range(n//2, 1, -1):
        if i in primeList and n-i in primeList:
            part = i
            break

    print(part, n-part)
