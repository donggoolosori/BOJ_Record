while True:
    a, b, c = map(int, input().split())
    if a == 0 and b == 0 and c == 0:
        break
    li = [a, b, c]
    maxNum = max(li)
    li.remove(maxNum)
    if li[0]**2 + li[1]**2 == maxNum**2:
        print("right")
    else:
        print("wrong")
