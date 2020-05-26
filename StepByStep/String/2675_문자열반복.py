T = int(input())
for testcase in range(T):
    R, S = input().split()
    R = int(R)
    for ch in S:
        print(ch*R, end="")
    print("")
