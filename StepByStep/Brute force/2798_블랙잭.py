numOfCards, targetNum = map(int, input().split())
numArr = list(map(int, input().split()))

answer = 0
for i in range(numOfCards-2):
    for j in range(i+1, numOfCards-1):
        for k in range(j+1, numOfCards):
            temp = numArr[i] + numArr[j] + numArr[k]
            if temp > answer and temp <= targetNum:
                answer = temp
print(answer)
