#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    // nxn 보드판 생성
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<long long int>> dp(n, vector<long long int>(n, 0));
    dp[0][0] = 1;

    // 보드판 입력 받기
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] != 0 && board[i][j] != 0)
            {
                // 오른쪽 이동
                if (j + board[i][j] < n)
                {
                    dp[i][j + board[i][j]] += dp[i][j];
                }
                // 아래로 이동
                if (i + board[i][j] < n)
                {
                    dp[i + board[i][j]][j] += dp[i][j];
                }
            }
        }
    }
    cout << dp[n - 1][n - 1];

    return 0;
}