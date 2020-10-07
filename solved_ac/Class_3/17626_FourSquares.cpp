#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> dp(n + 1, 50000);

    for (int i = 1; i <= sqrt(n); i++)
    {
        dp[i * i] = 1;
    }
    for (int i = 1; i <= sqrt(n); i++)
    {
        for (int j = 1; j <= n - i * i; j++)
        {
            dp[j + i * i] = min(dp[j + i * i], dp[j] + 1);
        }
    }

    cout << dp[n];
    return 0;
}