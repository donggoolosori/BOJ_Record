import sys
from collections import deque
input = sys.stdin.readline


def bfs(r, c):
    Q = deque([(r, c)])
    melt_Q = deque()
    while Q:
        c_row, c_col = Q.popleft()
        water = 0
        for i in range(4):
            n_row = c_row+dr[i]
            n_col = c_col+dc[i]
            if ice[n_row][n_col] == 0:
                water += 1
            else:
                if not visit[n_row][n_col]:
                    visit[n_row][n_col] = 1
                    Q.append((n_row, n_col))
        melt_Q.append((c_row, c_col, water))
    return melt_Q


if __name__ == "__main__":
    n, m = map(int, input().split())
    ice = [list(map(int, input().split())) for _ in range(n)]
    dc = [-1, 0, 1, 0]
    dr = [0, 1, 0, -1]
    year = 0
    while True:
        visit = [[0]*m for _ in range(n)]
        cnt = 0
        for i in range(1, n-1):
            for j in range(1, m-1):
                if ice[i][j] and not visit[i][j]:
                    visit[i][j] = 1
                    melt_Q = bfs(i, j)
                    cnt += 1
                    while melt_Q:
                        row, col, melt = melt_Q.popleft()
                        ice[row][col] = max(0, ice[row][col]-melt)
        if cnt >= 2:
            break
        if cnt == 0:
            year = 0
            break
        year += 1
    print(year)
