import sys
input = sys.stdin.readline


def LIS():
    dp = [0]*n
    dp[0] = 1
    for i in range(1, n):
        max_dp = 0
        for j in range(i-1, -1, -1):
            if num_list[j] < num_list[i] and dp[j] > max_dp:
                max_dp = dp[j]
        dp[i] = 1+max_dp
    print(max(dp))


if __name__ == "__main__":
    n = int(input())
    num_list = list(map(int, input().split()))
    LIS()
