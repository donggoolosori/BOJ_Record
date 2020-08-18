import sys
input = sys.stdin.readline


def setDp():
    dp = [0]*12
    dp[1] = 1
    dp[2] = 2
    dp[3] = 4
    for i in range(4, 12):
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3]
    return dp


if __name__ == "__main__":
    dp = setDp()
    for _ in range(int(input())):
        n = int(input())
        print(dp[n])
