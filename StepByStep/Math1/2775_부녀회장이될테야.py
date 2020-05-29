T = int(input())
weridApart = [[0]*15 for _ in range(15)]
for i in range(15):
    weridApart[0][i] = i+1
    weridApart[i][0] = 1
for row in range(1, 15):
    for col in range(1, 15):
        weridApart[row][col] = weridApart[row-1][col] + weridApart[row][col-1]


for testcase in range(T):
    k = int(input())
    n = int(input())
    print(weridApart[k][n-1])
