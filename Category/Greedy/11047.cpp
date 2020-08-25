#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> coin(n);
    for (int i = 0; i < n; i++)
        cin >> coin[i];
    sort(coin.begin(), coin.end(), compare);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += (k / coin[i]);
        k -= (k / coin[i]) * coin[i];
    }

    cout << res;

    return 0;
}