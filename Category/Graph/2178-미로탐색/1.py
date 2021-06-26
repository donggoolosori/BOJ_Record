import sys


row, col = map(int, sys.stdin.readline().split())
maze = [list(map(int, sys.stdin.readline().rstrip())) for _ in range(row)]
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
cntMtx = [[0]*col for _ in range(row)]
cntMtx[0][0] = 1
Q = [(0, 0)]
while Q:
    r, c = Q.pop(0)
    if (r, c) == (row-1, col-1):
        print(cntMtx[r][c])
        break
    else:
        for i in range(4):
            x = r+dx[i]
            y = c+dy[i]
            if 0 <= x < row and 0 <= y < col and maze[x][y] == 1 and cntMtx[x][y] == 0:
                Q.append((x, y))
                cntMtx[x][y] = cntMtx[r][c]+1
