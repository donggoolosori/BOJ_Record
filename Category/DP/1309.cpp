#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));

    for (int i = 0; i < 3; i++)
        dp[1][i] = 1;
    // 0 -> 사자가 없음, 1-> 사자가 왼쪽에, 2-> 사자 오른쪽
    for (int i = 2; i < n + 1; i++)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
    }
    int res = (dp[n][0] + dp[n][1] + dp[n][2]) % 9901;
    cout << res;

    return 0;
}