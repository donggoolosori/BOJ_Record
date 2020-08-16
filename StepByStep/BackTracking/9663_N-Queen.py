from sys import stdin
input = stdin.readline


def check(r):
    for i in range(r):
        if row[i] == row[r] or abs(row[r]-row[i]) == r-i:
            return False
    return True


def dfs(r):
    global cnt
    if r == n:
        cnt += 1
    else:
        for i in range(n):
            row[r] = i
            if check(r):
                dfs(r+1)


if __name__ == "__main__":
    n = int(input())
    row = [0]*n
    cnt = 0
    dfs(0)
    print(cnt)
