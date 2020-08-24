#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> maze(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++)
            cin >> maze[i][j];

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            dp[i][j] = maze[i][j] + max({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
        }
    }
    cout << dp[n][m];
    return 0;
}