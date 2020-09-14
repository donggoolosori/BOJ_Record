#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];

    vector<vector<int>> dp(2, vector<int>(n, 1));
    // 0~n 방향으로의 LIS dp구하기
    for (int i = 1; i < n; i++)
    {
        int temp = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (num[j] < num[i])
            {
                temp = max(temp, dp[0][j]);
            }
        }
        dp[0][i] = temp + 1;
    }
    // n->0 방향으로의 LIS dp구하기
    for (int i = n - 2; i >= 0; i--)
    {
        int temp = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (num[j] < num[i])
            {
                temp = max(temp, dp[1][j]);
            }
        }
        dp[1][i] = temp + 1;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, dp[0][i] + dp[1][i] - 1);
    }
    cout << res;
    return 0;
}