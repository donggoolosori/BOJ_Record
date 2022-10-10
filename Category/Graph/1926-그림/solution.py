from sys import stdin, setrecursionlimit

input = stdin.readline

setrecursionlimit(10 ** 6)

n, m = map(int, input().split())
paper = [list(map(int, input().split())) for _ in range(n)]

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

count = 0
max_area = 0


def dfs(y, x):
    global dy, dx, paper

    ret = 1
    for i in range(4):
        ny = y+dy[i]
        nx = x+dx[i]
        if ny < 0 or nx < 0 or ny >= n or nx >= m:
            continue
        if paper[ny][nx] == 0:
            continue
        paper[ny][nx] = 0
        ret += dfs(ny, nx)
    return ret


for i in range(n):
    for j in range(m):
        if paper[i][j] == 0:
            continue
        paper[i][j] = 0
        count += 1
        max_area = max(max_area, dfs(i, j))

print(count, max_area, sep='\n')
