import sys
import math

n_iter = 0
while(True):
    n_iter += 1
    L, P, V = map(int, sys.stdin.readline().split())
    if (L, P, V) == (0, 0, 0):
        break
    res = 0
    res += int(V/P)*L
    res += V % P if V % P <= L else L
    print("Case {}: {}".format(n_iter, res))
