#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> coin(n);
    vector<int> dp(k + 1, 10000);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
        cin >> coin[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = coin[i]; j < k + 1; j++)
        {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }
    int res = dp[k] == 10000 ? -1 : dp[k];
    cout << res;
    return 0;
}