dial = [(i//3)+3 for i in range(15)]
dial += [8]*4
dial += [9]*3
dial += [10]*4

dial_Alp = input()
dial_Alp = [ord(i)-ord("A") for i in dial_Alp]
totalTime = 0
for i in dial_Alp:
    totalTime += dial[i]
print(totalTime)
