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


M = int(input())
N = int(input())

primeNums = []
for num in range(M, N+1):
    if isPrime(num):
        primeNums.append(num)

# 소수 리스트가 비어있는 경우
if not primeNums:
    print(-1)
# 비어있지 않을 경우
else:
    sumOfPrime = sum(primeNums)
    minOfPrime = min(primeNums)
    print(sumOfPrime, minOfPrime, sep='\n')
