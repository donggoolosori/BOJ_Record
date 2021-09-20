from sys import stdin
input = stdin.readline


def solve():
    res = 0
    for i in range(k):
        flag = False
        for j in range(n):
            if using[j] == 0 or using[j] == schedule[i]:
                flag = True
                using[j] = schedule[i]
                break
        if flag:
            continue
        else:
            max_idx = 0
            for j in range(n):
                try:
                    if max_idx < schedule[i+1:].index(using[j]):
                        max_idx = schedule[i+1:].index(using[j])
                        tmp = j
                except:
                    tmp = j
                    break
            using[tmp] = schedule[i]
            res += 1
    return res


if __name__ == "__main__":
    n, k = map(int, input().split())
    schedule = list(map(int, input().split()))
    using = [0]*n
    print(solve())
