x = []
y = []
for _ in range(3):
    x1, y1 = map(int, input().split())
    x.append(x1) if x1 not in x else x.remove(x1)
    y.append(y1) if y1 not in y else y.remove(y1)
print(x[0], y[0])
