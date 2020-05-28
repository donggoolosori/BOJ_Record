A, B, C = map(int, input().split())
# A + B*n < C*n
answer = int(A/(C-B))+1 if C > B else -1
print(answer)
