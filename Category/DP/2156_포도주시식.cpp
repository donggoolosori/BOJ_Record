#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> wine(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> wine[i];
    }

    vector<int> dp(n + 1, 0);
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];
    int res = 0;
    for (int i = 3; i < n + 1; i++)
    {
        dp[i] = max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]);
        dp[i] = max(dp[i - 1], dp[i]);
        res = max(res, dp[i]);
    }
    if (res == 0)
    {
        if (n == 2)
            cout << dp[2];
        else
            cout << dp[1];
    }
    else
    {
        cout << res << '\n';
    }

    return 0;
}