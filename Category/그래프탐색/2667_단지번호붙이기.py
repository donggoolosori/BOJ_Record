import sys


def DFS(r, c):
    vill[r][c] = 0
    h_num[cnt] += 1
    for i in range(4):
        nr = r+dx[i]
        nc = c+dy[i]
        if 0 <= nr < n and 0 <= nc < n and vill[nr][nc] == 1:
            DFS(nr, nc)


if __name__ == "__main__":
    n = int(sys.stdin.readline())
    vill = [list(map(int, sys.stdin.readline().rstrip())) for _ in range(n)]
    h_num = []
    cnt = 0
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    for i in range(n):
        for j in range(n):
            if vill[i][j] == 1:
                h_num.append(0)
                DFS(i, j)
                cnt += 1
    print(cnt)
    for i in sorted(h_num):
        print(i)
