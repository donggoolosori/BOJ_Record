from sys import stdin, setrecursionlimit

setrecursionlimit(10**6)

input = stdin.readline

# n, m 을 int로 입력받는다
n, m = map(int, input().split())


class Solution:
    def __init__(self, n, m):
        self.n = n
        self.m = m
        self.parent = [i for i in range(n + 1)]

    def execute(self):
        answer = []

        for _ in range(m):
            op, a, b = map(int, input().split())
            if op == 0:
                self.union(a, b)
            elif op == 1:
                if self.find(a) == self.find(b):
                    answer.append("YES")
                else:
                    answer.append("NO")

        print("\n".join(answer))

    def union(self, a, b):
        a = self.find(a)
        b = self.find(b)
        if a < b:
            self.parent[b] = a
        else:
            self.parent[a] = b

    def find(self, a):
        if a == self.parent[a]:
            return a
        self.parent[a] = self.find(self.parent[a])
        return self.parent[a]


Solution(n, m).execute()
