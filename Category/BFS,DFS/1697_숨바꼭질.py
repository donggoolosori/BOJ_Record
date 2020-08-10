import sys
from collections import deque
input = sys.stdin.readline


def bfs():
    while Q:
        cur = Q.popleft()
        if cur == ep:
            return visit[cur]
        checkNxt(cur, cur+1)
        checkNxt(cur, cur-1)
        checkNxt(cur, cur*2)


def checkNxt(cur, nxt):
    if MAX > nxt >= 0 and (visit[nxt] == 0 or visit[cur]+1 < visit[nxt]):
        visit[nxt] = visit[cur]+1
        Q.append(nxt)


if __name__ == "__main__":
    MAX = 100001
    sp, ep = map(int, input().split())
    visit = [0]*MAX
    if sp >= ep:
        print(sp-ep)
    else:
        Q = deque([sp])
        print(bfs())
