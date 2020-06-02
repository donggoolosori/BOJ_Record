def stars(childStar):
    newStar = []
    for i in range(3*len(childStar)):
        if i//len(childStar) == 1:
            newStar.append(childStar[i % len(childStar)] +
                           ' '*len(childStar)
                           + childStar[i % len(childStar)])
        else:
            newStar.append(childStar[i % len(childStar)] * 3)
    return newStar


star = ["***", "* *", "***"]
N = int(input())
k = 0
while N != 3:
    N /= 3
    k += 1
for _ in range(k):
    star = stars(star)
for i in star:
    print(i)
