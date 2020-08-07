import sys

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
mtx = [[0]*(n+1) for _ in range(n+1)]
ch = [0]*(n+1)
ch[1] = 1
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    mtx[a][b] = 1
    mtx[b][a] = 1
Q = []
Q.append(1)
cnt = 0
while Q:
    c_row = Q.pop(0)
    for i in range(1, n+1):
        if mtx[c_row][i] == 1 and ch[i] == 0:
            Q.append(i)
            cnt += 1
            ch[i] = 1
print(cnt)
