import sys
input = sys.stdin.readline

n = int(input())
houses = list(map(int, input().split()))

houses.sort()

l = len(houses)

print(houses[(l-1)//2])
