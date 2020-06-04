words = [input() for _ in range(int(input()))]
words = sorted(set(words), key=lambda x: (len(x), x))
for i in words:
    print(i)
