import sys

n, k = map(int, sys.stdin.readline().split())
coin = []
for _ in range(n):
    coin.append(int(sys.stdin.readline()))
coin.sort(reverse=True)
cnt = 0
for c in coin:
    if k == 0:
        break
    tmp = k//c
    cnt += tmp
    k -= c*tmp
print(cnt)
