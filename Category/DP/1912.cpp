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
    vector<int> num(n);
    vector<int> dp(n);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    int sum = 0;
    int MAX = -1000;
    for (int i = 0; i < n; i++)
    {
        if (sum + num[i] > num[i])
        {
            sum += num[i];
            dp[i] = sum;
            MAX = max(MAX, dp[i]);
        }
        else
        {
            sum = num[i];
            dp[i] = sum;
            MAX = max(MAX, dp[i]);
        }
    }
    cout << MAX;

    return 0;
}