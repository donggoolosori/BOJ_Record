#include <iostream>

using namespace std;

int ans, n;

void solve()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int a, b;
    while (n--)
    {
        cin >> a >> b;
        ans += (b % a);
    }
    cout << ans << '\n';
}

int main()
{
    solve();

    return 0;
}