import sys
input = sys.stdin.readline


def fibo(n):
    if dy[n] != 0:
        return dy[n]
    if n == 0:
        return dy[0]
    elif n == 1:
        return dy[1]
    else:
        dy[n] = fibo(n-1)+fibo(n-2)
        return dy[n]


if __name__ == "__main__":
    n = int(input())
    dy = [0]*46
    dy[0] = 0
    dy[1] = 1
    print(fibo(n))
