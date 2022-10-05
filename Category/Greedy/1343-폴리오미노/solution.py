import sys
input = sys.stdin.readline

board = input().rstrip()
board += '.'
res = ''
count = 0
for i in board:
    if i == 'X':
        count += 1
    elif i == '.':
        if count % 2 != 0:
            print(-1)
            quit()
        else:
            res += "AAAA"*(count//4)
            count %= 4
            res += 'BB'*(count//2)
        count = 0
        res += '.'

print(res[:-1])
