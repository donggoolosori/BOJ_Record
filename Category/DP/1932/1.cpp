#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> num(n);

    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        while (j--)
        {
            int a;
            cin >> a;
            num[i].push_back(a);
        }
    }
    vector<vector<int>> dp(num);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < num[i].size(); j++)
        {
            int cur = dp[i][j];
            for (int k = j; k < j + 2; k++)
            {
                dp[i + 1][k] = max(dp[i + 1][k], cur + num[i + 1][k]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < dp[n - 1].size(); i++)
        ans = max(dp[n - 1][i], ans);
    cout << ans;
    return 0;
}