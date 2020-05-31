T = int(input())

for _ in range(T):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    d = ((x1-x2)**2 + (y1-y2)**2)**0.5  # 두 터렛 사이의 거리
    # 두 터렛이 같은 위치
    if (x1, y1) == (x2, y2):
        if r1 == r2:
            print(-1)
        else:
            print(0)
        continue
    # 원이 접하지 않을때
    if d > r1+r2 or d < abs(r1-r2):
        print(0)
    # 원이 외접 또는 내접
    elif d == r1+r2 or d == abs(r1-r2):
        print(1)

    else:
        print(2)
