#include <iostream>
#define max(a, b) a > b ? a : b

using namespace std;

int schedule[16][2];
int dp[17];
int n;
int ans;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> schedule[i][0] >> schedule[i][1];
    }
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        int t = schedule[i][0];
        if (i + t <= n + 1)
        {
            dp[i + t] = max(dp[i + t], dp[i] + schedule[i][1]);
            ans = max(ans, dp[i + t]);
        }
        dp[i + 1] = max(dp[i + 1], dp[i]);
        ans = max(ans, dp[i + 1]);
    }
    cout << ans << '\n';
}

int main()
{
    input();
    solve();

    return 0;
}