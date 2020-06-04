from collections import Counter
import sys


# 산술평균
def mean(arr):
    sumOfArr = sum(arr)
    return round(sumOfArr/len(arr))


# 중앙값
def median(arr):
    return arr[len(arr)//2]


# 최빈값
def mode(arr):
    if len(arr) == 1:
        return arr[0]
    result = Counter(arr).most_common(2)
    return result[1][0] if result[0][1] == result[1][1] else result[0][0]


# 범위
def width(arr):
    length = len(arr)
    if len == 1:
        return 0
    return max(arr) - min(arr)


N = int(sys.stdin.readline())
arr = []
for _ in range(N):
    arr.append(int(sys.stdin.readline()))
arr.sort()
print(mean(arr))
print(median(arr))
print(mode(arr))
print(width(arr))
