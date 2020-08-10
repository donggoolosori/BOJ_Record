import sys
input = sys.stdin.readline


def flip(x, y):
    for i in range(x, x+3):
        for j in range(y, y+3):
            A[i][j] = 1-A[i][j]


if __name__ == "__main__":
    n, m = map(int, input().split())
    A = [list(map(int, input().rstrip())) for _ in range(n)]
    B = [list(map(int, input().rstrip())) for _ in range(n)]
    cnt = 0
    for i in range(n-2):
        for j in range(m-2):
            if A[i][j] != B[i][j]:
                flip(i, j)
                cnt += 1
    if A == B:
        print(cnt)
    else:
        print(-1)
