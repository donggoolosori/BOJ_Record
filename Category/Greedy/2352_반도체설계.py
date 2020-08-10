import sys
from bisect import bisect
input = sys.stdin.readline

if __name__ == "__main__":
    n = int(input())
    port = list(map(int, input().split()))
    dp = [port[0]]
    for i in range(1, n):
        if port[i] > dp[-1]:
            dp.append(port[i])
        else:
            dp[bisect(dp, port[i])] = port[i]
        print(dp)
    print(len(dp))
