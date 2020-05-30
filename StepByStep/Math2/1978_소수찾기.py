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


N = int(input())
nums = list(map(int, input().split()))
cnt = 0

for i in range(len(nums)):
    if isPrime(nums[i]):
        cnt += 1
print(cnt)
