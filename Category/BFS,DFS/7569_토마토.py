import sys
from collections import deque
input = sys.stdin.readline

m, n, h = map(int, input().split())
visit = [[[0]*m for _ in range(n)] for _ in range(h)]
box = [[list(map(int, input().split()))
        for _ in range(n)] for _ in range(h)]
dx = [-1, 0, 1, 0, 0, 0]
dy = [0, 1, 0, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]
Q = deque()
for height in range(h):
    for i in range(n):
        for j in range(m):
            if box[height][i][j] == 1:
                Q.append((height, i, j))
                visit[height][i][j] = 1

while Q:
    cur_z, cur_y, cur_x = Q.popleft()
    for k in range(6):
        z = cur_z+dz[k]
        y = cur_y+dy[k]
        x = cur_x+dx[k]
        if 0 <= x < m and 0 <= y < n and 0 <= z < h and box[z][y][x] == 0 and visit[z][y][x] == 0:
            box[z][y][x] = box[cur_z][cur_y][cur_x]+1
            visit[z][y][x] = 1
            Q.append((z, y, x))
res = -2147000000

for z in box:
    for y in z:
        if 0 in y:
            print(-1)
            sys.exit(0)

for z in box:
    for y in z:
        res = max(res, max(y))
print(res-1)
