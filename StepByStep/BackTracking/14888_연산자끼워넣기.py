import sys
input = sys.stdin.readline


def calc(op):
    res = numList[0]
    for i in range(1, n):
        if op[i-1] == '+':
            res += numList[i]
        elif op[i-1] == '-':
            res -= numList[i]
        elif op[i-1] == '*':
            res *= numList[i]
        else:
            if res < 0:
                res = -((-res)//numList[i])
            else:
                res //= numList[i]
    return res


def dfs(L):
    if L == (n-1):
        res.append(calc(temp))
    else:
        for i in range(n-1):
            if not ch[i]:
                ch[i] = True
                temp[L] = opList[i]
                dfs(L+1)
                ch[i] = False


if __name__ == "__main__":
    n = int(input())
    numList = list(map(int, input().split()))
    opCnt = list(map(int, input().split()))
    op = ['+', '-', '*', '/']
    opList = []

    temp = [0]*(n-1)
    ch = [False]*(n-1)
    for i in range(4):
        opList += op[i]*opCnt[i]
    res = []
    dfs(0)
    print(max(res))
    print(min(res))
