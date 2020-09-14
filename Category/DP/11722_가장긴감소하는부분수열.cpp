#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> num(n, 1);
    for (int i = 0; i < n; i++)
        cin >> num[i];

    int res = 1;
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        int temp = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (num[j] > num[i])
                temp = max(temp, dp[j]);
        }
        dp[i] = temp + 1;
        res = max(res, dp[i]);
    }

    cout << res;
    return 0;
}