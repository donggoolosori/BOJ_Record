def hanoi(num, fr, by, to):
    if num == 1:
        print(fr, to)
    else:
        hanoi(num-1, fr, to, by)
        print(fr, to)
        hanoi(num-1, by, fr, to)


numOfDisk = int(input())
numOfMove = 2**numOfDisk - 1
print(numOfMove)
hanoi(numOfDisk, 1, 2, 3)
