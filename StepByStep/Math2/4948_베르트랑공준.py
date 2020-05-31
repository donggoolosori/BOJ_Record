def eratos(maxNum):
    primeList = [True]*maxNum
    dLimit = int(maxNum**0.5)
    for i in range(2, dLimit+1):
        if primeList[i]:
            for j in range(i+i, maxNum, i):
                primeList[j] = False
    return [i for i in range(2, maxNum) if primeList[i]]


while True:
    n = int(input())
    if n == 0:
        break
    li = eratos(2*n+1)
    li = [i for i in li if i > n]
    print(len(li))
