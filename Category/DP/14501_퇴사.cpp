#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> schedule(n + 1);
    vector<int> dp(n + 2, 0);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> schedule[i].first >> schedule[i].second;
    }

    int res = 0;
    for (int i = 1; i < n + 1; i++)
    {
        int t = schedule[i].first;
        if (i + t <= n + 1)
        {
            dp[i + t] = max(dp[i + t], dp[i] + schedule[i].second);
            res = max(res, dp[i + t]);
        }
        dp[i + 1] = max(dp[i + 1], dp[i]);
        res = max(res, dp[i + 1]);
    }
    cout << res;

    return 0;
}
