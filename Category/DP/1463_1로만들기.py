import sys
from collections import deque
input = sys.stdin.readline


def bfs():
    while Q:
        cur = Q.popleft()
        if cur == 1:
            return visit[1]
        if cur % 3 == 0:
            check_next(cur, cur//3)
        if cur % 2 == 0:
            check_next(cur, cur//2)
        check_next(cur, cur-1)


def check_next(cur, next):
    if 0 < next and not visit[next]:
        visit[next] = visit[cur]+1
        Q.append(next)


if __name__ == "__main__":
    n = int(input())
    visit = [0]*(n+1)
    Q = deque([n])
    print(bfs())
