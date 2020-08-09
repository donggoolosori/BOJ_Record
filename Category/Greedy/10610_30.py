import sys

n = sys.stdin.readline().rstrip()

if '0' not in n:
    print(-1)
else:
    digit_sum = 0
    for i in n:
        digit_sum += int(i)
    if digit_sum % 3 != 0:
        print(-1)
    else:
        for i in sorted(n, reverse=True):
            print(i, end='')
