from sys import stdin
input = stdin.readline


def solve():
    dp = [0]*(n+1)
    for idx, pr in enumerate(price):
        pack = idx+1
        for j in range(pack, n+1):
            dp[j] = max(dp[j], dp[j-pack]+pr)
    print(dp[n])


if __name__ == "__main__":
    n = int(input())
    price = list(map(int, input().split()))
    solve()
