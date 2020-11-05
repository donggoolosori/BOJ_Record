#include <iostream>
#define min(a, b) a < b ? a : b

using namespace std;

int n, m;
int sum, min_res = 10001;
bool isSqr[10001];

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
}

void solve()
{
    for (int i = 1; i * i <= 10000; i++)
    {
        isSqr[i * i] = true;
    }
    for (int i = m; i <= n; i++)
    {
        if (isSqr[i])
        {
            sum += i;
            min_res = min(min_res, i);
        }
    }
    if (min_res == 10001)
        cout << -1 << '\n';
    else
    {
        cout << sum << '\n'
             << min_res << '\n';
    }
}

int main()
{
    input();
    solve();

    return 0;
}