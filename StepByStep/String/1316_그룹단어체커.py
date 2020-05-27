N = int(input())
answer = N
for _ in range(N):
    word = input()
    for i in range(len(word)-1):
        if word.find(word[i]) > word.find(word[i+1]):
            answer -= 1
            break
print(answer)
