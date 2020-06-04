arr = [list(input().split()) for _ in range(int(input()))]
for i in arr:
    i[0] = int(i[0])
arr = sorted(arr, key=lambda x: x[0])
for i in arr:
    print(i[0], i[1])
