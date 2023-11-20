from sys import stdin

input = stdin.readline

n = int(input())
liquids = list(map(int, input().split()))

liquids.sort()

l, r = 0, n - 1
min_sum = 2000000000
answer = [liquids[l], liquids[r]]
while l < r:
    sum = liquids[l] + liquids[r]
    if abs(sum) < min_sum:
        min_sum = abs(sum)
        answer = [liquids[l], liquids[r]]
    if sum < 0:
        l += 1
    elif sum > 0:
        r -= 1
    else:
        break

print(*answer)
