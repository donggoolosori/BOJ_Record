arr = [tuple(map(int, input().split())) for _ in range(int(input()))]
arr = sorted(arr, key=lambda x: (x[0], x[1]))
for i in arr:
    print(i[0], i[1])
