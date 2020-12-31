#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int coin[10];

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> coin[i];
}

int main()
{
    input();

    sort(coin, coin + n, greater<int>());

    int cnt = 0, cur = k;
    for (int i = 0; i < n; i++)
    {
        if (coin[i] > cur)
            continue;
        cnt += cur / coin[i];
        cur -= coin[i] * (cur / coin[i]);
    }

    cout << cnt << '\n';
    return 0;
}