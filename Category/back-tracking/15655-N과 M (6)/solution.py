import sys

input = sys.stdin.readline

N, M = map(int, input().split())
nums = list(map(int, input().split()))
nums.sort()

arr = [0]*M


def permutation(L, idx):
    if L == M:
        print(*arr)
        return
    for i in range(idx, N):
        arr[L] = nums[i]
        permutation(L+1, i+1)


permutation(0, 0)
