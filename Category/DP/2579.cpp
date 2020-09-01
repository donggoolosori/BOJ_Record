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
    vector<int> stair(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int i = 1; i < n + 1; i++)
        cin >> stair[i];
    dp[1][0] = dp[1][1] = stair[1];
    for (int i = 2; i < n + 1; i++)
    {
        // 두칸 점프해서 현재 계단 i로 온 경우
        dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + stair[i];
        // 한칸 점프해서 현재 계단 i로 온 경우
        // 이 경우에는 바로 전 칸의 두 칸 점프한 경우만 가능
        dp[i][1] = dp[i - 1][0] + stair[i];
    }
    int res = max(dp[n][0], dp[n][1]);
    cout << res;
    return 0;
}