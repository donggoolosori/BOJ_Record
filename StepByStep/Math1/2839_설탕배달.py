N = int(input())
minNumOfBag = -1
for i in range(N//5, -1, -1):
    remain = N - i*5
    if remain % 3 == 0:
        minNumOfBag = i + remain//3
        break

print(minNumOfBag)
