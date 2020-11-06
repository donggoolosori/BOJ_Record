#include <iostream>
#include <cmath>

using namespace std;

int n;
int candidate[1000001];
int b, c;

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> candidate[i];
    cin >> b >> c;
}

void solve()
{
    long long res = n;
    for (int i = 0; i < n; i++)
    {
        double num = candidate[i] - b;
        num = num < 0 ? 0 : num;
        res += ceil(num / c);
    }
    cout << res << "\n";
}

int main()
{
    input();
    solve();

    return 0;
}