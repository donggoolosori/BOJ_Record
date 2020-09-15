#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct product
{
    int w, v;
};

int main()
{
    int n, k;
    cin >> n >> k;
    int w, v;
    vector<product> bag(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w >> v;
        bag[i] = {w, v};
    }

    int res = 0;
    vector<int> dp(k + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = k; j >= bag[i].w; j--)
        {
            dp[j] = max(dp[j], dp[j - bag[i].w] + bag[i].v);
        }
    }

    cout << dp[k];

    return 0;
}