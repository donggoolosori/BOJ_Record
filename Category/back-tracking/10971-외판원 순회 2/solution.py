import sys
input = sys.stdin.readline

N = int(input())
W = [list(map(int, input().split())) for _ in range(N)]
min_cost = sys.maxsize


def backtracking(start, curr, visited, cost):
    global min_cost

    if cost >= min_cost:
        return
    if len(visited) == N:
        if W[curr][start] != 0:
            min_cost = min(min_cost, cost + W[curr][start])
        return

    for i in range(N):
        if i in visited:
            continue
        if W[curr][i] == 0:
            continue
        visited.append(i)
        backtracking(start, i, visited, cost+W[curr][i])
        visited.pop()


for i in range(N):
    backtracking(i, i, [i], 0)

print(min_cost)
