N = int(input())
boundary = 1
numOfShell = 1
for i in range(1, N+1):
    if N <= boundary:
        numOfShell = i
        break
    boundary = boundary + 6*i
print(numOfShell)
