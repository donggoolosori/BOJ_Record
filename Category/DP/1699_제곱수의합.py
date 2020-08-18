import sys
input = sys.stdin.readline


def solve():
    for i in square_list:
        for j in range(i, n+1):
            tmp = dp[j-i]+1
            if dp[j] == 0 or tmp < dp[j]:
                dp[j] = tmp
    print(dp[-1])


if __name__ == "__main__":
    n = int(input())
    square_list = [i**2 for i in range(1, int(n**0.5)+1)]
    dp = [0]*(n+1)
    solve()
