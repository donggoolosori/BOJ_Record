import sys

n = int(sys.stdin.readline())
rope = []
for _ in range(n):
    rope.append(int(sys.stdin.readline()))
rope.sort(reverse=True)
res = rope[0]
for k in range(1, n):
    if rope[k]*(k+1) > res:
        res = rope[k]*(k+1)
print(res)
