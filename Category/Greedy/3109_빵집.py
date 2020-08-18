import sys
input = sys.stdin.readline


def solve(i, j):
    if j == c-1:
        return True
    for d in dr:
        n_r, n_c = i+d, j+1
        if 0 <= n_r < r and not visit[n_r][n_c] and mapInfo[n_r][n_c] == '.':
            visit[n_r][n_c] = True
            if solve(n_r, n_c):
                return True
    return False


if __name__ == "__main__":
    r, c = map(int, input().split())
    mapInfo = [input().rstrip() for _ in range(r)]
    visit = [[False]*c for _ in range(r)]
    dr = [-1, 0, 1]
    cnt = 0
    for row in range(r):
        if solve(row, 0):
            cnt += 1
    print(cnt)
