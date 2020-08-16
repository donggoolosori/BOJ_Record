from sys import stdin
input = stdin.readline

if __name__ == "__main__":
    n = int(input())
    dp = [0]*(91)
    for i in range(3):
        dp[i] = 1
    for i in range(3, n+1):
        dp[i] = dp[i-1]+dp[i-2]
    print(dp[n])
