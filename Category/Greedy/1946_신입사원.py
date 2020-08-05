import sys

T = int(sys.stdin.readline())
for _ in range(T):
    n = int(sys.stdin.readline())
    new = []
    for _ in range(n):
        new.append(tuple(map(int, sys.stdin.readline().split())))
    new.sort()
    cnt = 0
    smallest = n+1
    for x, y in new:
        if y < smallest:
            smallest = y
            cnt += 1
    print(cnt)
