#include <iostream>
#include <cstring>

using namespace std;

int cache[41];

int getFibo(int n)
{
    if (n == 0 || n == 1)
        return n;

    int &ret = cache[n];
    if (ret != -1)
        return ret;

    return ret = getFibo(n - 1) + getFibo(n - 2);
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

        if (n == 0)
            cout << "1 0" << '\n';
        else if (n == 1)
            cout << "0 1" << '\n';
        else
            cout << getFibo(n - 1) << ' ' << getFibo(n) << '\n';
    }

    return 0;
}