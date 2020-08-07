import sys


def dfs(start, visited):
    visited.append(start)
    for i in range(1, n+1):
        if mtx[start][i] == 1 and (i not in visited):
            dfs(i, visited)
    return visited


def bfs(start):
    visited = [start]
    Q = [start]
    while Q:
        now = Q.pop(0)
        for i in range(1, n+1):
            if mtx[now][i] == 1 and (i not in visited):
                Q.append(i)
                visited.append(i)
    return visited


if __name__ == "__main__":
    n, m, v = map(int, sys.stdin.readline().split())
    mtx = [[0]*(n+1) for _ in range(n+1)]
    for _ in range(m):
        fr, to = map(int, sys.stdin.readline().split())
        mtx[fr][to] = 1
        mtx[to][fr] = 1
    print(*dfs(v, []))
    print(*bfs(v))
