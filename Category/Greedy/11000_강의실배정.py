import sys
import heapq as hq

n = int(sys.stdin.readline())
cTime = []
for _ in range(n):
    cTime.append(tuple(map(int, sys.stdin.readline().split())))
cTime.sort(key=lambda x: x[0])
pq = []
hq.heappush(pq, cTime[0][1])
for i in range(1, n):
    if pq[0] <= cTime[i][0]:
        hq.heappop(pq)
        hq.heappush(pq, cTime[i][1])
    else:
        hq.heappush(pq, cTime[i][1])
print(len(pq))
