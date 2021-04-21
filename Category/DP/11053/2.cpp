#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];

    int res = 0;
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int max_dp = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (num[i] > num[j] && dp[j] > max_dp)
            {
                max_dp = dp[j];
            }
        }
        dp[i] = max_dp + 1;
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}