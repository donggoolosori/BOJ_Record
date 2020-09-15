import sys


def DFS(idx):
    visited[idx] = True
    nidx = series[idx]
    if not visited[nidx]:
        DFS(nidx)


T = int(sys.stdin.readline())
for _ in range(T):
    n = int(sys.stdin.readline())
    series = [0] + list(map(int, sys.stdin.readline().split()))
    visited = [False]*(n+1)
    cnt = 0
    for i in range(1, n+1):
        if not visited[i]:
            DFS(i)
            cnt += 1
    print(cnt)
