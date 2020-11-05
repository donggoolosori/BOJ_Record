#include <iostream>

using namespace std;

void solve()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int c;
        double g;
        double den = 0, num = 0;
        while (n--)
        {
            cin >> c >> g;
            den += c;
            num += c * g;
        }
        cout.precision(2);
        cout << den << ' ' << num / den << '\n';
    }
}

int main()
{
    solve();

    return 0;
}