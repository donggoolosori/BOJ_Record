from sys import stdin, exit
input = stdin.readline


def check(i, j):
    promising = [i for i in range(1, 10)]
    for k in range(9):
        if sudoku[i][k] in promising:  # 행 체크
            promising.remove(sudoku[i][k])
        if sudoku[k][j] in promising:  # 열 체크
            promising.remove(sudoku[k][j])

    # 격자 체크
    i //= 3
    j //= 3
    for k in range(3):
        for m in range(3):
            if sudoku[3*i+k][3*j+m] in promising:
                promising.remove(sudoku[3*i+k][3*j+m])

    return promising


def dfs(L):
    if L == len(zeros):
        for row in sudoku:
            print(*row)
        exit(0)

    else:
        i, j = zeros[L]
        promising = check(i, j)  # 유망한 숫자들의 리스트
        for num in promising:
            sudoku[i][j] = num
            dfs(L+1)
            sudoku[i][j] = 0


if __name__ == "__main__":
    sudoku = [list(map(int, input().split())) for _ in range(9)]
    zeros = [(i, j) for i in range(9) for j in range(9) if sudoku[i][j] == 0]
    dfs(0)
