import math
T = int(input())

for testcast in range(T):
    x, y = map(int, input().split())
    distance = y-x  # x와 y의 거리
    n = round(math.sqrt(distance))  # 거리를 수열로 나타냈을때 가장 큰 수
    numOfWorking = n*2 if n < math.sqrt(distance) else n*2 - 1
    numOfWorking = distance if distance < 4 else numOfWorking
    print(numOfWorking)
