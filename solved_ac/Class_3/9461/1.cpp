#include <iostream>
#include <cstring>
#define ll long long

using namespace std;

ll cache[101];

ll getPado(int n)
{
    if (n <= 3)
        return 1;

    ll &ret = cache[n];
    if (ret != -1)
        return ret;

    return ret = getPado(n - 2) + getPado(n - 3);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cache, -1, sizeof(cache));

    int T, n;
    cin >> T;

    while (T--)
    {
        cin >> n;
        cout << getPado(n) << '\n';
    }

    return 0;
}