#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int dp[1001][10] = {0};
    // 1자리 수일 경우 마지막에 오는 수 0~9에 따른 경우의 수는 모두 1
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
    int sum = 0;
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < j + 1; k++)
                dp[i][j] += dp[i - 1][k];
            dp[i][j] %= 10007;
        }
    }
    for (int i = 0; i < 10; i++)
        sum = (sum + dp[n][i]) % 10007;
    cout << sum % 10007;

    return 0;
}