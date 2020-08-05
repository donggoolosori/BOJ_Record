import sys

n = int(sys.stdin.readline())
cLv = list(map(int, sys.stdin.readline().split()))
maxLv_idx = cLv.index(max(cLv))
res = 0
for i in range(n):
    if i == maxLv_idx:
        continue
    res += cLv[maxLv_idx]+cLv[i]
print(res)
