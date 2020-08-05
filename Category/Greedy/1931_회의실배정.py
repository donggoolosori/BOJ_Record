import sys

n = int(sys.stdin.readline())
meeting = []
for _ in range(n):
    meeting.append(tuple(map(int, sys.stdin.readline().split())))
meeting.sort(key=lambda x: (x[1], x[0]))
cnt = 0
et = 0
for s, e in meeting:
    if s >= et:
        et = e
        cnt += 1
print(cnt)
