import sys
input = sys.stdin.readline

n = int(input())

res = 0

while(n % 5 != 0 and n >= 0):
    res += 1
    n -= 2

if(n < 0):
    print(-1)
else:
    res += n//5
    print(res)
