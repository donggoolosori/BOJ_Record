import heapq
from sys import stdin
from collections import deque
input = stdin.readline


if __name__ == "__main__":
    # n 보석 개수, k 가방 개수
    n, k = map(int, input().split())
    jw = [list(map(int, input().split())) for _ in range(n)]
    bag = [int(input()) for _ in range(k)]
    jw = deque(sorted(jw, key=lambda x: x[0]))
    bag.sort()
    res = 0
    heap = []

    for c in bag:
        while jw and c >= jw[0][0]:
            heapq.heappush(heap, -jw.popleft()[1])
        if heap:
            res -= heapq.heappop(heap)
    print(res)
