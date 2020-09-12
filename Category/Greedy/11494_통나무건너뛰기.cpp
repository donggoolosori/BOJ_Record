#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        vector<int> num(n);
        for (int i = 0; i < n; i++)
            cin >> num[i];
        sort(num.begin(), num.end());
        int res;
        res = max(num[1] - num[0], num[n - 1] - num[n - 2]);
        for (int i = 0; i < n - 2; i++)
        {
            res = max(res, num[i + 2] - num[i]);
        }
        cout << res << '\n';
    }
    return 0;
}