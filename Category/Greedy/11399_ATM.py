import sys

n = int(sys.stdin.readline())
lst = list(enumerate(map(int, sys.stdin.readline().split())))
lst.sort(key=lambda x: x[1])
res = 0
s = 0
for i in range(n):
    s += lst[i][1]
    res += s
print(res)
