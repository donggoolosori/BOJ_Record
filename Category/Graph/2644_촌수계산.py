import sys

n = int(sys.stdin.readline())
fr, to = map(int, sys.stdin.readline().split())
m = int(sys.stdin.readline())
mtx = [[0]*(n+1) for _ in range(n+1)]
for _ in range(m):
    par, sub = map(int, sys.stdin.readline().split())
    mtx[par][sub] = mtx[sub][par] = 1

Q = [fr]
visited = [0]*(n+1)
while Q:
    cur = Q.pop(0)
    for i in range(1, n+1):
        if mtx[cur][i] == 1 and visited[i] == 0:
            visited[i] = visited[cur]+1
            Q.append(i)
print(visited[to] if visited[to] else -1)
