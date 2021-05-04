#include <iostream>
#include <string>
#define ll long long

using namespace std;

ll A, B, C;

ll getPow(ll n, ll r)
{
    if (r == 0)
        return 1;
    if (r % 2 == 1)
        return getPow(n, r - 1) * n % C;
    ll temp = getPow(n, r / 2) % C;
    return temp * temp % C;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;
    cout << getPow(A, B);
    return 0;
}