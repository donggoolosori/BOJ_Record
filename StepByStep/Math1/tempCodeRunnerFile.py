import math
T = int(input())

for testcast in range(T):
    x, y = map(int, input().split())
    distance = y-x
    numOfWorking = math.ceil(math.sqrt(distance)) + \
        1 if distance >= 4 else distance
    print(numOfWorking)
