#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long int> dp(n + 1);
    for (int i = 0; i < 3; i++)
        dp[i] = 1;
    for (int i = 3; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
    return 0;
}