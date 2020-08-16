from sys import stdin, setrecursionlimit
setrecursionlimit(10000)
input = stdin.readline


def dfs(r, c):
    if (r, c) == (m-1, n-1):
        return 1
    if dp[r][c] != -1:
        return dp[r][c]
    dp[r][c] = 0
    for i in range(4):
        nr = r+dy[i]
        nc = c+dx[i]
        if 0 <= nr < m and 0 <= nc < n and mapInfo[nr][nc] < mapInfo[r][c]:
            dp[r][c] += dfs(nr, nc)
    return dp[r][c]


if __name__ == "__main__":
    m, n = map(int, input().split())
    mapInfo = [list(map(int, input().split())) for _ in range(m)]
    dp = [[-1]*n for _ in range(m)]
    print(dfs(0, 0))
