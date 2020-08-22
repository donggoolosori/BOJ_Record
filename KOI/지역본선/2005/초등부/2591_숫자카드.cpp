#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string series;
    cin >> series;

    int dp[45] = {0};
    dp[0] = 1;
    int i;
    for (i = 0; series[i]; i++)
    {
        int cur_val = series[i] - '0';
        if (cur_val)
        {
            dp[i + 1] += dp[i];
            if (cur_val * 10 + series[i + 1] - '0' <= 34)
                dp[i + 2] += dp[i];
        }
    }
    for (int i = 0; i < 6; i++)
        cout << dp[i] << '\n';

    return 0;
}