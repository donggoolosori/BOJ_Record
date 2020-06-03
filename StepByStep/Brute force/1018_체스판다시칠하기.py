row, col = map(int, input().split())
board = []
answer = row*col
# board판 입력 받기
for _ in range(row):
    board.append(input())
whiteFirst = ["WBWBWBWB",
              "BWBWBWBW",
              "WBWBWBWB",
              "BWBWBWBW",
              "WBWBWBWB",
              "BWBWBWBW",
              "WBWBWBWB",
              "BWBWBWBW"]
blackFirst = ["BWBWBWBW",
              "WBWBWBWB",
              "BWBWBWBW",
              "WBWBWBWB",
              "BWBWBWBW",
              "WBWBWBWB",
              "BWBWBWBW",
              "WBWBWBWB"]

for i in range(row-7):
    for j in range(col-7):
        cnt_b = 0
        cnt_w = 0
        for k in range(8):
            for m in range(8):
                # black이 먼저인 기준
                if board[i+k][j+m] != blackFirst[k][m]:
                    cnt_b += 1
                # white가 먼저인 기준
                if board[i+k][j+m] != whiteFirst[k][m]:
                    cnt_w += 1
        cnt = cnt_b if cnt_b < cnt_w else cnt_w
        if cnt < answer:
            answer = cnt
print(answer)
