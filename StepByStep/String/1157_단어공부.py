N = input().upper()
N_Set = set(N)
numOfAlp = []
for i in N_Set:
    numOfAlp.append(N.count(i))
idx = [i for i, x in enumerate(numOfAlp) if x == max(numOfAlp)]

if len(idx) > 1:
    print("?")
else:
    print(list(N_Set)[idx[0]])
