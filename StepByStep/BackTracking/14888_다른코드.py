import sys
input = sys.stdin.readline


def calc(num, idx, add, minus, multi, div):
    global MAX, MIN
    if idx == n:
        MAX = max(num, MAX)
        MIN = min(num, MIN)
    else:
        if add:
            calc(num+num_list[idx], idx+1, add-1, minus, multi, div)
        if minus:
            calc(num-num_list[idx], idx+1, add, minus-1, multi, div)
        if multi:
            calc(num*num_list[idx], idx+1, add, minus, multi-1, div)
        if div:
            calc(int(num/num_list[idx]), idx+1, add, minus, multi, div-1)


if __name__ == "__main__":
    MAX = -sys.maxsize - 1
    MIN = sys.maxsize
    n = int(input())
    num_list = list(map(int, input().split()))
    a, mi, mu, di = map(int, input().split())
    calc(num_list[0], 1, a, mi, mu, di)
    print(MAX)
    print(MIN)
