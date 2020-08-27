#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);

    for (int i = 1; i < sqrt(n) + 1; i++)
    {
        for (int j = i * i; j < n + 1; j++)
        {
            if (dp[j] == 0 || dp[j] > dp[j - i * i] + 1)
            {
                dp[j] = dp[j - i * i] + 1;
            }
        }
    }
    cout << dp[n];

    return 0;
}