#include <iostream>
#include <vector>

using namespace std;

int checkRowCol(vector<vector<int>> board)
{
    int rowSum, colSum;
    int cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        rowSum = 0;
        colSum = 0;
        for (int j = 0; j < 5; j++)
        {
            rowSum += board[i][j];
            colSum += board[j][i];
        }
        if (rowSum == 0)
            cnt++;
        if (colSum == 0)
            cnt++;
    }
    return cnt;
}
int checkDiag(vector<vector<int>> board)
{
    int cnt = 0;
    int rSum = 0, lSum = 0;
    for (int i = 0; i < 5; i++)
    {
        rSum += board[i][i];
        lSum += board[4 - i][i];
    }
    if (rSum == 0)
        cnt++;
    if (lSum == 0)
        cnt++;

    return cnt;
}
bool checkBingo(vector<vector<int>> board)
{
    int cnt = 0;
    cnt += checkRowCol(board);
    cnt += checkDiag(board);
    if (cnt >= 3)
        return true;
    else
        return false;
}
void check(vector<vector<int>> &board, int target)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == target)
            {
                board[i][j] = 0;
                return;
            }
        }
    }
}
int main()
{
    int idx;
    vector<vector<int>> board(5, vector<int>(5));
    vector<int> calledNum(25);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 25; i++)
        cin >> calledNum[i];

    for (int i = 0; i < 25; i++)
    {
        check(board, calledNum[i]);
        if (i > 10)
        {
            if (checkBingo(board))
            {
                cout << i + 1;
                break;
            }
        }
    }

    return 0;
}