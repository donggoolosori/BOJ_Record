natural_set = set(range(1, 10001))
dn_set = set()


def d(n):
    dn = n
    for i in str(n):
        dn += int(i)
    return dn


for i in range(1, 10001):
    dn_set.add(d(i))

selfNum_set = natural_set - dn_set
for i in sorted(selfNum_set):
    print(i)
