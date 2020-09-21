#include <iostream>

using namespace std;

int dp[11][11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
        dp[i][i] = 1;
    }
    cout << dp[n][k];

    return 0;
}