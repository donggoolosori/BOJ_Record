from sys import stdin
input = stdin.readline


def solve():
    dp = [100000]*(k+1)
    dp[0] = 0
    for i in coin_list:
        for j in range(i, k+1):
            dp[j] = min(dp[j], dp[j-i]+1)
    res = -1 if dp[k] == 100000 else dp[k]
    print(res)


if __name__ == "__main__":
    n, k = map(int, input().split())
    coin_list = [int(input()) for _ in range(n)]
    solve()
