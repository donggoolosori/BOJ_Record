#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> cost[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(3, 0));
    for (int i = 0; i < 3; i++)
        dp[0][i] = cost[0][i];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + cost[i][2];
    }
    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    return 0;
}