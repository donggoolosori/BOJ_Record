import sys
input = sys.stdin.readline


def solve():
    res = 0
    road_ = [[1]*n for _ in range(n)]
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if i == j or j == k or i == k:
                    continue
                # 최소 도로 아님
                if road[i][j] == road[i][k]+road[k][j]:
                    road_[i][j] = 0
                # 불가능한 경우
                elif road[i][j] > road[i][k]+road[k][j]:
                    print(-1)
                    sys.exit(0)

    for i in range(n):
        for j in range(i, n):
            if road_[i][j]:
                res += road[i][j]
    print(res)


if __name__ == "__main__":
    n = int(input())
    road = [list(map(int, input().split())) for _ in range(n)]
    solve()
