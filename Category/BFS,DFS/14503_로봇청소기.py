import sys
from collections import deque
input = sys.stdin.readline


# 방향을 왼쪽으로 바꾼다
def dir_left(d):
    new_d = d-1 if d != 0 else 3
    return new_d


# 방향을 뒤로 바꾼다
def dir_back(d):
    new_d = d+2 if d < 2 else d-2
    return new_d


# 탐색
def bfs(r, c, d):
    cnt = 1  # 청소하는 칸 개수
    mapInfo[r][c] = 2
    Q = deque([(r, c, d)])
    while Q:
        c_row, c_col, c_dir = Q.popleft()
        n_dir = c_dir
        for i in range(4):
            n_dir = dir_left(n_dir)
            n_row, n_col = c_row+dr[n_dir], c_col+dc[n_dir]
            if mapInfo[n_row][n_col] == 0:
                cnt += 1
                mapInfo[n_row][n_col] = 2
                Q.append((n_row, n_col, n_dir))
                break
            elif i == 3:
                n_dir = dir_back(c_dir)
                n_row, n_col = c_row+dr[n_dir], c_col+dc[n_dir]
                Q.append((n_row, n_col, c_dir))
                if mapInfo[n_row][n_col] == 1:
                    return cnt


if __name__ == "__main__":
    dr = [-1, 0, 1, 0]
    dc = [0, 1, 0, -1]
    n, m = map(int, input().split())
    r, c, d = map(int, input().split())
    mapInfo = [list(map(int, input().split())) for _ in range(n)]
    print(bfs(r, c, d))
