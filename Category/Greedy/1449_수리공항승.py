import sys
input = sys.stdin.readline

if __name__ == "__main__":
    n, l = map(int, input().split())
    leak_point = list(map(int, input().split()))
    leak_point.sort()
    cnt = 0
    cover = l-1
    standard = 0
    for p in leak_point:
        if standard < p:
            standard = p+cover
            cnt += 1

    print(cnt)
