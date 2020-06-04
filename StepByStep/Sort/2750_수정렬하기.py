N = int(input())
numArr = []
for _ in range(N):
    numArr.append(int(input()))

numArr.sort()
for i in numArr:
    print(i)
