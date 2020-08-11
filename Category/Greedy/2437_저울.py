import sys
input = sys.stdin.readline


def solve():
    num = 1
    for i in range(n):
        if num < w_lst[i]:
            break
        num += w_lst[i]
        print(num)
    print(num)


if __name__ == "__main__":
    n = int(input())
    w_lst = list(map(int, input().split()))
    w_lst.sort()
    solve()
