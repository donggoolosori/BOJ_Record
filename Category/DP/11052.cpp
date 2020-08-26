#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> card_price(n + 1);
    vector<int> dp(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
        cin >> card_price[i];

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = i; j < n + 1; j++)
        {
            dp[j] = max(dp[j], dp[j - i] + card_price[i]);
        }
    }
    cout << dp[n];
    return 0;
}