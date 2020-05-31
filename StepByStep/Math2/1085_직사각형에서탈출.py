x, y, w, h = map(int, input().split())
horizon = w-x if x >= w/2 else x
vertical = h-y if y >= h/2 else y
print(horizon if horizon < vertical else vertical)
