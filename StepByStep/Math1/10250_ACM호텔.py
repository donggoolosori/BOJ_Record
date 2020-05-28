T = int(input())

for testcase in range(T):
    H, W, N = map(int, input().split())
    if N % H == 0:
        roomNum = str(N//H) if N//H >= 10 else '0'+str(N//H)
        floor = str(H)
    else:
        roomNum = str(N//H+1) if N//H+1 >= 10 else '0'+str(N//H+1)
        floor = str(N % H)
    print(floor + roomNum)
