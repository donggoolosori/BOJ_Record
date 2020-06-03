numOfPeople = int(input())
dataArr = []

for _ in range(numOfPeople):
    w, t = map(int, input().split())
    dataArr.append([w, t])
for i in range(numOfPeople):
    cnt = 1
    for j in range(numOfPeople):
        if j == i:
            continue
        if dataArr[j][0] > dataArr[i][0] and dataArr[j][1] > dataArr[i][1]:
            cnt += 1
    dataArr[i].append(cnt)
for i in range(numOfPeople):
    print(dataArr[i][2], end=' ')
