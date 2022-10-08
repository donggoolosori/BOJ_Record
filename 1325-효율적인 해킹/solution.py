import sys
input = sys.stdin.readline

N, M = map(int, input().split())

network = [[] for _ in range(N+1)]

for _ in range(M):
    a, b = map(int, input().split())
    network[b].append(a)

visited = [False]*(N+1)
dp = [-1]*(N+1)


def dfs(curr):
    global visited

    if (dp[curr] != -1):
        return dp[curr]

    count = 1
    for next in network[curr]:
        if visited[next]:
            continue
        visited[next] = True
        count += dfs(next)
        visited[next] = False
    dp[curr] = count

    return dp[curr]


max_hacking = 0
answer = []

for i in range(1, N+1):
    hacking = dfs(i)
    if hacking > max_hacking:
        max_hacking = hacking
        answer = [i]
    elif hacking == max_hacking:
        answer.append(i)

print(*answer)
