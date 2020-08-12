import sys
input = sys.stdin.readline


def dfs(L):
    if L == m:
        for i in res:
            print(i, end=' ')
        print()
    else:
        for i in range(1, n+1):
            if ch[i]:
                continue
            ch[i] = True
            res[L] = i
            dfs(L+1)
            ch[i] = False


if __name__ == "__main__":
    n, m = map(int, input().split())
    ch = [False]*(n+1)
    res = [0]*m
    dfs(0)
