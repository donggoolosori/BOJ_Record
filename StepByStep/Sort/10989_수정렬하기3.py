import sys
MAX_NUM = 10000
N = int(sys.stdin.readline())
count = [0]*(MAX_NUM+1)
for _ in range(N):
    count[int(sys.stdin.readline())] += 1

for i in range(1, MAX_NUM+1):
    if count[i] != 0:
        for _ in range(count[i]):
            print(i)
