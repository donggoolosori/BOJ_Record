#include <iostream>
#include <queue>

using namespace std;
typedef long long int ll;

ll ans = -1;

void bfs(ll a, ll b)
{
    queue<pair<ll, ll>> q;
    q.push({a, 1});
    while (!q.empty())
    {
        ll cur_num = q.front().first;
        ll cur_op = q.front().second;
        q.pop();

        if (cur_num == b)
        {
            ans = cur_op;
            return;
        }
        ll op1 = cur_num * 2;
        ll op2 = 10 * cur_num + 1;

        if (op1 <= b)
            q.push({op1, cur_op + 1});
        if (op2 <= b)
            q.push({op2, cur_op + 1});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b;
    cin >> a >> b;

    bfs(a, b);
    cout << ans << '\n';

    return 0;
}