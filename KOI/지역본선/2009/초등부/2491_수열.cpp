#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int MAX = 1;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    vector<vector<int>> dp(n, vector<int>(2, 1));
    // 0인덱스는 증가 1은 감소

    for (int i = 1; i < n; i++)
    {
        if (num[i - 1] == num[i])
        {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1] + 1;
        }
        else if (num[i - 1] < num[i])
            dp[i][0] = dp[i - 1][0] + 1;
        else
            dp[i][1] = dp[i - 1][1] + 1;

        MAX = max(MAX, max(dp[i][0], dp[i][1]));
    }
    cout << MAX;

    return 0;
}