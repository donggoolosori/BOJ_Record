#include <iostream>

using namespace std;

typedef long long int ll;

ll pow_recur(ll a, ll b, ll c)
{
    if (b == 0)
        return 1;

    if (b % 2 == 1)
        return pow_recur(a, b - 1, c) * a;

    ll n = pow_recur(a, b / 2, c) % c;
    return n * n % c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll A, B, C;
    cin >> A >> B >> C;
    ll ans = pow_recur(A, B, C) % C;
    cout << ans << '\n';

    return 0;
}