import sys
input = sys.stdin.readline


def solve():
    dp = [0]*(k+1)
    dp[0] = 1
    for i in coin_list:
        for j in range(i, k+1):
            dp[j] += dp[j-i]
    print(dp[-1])


if __name__ == "__main__":
    n, k = map(int, input().split())
    coin_list = [int(input()) for _ in range(n)]
    solve()
