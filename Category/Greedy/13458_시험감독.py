import sys
import math
n = int(sys.stdin.readline())
cand = list(map(int, sys.stdin.readline().split()))
geD, assD = map(int, sys.stdin.readline().split())
cnt = n
for c in cand:
    goal = c-geD
    if goal <= 0:
        pass
    else:
        if assD > goal:
            cnt += 1
        else:
            cnt += math.ceil(goal/assD)
print(cnt)
