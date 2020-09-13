#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    vector<int> dp(n, 0);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (num[j] < num[i])
                temp = max(temp, dp[j]);
        }
        dp[i] = max(dp[i], num[i] + temp);
        res = max(res, dp[i]);
    }
    cout << res << '\n';

    return 0;
}