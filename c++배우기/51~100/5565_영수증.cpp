#include <iostream>

using namespace std;

int total_price;

void solve()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> total_price;
    int p;
    for (int i = 0; i < 9; i++)
    {
        cin >> p;
        total_price -= p;
    }
    cout << total_price;
}

int main()
{
    solve();

    return 0;
}