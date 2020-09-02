#include <iostream>
#include <vector>

#define max(a, b) a > b ? a : b

using namespace std;

int n;
int ans[2];
int left_diagonal[20];
int right_diagonal[20];

void dfs(vector<vector<int>> board, int row, int col, int cnt, int color)
{
    if (col >= n)
    {
        row++;
        if (col % 2 == 0)
            col = 1;
        else
            col = 0;
    }
    if (row >= n)
    {
        ans[color] = max(ans[color], cnt);
        return;
    }
    if (board[row][col] && !left_diagonal[col - row + n - 1] && !right_diagonal[row + col])
    {
        left_diagonal[col - row + n - 1] = right_diagonal[row + col] = 1;
        dfs(board, row, col + 2, cnt + 1, color);
        left_diagonal[col - row + n - 1] = right_diagonal[row + col] = 0;
    }
    dfs(board, row, col + 2, cnt, color);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    dfs(board, 0, 0, 0, 0); // 검은 칸
    dfs(board, 0, 1, 0, 1); // 흰 칸

    int res = ans[0] + ans[1];
    cout << res;
    return 0;
}