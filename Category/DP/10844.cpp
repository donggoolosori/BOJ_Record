#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int dp[101][10] = {0};
    for (int i = 1; i < 10; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i < n + 1; i++)
    {
        dp[i][0] = dp[i - 1][1];
        dp[i][9] = dp[i - 1][8];
        for (int j = 1; j < 9; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }
    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum = (sum + dp[n][i]) % 1000000000;
    cout << sum % 1000000000 << '\n';

    return 0;
}