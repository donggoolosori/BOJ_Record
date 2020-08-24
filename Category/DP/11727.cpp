#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dp[1001] = {0};
    dp[1] = 1;
    dp[2] = 3;

    int n;
    cin >> n;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
    }
    cout << dp[n];

    return 0;
}