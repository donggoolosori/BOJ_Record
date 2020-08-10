import sys
from collections import deque
input = sys.stdin.readline


def bfs():
    while Q:
        cur_row, cur_col = Q.popleft()
        for i in range(4):
            n_row = cur_row + dx[i]
            n_col = cur_col + dy[i]
            if 0 <= n_row < n and 0 <= n_col < n and tmpMap[n_row][n_col] == 1:
                tmpMap[n_row][n_col] = 0
                Q.append((n_row, n_col))


if __name__ == "__main__":
    n = int(input())
    mapInfo = [list(map(int, input().split())) for _ in range(n)]
    rainH = list(set(sum(mapInfo, [])))
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    res = 0
    for wH in rainH:
        tmpMap = [[0]*n for _ in range(n)]
        cnt = 0
        for i in range(n):
            for j in range(n):
                tmpMap[i][j] = 1 if mapInfo[i][j] >= wH else 0
        for i in range(n):
            for j in range(n):
                if tmpMap[i][j] == 1:
                    tmpMap[i][j] = 0
                    cnt += 1
                    Q = deque()
                    Q.append((i, j))
                    bfs()
        res = max(res, cnt)
    print(res)
