#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int cache[12];

int getCases(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    int &ret = cache[n];
    if (ret != -1)
        return ret;

    return ret = getCases(n - 1) + getCases(n - 2) + getCases(n - 3);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    memset(cache, -1, sizeof(cache));

    while (T--)
    {
        int n;
        cin >> n;
        cout << getCases(n) << '\n';
    }

    return 0;
}