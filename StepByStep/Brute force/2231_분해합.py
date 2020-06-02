def divSum(num):
    stringNum = str(num)
    result = num
    for i in stringNum:
        result += int(i)
    return result


N = int(input())
answer = 0
for i in range(1, N+1):
    if divSum(i) == N:
        answer = i
        break
print(answer)
