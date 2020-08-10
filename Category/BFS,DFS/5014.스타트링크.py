import sys
from collections import deque
input = sys.stdin.readline


def bfs():
    while Q:
        cur = Q.popleft()
        if cur == g:
            return
        n_up = cur+u
        n_dn = cur-d
        for i in (n_up, n_dn):
            if 0 < i <= f and not visit[i] and i != s:
                visit[i] = visit[cur]+1
                Q.append(i)


if __name__ == "__main__":
    f, s, g, u, d = map(int, input().split())
    if s == g:
        print(0)
        sys.exit(0)
    visit = [0]*(f+1)
    Q = deque([s])
    bfs()
    res = visit[g]
    print(res if res != 0 else "use the stairs")
