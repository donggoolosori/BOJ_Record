import sys
input = sys.stdin.readline


def check():
    for i in range(n+2):
        for j in range(n+2):
            if i == j:
                continue
            dis = abs(pos[i][0]-pos[j][0]) + abs(pos[i][1]-pos[j][1])
            if dis <= 1000:
                pos_grid[i][j] = 1
                pos_grid[j][i] = 1


def dfs(s):
    visit[s] = 1
    for i in range(n+2):
        if pos_grid[s][i] == 1 and not visit[i]:
            dfs(i)


if __name__ == "__main__":
    for _ in range(int(input())):
        n = int(input())
        pos = [list(map(int, input().split())) for _ in range(n+2)]
        pos_grid = [[0]*(n+2) for _ in range(n+2)]
        visit = [0]*(n+2)
        check()
        dfs(0)
        if visit[n+1]:
            print("happy")
        else:
            print("sad")
