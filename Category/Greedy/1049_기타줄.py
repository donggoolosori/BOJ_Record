import sys
input = sys.stdin.readline

n, m = map(int, input().split())
pack = 1000
single = 1000
for _ in range(m):
    a, b = map(int, input().split())
    if a <= pack:
        pack = a
    if b <= single:
        single = b
res = 0
if n >= 6:
    quo = n//6
    rem = n % 6
    case = (pack*(quo+1), pack*quo+single*rem, single*n)
    res = min(case)
else:
    res = min(pack, single*n)
print(res)
