def endNum(order):
    cnt = 1
    i = 666
    while cnt < order:
        i += 1
        if str(i).find('666') >= 0:
            cnt += 1
    return i


N = int(input())
print(endNum(N))
